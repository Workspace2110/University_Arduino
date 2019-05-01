#include "Clock.h"
using namespace std;

// Constructor: input(SEG pins(a~g), scanner pins, PB pins, DIPSW pins, and buzzer pin)
Clock::Clock(const int* SEG, const int* scan, const int* PB, int PB_length, const int* DIPSW, int DIPSW_length, const int buzzer, const int DD){
    FDSS = new FourDigitSevenSegment(SEG, scan);    //Instance FDSS

    this->PB = new int[ PB_length ];        // Instance PB array
    this->DIPSW = new int[ DIPSW_length ];  // Instance DIPSW array

    // Setting pins:
    set_PB_pins(PB, PB_length );
    set_DIPSW_pins(DIPSW, DIPSW_length );
    set_Buzzer_pin(buzzer);
    set_DD_pin(DD);
    // ===========================================
}
//--------------------------------------------

// Deconstructor
Clock::~Clock(){

}
//--------------------------------------------

// Setting DIP switch pins
void Clock::set_DIPSW_pins(const int* pins, int length){
    for(int i=0; i<length; ++i){
        DIPSW[i] = pins[i];
    }

    setupDIPSW();
}
//--------------------------------------------

// Setting PB pins
void Clock::set_PB_pins(const int* pins, int length){
    for(int i=0; i<length; ++i){
        PB[i] = pins[i];
    }

    setupPB();
}
//--------------------------------------------

// Setting Buzzer pins
void Clock::set_Buzzer_pin(const int pin){
    BZ = pin;

    setupBuzzer();
}
//--------------------------------------------

// Setting DD pins
void Clock::set_DD_pin(const int pin){
    DD = pin;

    setupDD();
}
//--------------------------------------------

// 調整模式
void Clock::adjustment(){
    while(phase0==1){
        seconds = 0;                // 秒數歸零
        digitalWrite(DD, false);    // 閃秒固定亮著

        // 時遞增調整(按鍵為低態動作)
        if(!digitalRead(PB[0])){    // 若PB[0]被按下(時遞增)
            add_hour(disp);
        }

        // 分遞增調整(按鍵為低態動作)
        if(!digitalRead(PB[1])){    // 若PB[1]被按下(分遞增)
            add_minute(disp);
        }

        FDSS->scanner(25, disp);    // 連續掃描25週(100ms，每秒約10次)

        DIP_swtich();   // 讀取指撥開關
    }
}
//--------------------------------------------

// 鬧鐘調整模式
void Clock::adjustment_alarm(){
   while(phase0==2){
        seconds = 0;                // 秒數歸零
        digitalWrite(DD, false);    // 閃秒固定亮著
            
        // 時遞增調整(按鍵為低態動作)
        if(!digitalRead(PB[0])){    // 若PB[0]被按下(時遞增)
            add_hour(goal);
        }

        // 分遞增調整(按鍵為低態動作)
        if(!digitalRead(PB[1])){    // 若PB[1]被按下(分遞增)
            add_minute(goal);
        }

        FDSS->scanner(25, goal);    // 連續掃描25週(100ms，每秒約10次)
        FDSS->closeAll();           // Close all LED(Prevent afterimage)

        DIP_swtich();   // 讀取指撥開關
   }
}
//--------------------------------------------

// 計時模式
void Clock::timing(){
    int index = 0;              // index of tones
    boolean activity = false;   // flag (Can it be an alarm?)

    while(phase0==0){
      if(!activity){
        FDSS->scanner(2, disp); // 連續掃描2週(8ms)
      }else{
        FDSS->closeAll();       // 關閉鬧鐘顯示
      }
      
        x1 = millis();          // 查詢時間
        x2=x1-x0;               // 計算時間差

        if(x2>=500){    // 0.5秒時間差
            x0=x1;      // 記錄時間

            // 切換閃秒:
            sec=!sec;
            digitalWrite(DD, sec);
            // - - - - - - - - - - - - - - - - - - - - - -

            // 處理時間
            if(sec){
                if(++seconds>=60){      // 秒數加1
                    seconds-=60;        // 若秒數滿60則歸零
                    if(disp[0]==9){     // 若分之個位數滿9
                        disp[0]=0;      // 則分之個位數歸零

                        if(disp[1]==5){ // 若分之十位數滿5
                            disp[1]=0;  // 則分之十位數歸零

                            add_hour(disp);     // Add one hour
                        }else{
                            ++disp[1];  //否則分之十位數加1
                        }

                    }else{
                        ++disp[0];      //否則分之個位數加1
                    }
                }
            }

        }
        isAlarm();
        
        if(alarm){  // It is alarm

            // Check time
            if(disp[0]==goal[0] && disp[1]==goal[1] && disp[2]==goal[2] && disp[3]==goal[3]){
                activity = true;
            }

            
            if(activity){                   // If time to ,play one beat of music 

                FDSS->closeAll();           // Close all LED(Prevent afterimage)

                if(index >= tones_size){    // Checking if index is over range
                    index = 0;              // if index is over range, make index to 0
                }

                if(tones[index] != 0){                              // if the tone is not pause.
                    tone(BZ, tones[index], beat[index]*tempo);      // play one tone with one beat
                }

                seconds += ( ((double)tempo) /1000 )*beat[index];   // Computing fix time

                delay(beat[index]*tempo);   // Waitting one beat
                noTone(BZ);                 // Close buzzer (Prevent afterimage)
                ++index;                    // Moving index to next one
            }

        }else{                              // If it is not alarm, it will not play music
            activity = false;
        }

        DIP_swtich();   // 讀取指撥開關
    }
}
//--------------------------------------------

