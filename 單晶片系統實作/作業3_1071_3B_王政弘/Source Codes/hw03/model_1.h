/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    功能:
        可以利用搖桿控制兩個伺服馬達的轉動角度，並將兩個伺服馬達之角度顯示在LCD上。
*/

#ifndef MODEL_1_H
#define MODEL_1_H

// include libraries:
#include <Arduino.h>    // Ardruino base library
#include <Servo.h>      // Servo working library
//--------------------------------------------

class Model_1{
public:
    // Constructor: input(pin of bottom servo, pin of top servo, pin of horizontal joystick, pin of vertical joystick)
    Model_1(int servo_1, int servo_2, int joystick_H, int joystick_V);
    // ===========================================

    // Deconstructor:
    ~Model_1();
    // ===========================================

    // Functions:

    // 主要驅動程式
    void runWork();
    // - - - - - - - - - - - - - - - - - - - - - -

    // 讀取信號並調整位置值
    long mapping(int pin);
    // - - - - - - - - - - - - - - - - - - - - - -

    // Getting functions:
    char* getTitle() const;         // Get title string
    int getTitle_size() const;      // Get size of title

    char* getMessage() const;       // Get message string
    int getMessage_size() const;    // Get size of message
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
private:
    // Functions:
    void updata();              // Updata all Data
    void updataMessage();       // Updata message
    void updataMessage_size();  // Updata size of message
    // ===========================================

    // Data:
    // About LCD:
    static const char* const title = "Angle";         // title
    int title_size = sizeof(title)/sizeof(title[0]);  // title size

    const char* message = "X:%d Y:%d";                      // message
    int message_size = sizeof(message)/sizeof(message[0]);  // message size
    // - - - - - - - - - - - - - - - - - - - - - -

    // Servo motors:
    Servo* servo_1; // Bottom Servo Object
    Servo* servo_2; // Top Servo Object
    // - - - - - - - - - - - - - - - - - - - - - -

    // Joystick:
    int joystick_H = A0; // pin of joystick horizontal (Defualt: A0)
    int joystick_V = A1; // pin of joystick vertical (Defualt: A1)
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
protected:
};
#endif // MODEL_1_H
