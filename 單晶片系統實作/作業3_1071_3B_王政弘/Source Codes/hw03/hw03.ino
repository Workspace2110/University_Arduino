/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    題目： 伺服馬達、搖桿、紅外線感測器、超音波感測器、溫溼度感測器及LCD之整合應用
    接腳:
        DIP switch : 
            Model 1:  接微控板的 2 腳
            Model 2:  接微控板的 3 腳
            Model 3:  接微控板的 4 腳

        LCD(I2C匯流排) :
            SDA : 接微控板的 A4 腳
            SCL : 接微控板的 A5 腳
            
        Servomotors:
            Servomotor1 : 接微控板的 5 腳
            Servomotor2 : 接微控板的 6 腳

        Joystick : 
            Horizontal: 接微控板的 A0 腳
            Vertical:   接微控板的 A1 腳

        Infrared : 
            right:  接微控板的 11 腳
            center: 接微控板的 10 腳
            left:   接微控板的  9 腳

        Ultrasonic :
            trigger:    接微控板的 12 腳
            echo:       接微控板的 13 腳

        Temperature and humidity : 
            data:    接微控板的 A3 腳
    功能:
        (1)	模式1：
            可以利用搖桿控制兩個伺服馬達的轉動角度，並將兩個伺服馬達之角度顯示在LCD上。
            (例如：X: 56  Y:90)

        (2)	模式2：
            利用紅外線感測器感測路徑(貼上一條黑膠帶)，
            並在LCD上顯示微控板之位置狀態：
                位置正常(Position： Normal)、
                微偏右(Position： Slightly Right)、
                偏右(Position： Right)、
                微偏左(Position： Slightly Left)、
                偏左(Position： Left)、
                不正常(Position： Abnormal)

        (3)	模式3：
            可利用超音波感測器感測距離，並使用溫溼度感測器感測溫度與濕度，然後將感測到的距離及溫溼度顯示在LCD上。
            (例如:Distance: 30 cm  Temp:30 Humid:63)
*/

// Include libraries:
#include "model_1.h" // 模式1的函式庫
#include "model_2.h" // 模式2的函式庫
#include "model_3.h" // 模式3的函式庫
#include "My_LCD.h"  // LCD library
//--------------------------------------------

// Declare variables:

// Output pins:
// Servo motors:
int Servomotors1 = 5;
int Servomotors2 = 6;
// - - - - - - - - - - - - - - - - - - - - - -

// ===========================================

// Input pins:
// DIP switch:
const int DIP_1 = 2;
const int DIP_2 = 3;
const int DIP_3 = 4;
// - - - - - - - - - - - - - - - - - - - - - -

// Joystick:
const int Horizontal = A0;
const int Vertical   = A1;
// - - - - - - - - - - - - - - - - - - - - - -

// Infrared:
const int left      =  9;
const int center    = 10;
const int right     = 11;
// - - - - - - - - - - - - - - - - - - - - - -

// Temperature and humidity:
int data = A3;
// - - - - - - - - - - - - - - - - - - - - - -

// ===========================================

// Mixed pins:
// Ultrasonic:
const int trigger = 12;
const int echo    = 13;
// - - - - - - - - - - - - - - - - - - - - - -
// ===========================================

// Data:
const char* title     = ""; // title string
const char* message   = ""; // message string

Model_1* model_1;   // 模式1的物件
Model_2* model_2;   // 模式2的物件
Model_3* model_3;   // 模式3的物件
My_LCD* LCD;        // LCD object
// ===========================================

//--------------------------------------------

// Initializing
void setup(){
    model_1 = new Model_1(Servomotors1, Servomotors2, Horizontal, Vertical);
    model_2 = new Model_2(left, center, right);
    model_3 = new Model_3(trigger,echo, data);
    LCD = new My_LCD();
    Serial.begin(9600);
}
//--------------------------------------------

// main program
void loop(){
    if(!digitalRead(DIP_1)){          // Model 1
        model_1->runWork();
        title = model_1->getTitle();
        message = model_1->getMessage();
    }else if(!digitalRead(DIP_2)){    // Model 2
        model_2->runWork();
        title = model_2->getTitle();
        message = model_2->getMessage();
    }else if(!digitalRead(DIP_3)){    // Model 3
        model_3->runWork();
        title = model_3->getTitle();
        message = model_3->getMessage();
    }else{                           // Defualt model
        title   = "Defualt model";
        message = "Welcome";
    }

    LCD->set_words(title, message); // Display on LCD
    
    // For Debug:
    // Serial.println(title);
    // Serial.println(message);
    // ===========================================
}
//--------------------------------------------
