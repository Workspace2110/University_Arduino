#include "model_1.h"

// Constructor: input(pin of bottom servo, pin of top servo, pin of horizontal joystick, pin of vertical joystick)
Model_1::Model_1(int servo_1, int servo_2, int joystick_H, int joystick_V):joystick_H(joystick_H), joystick_V(joystick_V){
    // Initializing Servo Object:
    this->servo_1 = new Servo();
    this->servo_2 = new Servo();
    this->servo_1->attach(servo_1);
    this->servo_2->attach(servo_2);
    // ===========================================

    // setting out pins:
    pinMode(this->joystick_H, INPUT);
    pinMode(this->joystick_V, INPUT);
    // ===========================================
}
//--------------------------------------------

// Deconstructor
Model_1::~Model_1(){

}
//--------------------------------------------

// 主要驅動程式
void Model_1::runWork(){
    servo_1->write( mapping(this->joystick_H) ); // 驅動水平伺服機
    servo_2->write( mapping(this->joystick_V) ); // 驅動垂直伺服機

     updata();
}
//--------------------------------------------

// 讀取信號並調整位置值
long Model_1::mapping(int pin){
    return map(analogRead(pin), 0, 1023, 179, 0);
}
//--------------------------------------------

// Get title string
char* Model_1::getTitle() const{
    return (char*)title;
}
//--------------------------------------------

// Get size of title
int Model_1::getTitle_size() const{
    return title_size;
}
//--------------------------------------------

// Get message string
char* Model_1::getMessage() const{
    return (char*)message;
}
//--------------------------------------------

// Get size of message
int Model_1::getMessage_size() const{
    return message_size;
}
//--------------------------------------------

// Updata all Data
void Model_1::updata(){
    updataMessage();
    updataMessage_size();
}
//--------------------------------------------

// Updata message
void Model_1::updataMessage(){
    // Updata message
    sprintf((char*)message,"X:%i Y:%i", (int)mapping(this->joystick_H), (int)mapping(this->joystick_V));
}
//--------------------------------------------

// Updata size of message
void Model_1::updataMessage_size(){
    message_size = sizeof(message)/sizeof(message[0]); // Updata size of message
}
//--------------------------------------------
