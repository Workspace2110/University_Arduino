/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    題目： 數位時鐘(基本版)
    接腳:
        P11B(1~4)   : 分別接微控板的 2 、3 、4 、5 腳
        P11A(a~g)   : 分別接微控板的 6 、7 、8 、9 、10 、11 、12 腳
        P14         : 接微控板的 13 腳
        DD          : 接微控板的 A0 腳
        P5-1        : 接微控板的 A1 腳
        P6-5~P6-8   : 分別接微控板的 A2 、A3 、A4 、A5 腳
        P6-1        : 接GND(低態動作)
    功能:
        (1)具有調整時、分的功能
        (2)每隔5分鐘從蜂鳴器發出聲音
        (3)每小時發出一段簡短音樂報時
*/

// Include library(s):
#include "Clock.h" //My library : 處理時鐘運作作業(詳情請看header檔)
//--------------------------------------------

// Declare variables:

// Output pins:
const int scan[] = {2, 3, 4, 5};                // 宣告掃描信號接腳
const int SEG[] = {6, 7, 8, 9, 10, 11, 12};     // 宣告顯示信號接腳(g~a)
const int BZ = 13;                              // 宣告蜂鳴器接腳
const int DD = A0;                              // 宣告閃秒LED接腳(":")
// ===========================================

// Input pins
const int DIPSW[] = {A1};                       // 宣告指撥開關接腳
const int PB[] = {A2, A3, A4, A5};              // 宣告按鍵接腳
// ===========================================

// Data:
Clock* clock;   // 宣告時鐘物件
// ===========================================

//--------------------------------------------


// Initializing system
void setup(){
    clock = new Clock(SEG, scan, PB, 4, DIPSW, 1, BZ, DD);  //Instance clock
}
//--------------------------------------------

// Main function
void loop(){
    clock->runWork();// run clock
}
//--------------------------------------------
