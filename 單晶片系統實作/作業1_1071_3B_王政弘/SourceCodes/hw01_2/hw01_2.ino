/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    題目： 課本實作題第3章第1題(利用電位計調整1w LED的光燈)
    接腳:
        VR7A (P7 horizontal) : 接微控板的 A0 腳
        1w LED (P8) : 接微控板的 3 腳
    功能:
        VR7A : 調整用之電位計
        序列埠監控視窗 : 顯示PWM 值(0-255)
*/

// Declare variables:
const int LED = 3;              // Declare pin of LED
const int POT = A0;             // Declare pin of VR7A
const unsigned int baud = 9600; // Declare baud rate
//--------------------------------------------

// Initializing system
void setup() {
    pinMode(POT, INPUT);    // Setup POT
    pinMode(LED, OUTPUT);   // Setup LED
    digitalWrite(LED, 0);   // Close LED
    Serial.begin(baud);     // Start the serial port and set the 9600 baud rate
}
//--------------------------------------------

// main function
void loop() {
    int value = analogRead(POT)/4;  // Read analog pin(1024/4 = 256)
    analogWrite(LED, 255-value);    // Output PWM signal to LED
    Serial.println(value);          // Print in the Serial Monitor Window
    //delay(5000);
}
//--------------------------------------------
