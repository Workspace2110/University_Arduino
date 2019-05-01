/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    題目： 課本實作題第2章第1題(利用按鈕控制LED單燈左、右移一圈)
    接腳:
        PB0(P6-5) : 接微控板的 3 腳
        PB1(P6-6) : 接微控板的 4 腳
        P6-1      : 接GND(低態動作)
        4 個LED   : 分別接微控板的 8 、9 、10 、11 腳
    功能:
        PB0 : 單燈左移一圈
        PB1 : 單燈右移一圈
*/

// Define data:
    #define PB0 3 // Define turn Left Button
    #define PB1 4 // Define turn Right Button
//--------------------------------------------

// Declare variables:
    const int LEDs[] = {8, 9, 10, 11};                  // Declare pin of LEDs
    const int start = 1;                                // Declare index which is start of LEDs
    const int len = ( sizeof(LEDs)/sizeof(LEDs[0]) );   // Declare length of LEDs
//--------------------------------------------

// Forward declarations:
    void setup_all_LEDs(const int* leds/*leds : LEDs array*/); // Setup all LEDs
    void close_all_LEDs(const int* leds/*leds : LEDs array*/); // Close all LEDs
    void turn_to(bool which/*Ture : turn to rigth, False : turn to left*/); // Which side turn to and light up?
    void left(int& n/*n : index*/);  // Index to the left
    void right(int& n/*n : index*/); // Index to the right
//--------------------------------------------

// Initializing system
void setup(){
    pinMode(PB0, INPUT);    // Setup PB0
    pinMode(PB1, INPUT);    // Setup PB1
    setup_all_LEDs(LEDs);   // Setup all LEDs
    close_all_LEDs(LEDs);   // close all LEDs
}
//--------------------------------------------

// main function
void loop(){
    digitalWrite(LEDs[start], LOW); // Default state light up LED
    if( !digitalRead(PB0) ){        // When PB0 be click
        turn_to(false);             // turn to left and light up
    }else if( !digitalRead(PB1) ){  // When PB1 be click
        turn_to(true);              // turn to right and light up
    }
}
//--------------------------------------------

// Definitions of the others functions:

// Close all LEDs
void setup_all_LEDs(const int* leds/*leds : LEDs array*/){
    for (int i= 0; i < len; ++i){
        digitalWrite(leds[i], HIGH);
    }
}

// Setup all LEDs
void close_all_LEDs(const int* leds/*leds : LEDs array*/){
    for (int i= 0; i < len; ++i){
        pinMode(leds[i], OUTPUT);
    }
}

// Which side turn to and light up?
void turn_to(bool which/*Ture : rigth, False : left*/){
    int n = start;
    for(int i = 0; i < len; ++i){
        digitalWrite(LEDs[n], HIGH);    // Close the nth LED

        if( which ){
            right(n);   //Turn to right
        }else{
            left(n);    //Turn to left
        }

        digitalWrite(LEDs[n], LOW);     // Light up the nth LED
        delay(500);     //waitting 0.5s
    }
}

// Index to the left
void left(int& n/*n : index*/){
    if( n > 0 ){
        --n;
    }else{
        n = (len-1);
    }
}

// Index to the right
void right(int& n/*n : index*/){
    if( n < (len-1) ){
        ++n;
    }else{
        n = 0;
    }
}
//--------------------------------------------
