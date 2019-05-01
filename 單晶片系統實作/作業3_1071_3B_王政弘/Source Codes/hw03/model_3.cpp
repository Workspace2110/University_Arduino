#include "model_3.h"

// Constructor:(input: pin of trigger, pin of echo, pin of data)
Model_3::Model_3(int trigger, int echo, int data): trigger(trigger), echo(echo){
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    dht11 = new DHT(data, DHTTYPE);
}
//--------------------------------------------

// Deconstructor
Model_3::~Model_3(){

}
//--------------------------------------------

// 主要驅動程式
void Model_3::runWork(){
    updata();
}
//--------------------------------------------

// Get title string
char* Model_3::getTitle() const{
    return (char*)title;
}
//--------------------------------------------

// Get size of title
int Model_3::getTitle_size() const{
    return title_size;
}
//--------------------------------------------

// Get message string
char* Model_3::getMessage() const{
    return (char*)message;
}
//--------------------------------------------

// Get size of message
int Model_3::getMessage_size() const{
    return message_size;
}
//--------------------------------------------

// Updata all data
void Model_3::updata(){
    updataDistance();
    updataTempHumi();
}
//--------------------------------------------

// Updata title
void Model_3::updataTitle(){
    sprintf((char*)title,"Distance:%i cm", distance);
    updataTitle_size();
}
//--------------------------------------------

// Updata size of title
void Model_3::updataTitle_size(){
    title_size = sizeof(title)/sizeof(title[0]);
}
//--------------------------------------------

// Updata message
void Model_3::updataMessage(){
    sprintf((char*)message,"Temp:%i Humid:%i", (int)this->temperature, (int)this->humidity);
    updataMessage_size();
}
//--------------------------------------------

// Updata size of message
void Model_3::updataMessage_size(){
    message_size = sizeof(message)/sizeof(message[0]);
}
//--------------------------------------------

// Updata temperature and humidity
void Model_3::updataTempHumi(){
    // 若讀取dht11無誤，則執行下列動作
    this->temperature   = dht11->readTemperature(); // Read temperature as Celsius
    this->humidity      = dht11->readHumidity();    // Read humidity
    updataMessage();
}
//--------------------------------------------

// Updata distance
void Model_3::updataDistance(){
    digitalWrite(trigger, HIGH); 		    // 持續送出超音波
    delayMicroseconds(10);		          // 等待10微秒
    digitalWrite(trigger, LOW); 		    // 停止送出超音波
    duration = pulseIn(echo, HIGH)/2;	  // 單趟時間
    distance = duration/T25;	          // 距離
    updataTitle();
}
//--------------------------------------------