// 讀取指撥開關
void Clock::DIP_swtich(){
    if(digitalRead(DIPSW[1])){          // 讀取指撥開關(DIPSW[1]) ： 鬧鐘調整模式
        phase0 = 2;
    }else if(digitalRead(DIPSW[0])){    // 讀取指撥開關(DIPSW[0]) ： 調整模式
        phase0 = 1;
    }else{                              // 讀取指撥開關(DIPSW[0]) ： 計時模式
        phase0 = 0;
    }
}
//--------------------------------------------

// 讀取鬧鐘模式是否開啟
void Clock::isAlarm(){
    if(digitalRead(DIPSW[2])){  // It is alarm.
        alarm = true;
    }else{                      // It is not alarm.
        alarm = false;
    }
}
//--------------------------------------------

// Run
void Clock::runWork(){
    DIP_swtich();           // 讀取指撥開關
    adjustment_alarm();     // 鬧鐘調整模式
    adjustment();           // 調整模式
    timing();               // 計時模式
}
// - - - - - - - - - - - - - - - - - - - - - -

// Add one hour
void Clock::add_hour(int* m_time/*m_time: time array*/){
    if(m_time[3]==2 && m_time[2]==3){   // 若已23時
        m_time[3]=0;                    // 時之十位數歸零
        m_time[2]=0;                    // 時之個位數歸零
    }else if(m_time[2]==9){             // 若時之個位數等於9
        m_time[2]=0;                    // 時之個位數歸零
        ++m_time[3];                    // 時之十位數遞增(進位)
    }else{
        ++m_time[2];                    // 否則時之個位數遞增
    }
}
//--------------------------------------------

// Subtract one hour
void Clock::subtract_hour(int* m_time/*m_time: time array*/){
    if(m_time[3]==0 && m_time[2]==0){   // 若已00時
        m_time[3]=2;                    // 時之十位數調整為2
        m_time[2]=3;                    // 時之個位數調整為3
    }else if(m_time[2]==0){             // 若時之個位數等於0
        m_time[2]=9;                    // 時之個位調整為9
        --m_time[3];                    // 時之十位數遞減(借位)
    }else{
        --m_time[2];                    // 否則時之個位數遞減
    }
}
//--------------------------------------------

// Add one minute
void Clock::add_minute(int* m_time/*m_time: time array*/){
    if(m_time[1]==5 && m_time[0]==9){   // 若已59分
        m_time[1]=0;                    // 分之十位數歸零
        m_time[0]=0;                    // 分之個位數歸零
    }else if(m_time[0]==9){             // 若分之個位數等於9
        m_time[0]=0;                    // 分之個位數歸零
        ++m_time[1];                    // 分之十位數遞增(進位)
    }else{
        ++m_time[0];                    // 否則分之個位數遞增
    }
}
//--------------------------------------------

// Subtract one minute
void Clock::subtract_minute(int* m_time/*m_time: time array*/){
    if(m_time[1]==0 && m_time[0]==0){   // 若已00分
        m_time[1]=5;                    // 分之十位數調整為5
        m_time[0]=9;                    // 分之個位數調整為9
    }else if(m_time[0]==0){             // 若分之個位數等於0
        m_time[0]=9;                    // 分之個位調整為9
        --m_time[1];                    // 分之十位數遞減(借位)
    }else{
        --m_time[0];                    // 否則分之個位數遞減
    }
}
//--------------------------------------------

// beep beep counts times
double Clock::beep(int pin, int counts){
    double delayTime = 0;
    for(int i=0; i<counts; ++i){    // 執行counts次
        tone(pin, 1000, 100);       // 發聲(1kHz,0.1秒)
        delay(100);                 // 靜音(0.1秒)
        delayTime += 0.2;           // Computing fix time
    }

    return delayTime;               // return fix time
}
//--------------------------------------------

// Setup all PB
void Clock::setupPB(){
    for(int i=0; i<(sizeof(PB)/sizeof(PB[0])); ++i){
        pinMode(PB[i], INPUT);
    }
}
//--------------------------------------------

// Setup all dip switch
void Clock::setupDIPSW(){
    for(int i=0; i<(sizeof(DIPSW)/DIPSW[0]); ++i){
        pinMode(DIPSW[i], INPUT);
    }
}
//--------------------------------------------

// Setup buzzer
void Clock::setupBuzzer(){
    pinMode(BZ, OUTPUT);
}
//--------------------------------------------

// Setup DD
void Clock::setupDD(){
    pinMode(DD, OUTPUT);
}
//--------------------------------------------