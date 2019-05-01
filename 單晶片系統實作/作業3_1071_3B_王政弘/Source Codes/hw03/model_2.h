/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    功能:
        利用紅外線感測器感測路徑(貼上一條黑膠帶)，並在LCD上顯示微控板之位置狀態：
            位置正常(Position： Normal)、
            微偏右(Position： Slightly Right)、
            偏右(Position： Right)、
            微偏左(Position： Slightly Left)、
            偏左(Position： Left)、
            不正常(Position： Abnormal)
        。
*/

#ifndef MODEL_2_H
#define MODEL_2_H

// include libraries:
#include <Arduino.h>    // Ardruino base library
//--------------------------------------------

class Model_2{
public:
    // Constructor:(input: pin of left, pin of center, pin of right)
    Model_2(int left, int center, int right);
    // ===========================================

    // Deconstructor:
    ~Model_2();
    // ===========================================

    // Functions:

    // 主要驅動程式
    void runWork();
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
    void updata();              // Updata all data
    void updataMessage();       // Updata message
    void updataMessage_size();  // Updata size of message
    // ===========================================

    // Data:
    // About LCD:
    static const char* const title = "Position";      // title
    int title_size = sizeof(title)/sizeof(title[0]);  // title size

    const char* message = "123";                            // message
    int message_size = sizeof(message)/sizeof(message[0]);  // message size
    // - - - - - - - - - - - - - - - - - - - - - -

    // Aoubt Infrared sensor:
    int left    = 2;    // 紅外線感測器(左)接腳  (Defualt: 2)
    int center  = 3;    // 紅外線感測器(中)接腳  (Defualt: 3)
    int right   = 4;    // 紅外線感測器(右)接腳  (Defualt: 4)

    int LEFT    = 0;    // 存放紅外線感測器(左)狀態
    int CENTER  = 0;    // 存放紅外線感測器(中)狀態
    int RIGHT   = 0;    // 存放紅外線感測器(右)狀態
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
protected:
};
#endif // MODEL_2_H
