/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    功能:
        利用超音波感測器感測距離，並使用溫溼度感測器感測溫度與濕度，然後將感測到的距離及溫溼度顯示在LCD上。
*/

#ifndef MODEL_3_H
#define MODEL_3_H

// Define data:
#define DHTTYPE DHT11
//--------------------------------------------

// include libraries:
#include <Arduino.h>      // Ardruino base library
#include <DHT.h>        // Temperature and humidity sensor library
//--------------------------------------------

class Model_3{
public:
    // Constructor:(input: pin of trigger, pin of echo, pin of data)
    Model_3(int trigger, int echo, int data);
    // ===========================================

    // Deconstructor:
    ~Model_3();
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
    void updataTitle();         // Updata title
    void updataTitle_size();    // Updata size of title
    void updataMessage();       // Updata message
    void updataMessage_size();  // Updata size of message
    void updataTempHumi();      // Updata temperature and humidity
    void updataDistance();      // Updata distance
    // ===========================================

    // Data:
    // About LCD:
    const char* title = "Distance:%d cm";             // title
    int title_size = sizeof(title)/sizeof(title[0]);  // title size

    const char* message = "Temp:%d Humid:%d";               // message
    int message_size = sizeof(message)/sizeof(message[0]);  // message size
    // - - - - - - - - - - - - - - - - - - - - - -

    // About temperature and humidity sensor:
    DHT* dht11; // temperature and humidity sensor object

    float temperature   = 0.0; // 存放濕度值的變數
    float humidity      = 0.0; // 存放攝氏溫度值的變數
    // - - - - - - - - - - - - - - - - - - - - - -

    // About ultrasonic sensor:
    const int samplePeriod = 50;	// 每50ms取樣一次(頻率為20Hz)
    const int T25=29;	            // 25度時之音速比例(1/0.0346)
    int distance = 0;
    int duration = 0;

    int trigger = 2; // pin of trigger  (defualt: 3)
    int echo    = 3; // pin of echo     (defualt: 2)
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
protected:
};
#endif // MODEL_3_H
