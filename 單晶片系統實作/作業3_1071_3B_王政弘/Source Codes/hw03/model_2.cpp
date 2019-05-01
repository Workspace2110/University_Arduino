#include "model_2.h"

// Constructor:(input: pin of left, pin of center, pin of right)
Model_2::Model_2(int left, int center, int right) : left(left), center(center), right(right)
{
    // 設定為輸入接腳:
    pinMode(this->left, INPUT);
    pinMode(this->center, INPUT);
    pinMode(this->right, INPUT);
    // ===========================================
}
//--------------------------------------------

// Deconstructor:
Model_2::~Model_2()
{
}
//--------------------------------------------

// 主要驅動程式
void Model_2::runWork()
{
    LEFT   = digitalRead(this->left);     // 讀取紅外線感測器(左)
    CENTER = digitalRead(this->center);   // 讀取紅外線感測器(中)
    RIGHT  = digitalRead(this->right);    // 讀取紅外線感測器(右)

    updata();
}
//--------------------------------------------

// Get title string
char* Model_2::getTitle() const{
    return (char*)title;
}
//--------------------------------------------

// Get size of title
int Model_2::getTitle_size() const{
    return title_size;
}
//--------------------------------------------

// Get message string
char* Model_2::getMessage() const{
    return (char*)message;
}
//--------------------------------------------

// Get size of message
int Model_2::getMessage_size() const{
    return message_size;
}
//--------------------------------------------

// Updata all data
void Model_2::updata(){
    updataMessage();
    updataMessage_size();
}
//--------------------------------------------

// Updata message
void Model_2::updataMessage(){
    if ((LEFT || CENTER || RIGHT) == 0 || (LEFT && CENTER && RIGHT) == 1) // 不正常狀態
    {
        message = "Abnormal";
    }
    else if ((!LEFT && CENTER && !RIGHT) == 1)   // 位置正常狀態
    {
        message = "Normal";
    }
    else if ((!LEFT && !CENTER && RIGHT) == 1)  // 微偏右狀態
    {
        message = "Slightly Right";
    }
    else if ((!LEFT && CENTER && RIGHT) == 1)   // 偏右狀態
    {
        message = "Right";
    }
    else if ((LEFT && !CENTER && !RIGHT) == 1)  // 微偏左狀態
    {
        message = "Slightly Left";
    }
    else if ((LEFT && CENTER && !RIGHT) == 1)   // 偏左狀態
    {
        message = "Left";
    }
}
//--------------------------------------------

// Updata size of message  
void Model_2::updataMessage_size(){
    message_size = sizeof(message)/sizeof(message[0]); // Updata size of message
}
//--------------------------------------------
