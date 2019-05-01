/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    處理時鐘的運行及邏輯
*/
#ifndef CLOCK_H
#define CLOCK_H

// include librarys:
#include "Arduino.h"                // Ardruino base library
#include "FourDigitSevenSegment.h"  // My Library : 處理四段七節顯示器的部分作業(詳情請看header檔)
//--------------------------------------------
using namespace std;

class Clock{
public:
    // Constructor: input(SEG pins(a~g), scanner pins, PB pins, DIPSW pins, and buzzer pin)
    Clock(const int* SEG, const int* scan, const int* PB, int PB_length, const int* DIPSW, int DIPSW_length, const int buzzer, const int DD);
    // ===========================================

    // Deconstructor
    ~Clock();
    // ===========================================

    // Functions:

    // Setting Functions:

    // Setting DIP switch pins
    void set_DIPSW_pins(const int* pins, int length);

    // Setting PB pins
    void set_PB_pins(const int* pins, int length);

    // Setting Buzzer pins
    void set_Buzzer_pin(const int pin);

    // Setting DD pins
    void set_DD_pin(const int pin);
    // - - - - - - - - - - - - - - - - - - - - - -

    // Clock work Functions:

    // 調整模式
    void adjustment();

    // 鬧鐘調整模式
    void adjustment_alarm();

    // 計時模式
    void timing();
    // - - - - - - - - - - - - - - - - - - - - - -

    // The others functions:

    // beep beep counts times
    double beep(int pin, int counts);

    // 讀取指撥開關
    void DIP_swtich();
    // - - - - - - - - - - - - - - - - - - - - - -

    // 讀取鬧鐘模式是否開啟
    void isAlarm();
    // - - - - - - - - - - - - - - - - - - - - - -
    
    // Run
    void runWork();
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
private:
    // Functions:

    // Time work Functions:

    // Add one hour
    void add_hour(int* m_time/*m_time: time array*/);

    // Subtract one hour
    void subtract_hour(int* m_time/*m_time: time array*/);

    // Add one minute
    void add_minute(int* m_time/*m_time: time array*/);

    // Subtract one minute
    void subtract_minute(int* m_time/*m_time: time array*/);
    // - - - - - - - - - - - - - - - - - - - - - -

    // Setup functions:

    // Setup all PB
    void setupPB();

    // Setup all dip switch
    void setupDIPSW();

    // Setup buzzer
    void setupBuzzer();

    // Setup DD
    void setupDD();
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================

    // Pins:
    int BZ;     // 宣告蜂鳴器接腳
    int DD;     // 閃秒LED接腳(":")
    int* PB;    // 按鍵接腳
    int* DIPSW; // 指撥開關接腳
    // ===========================================

    // Base data:
    FourDigitSevenSegment* FDSS;    // 四段七節顯示器處理物件
    int disp[4] = {0, 0, 0, 0};     // 顯示緩衝區陣列(buffer)
    int goal[4] = {0, 0, 6, 0};     // 鬧鈴目標時間，預設06:00
    unsigned long long x0,x1,x2;    // 時間變數
    int phase0 = 2;                 // 工作旗標(flag)：phase0=0計時模式, phase0=1調整模式, phase0=2鬧鐘調整模式
    boolean alarm = true;           // 工作旗標(flag)：alarm=false鬧鐘模式開(ON), alarm=true鬧鐘模式關(OFF)
    double seconds=0;               // 秒變數
    bool sec = false;               // 閃秒LED旗標(flag)
    // ===========================================

    // Data of music:
    // beat
    double beat[49] = {
        1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,
        1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4,
        1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2,
        1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4
    };
    // - - - - - - - - - - - - - - - - - - - - - -

    // tones
    int tones[49] = {
        784, 659, 659, 698, 587, 587, 523, 587, 659, 698, 784, 784, 784,
        784, 659, 659, 698, 587, 587, 523, 659, 784, 784, 659,
        587, 587, 587, 587, 587, 659, 698, 659, 659, 659, 659, 659, 698, 784,
        784, 659, 659, 698, 587, 587, 523, 659, 784, 784, 523
    };
    // - - - - - - - - - - - - - - - - - - - - - -

    // tempo
    int tempo = 300;
    // - - - - - - - - - - - - - - - - - - - - - -

    // size of tones
    int tones_size = sizeof(tones)/sizeof(tones[0]);
    // - - - - - - - - - - - - - - - - - - - - - -
    // ===========================================
protected:
};
#endif // !CLOCK_H