/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    處理四段七節顯示器顯示及接腳作業
*/
#ifndef FOURDIGITSEVENSEGMENT_H
#define FOURDIGITSEVENSEGMENT_H

// include librarys:
#include "Arduino.h"    //Ardruino base library
//--------------------------------------------
using namespace std;

class FourDigitSevenSegment
{
public:
    // Constructors:

    // Constructor: default
    FourDigitSevenSegment(/* args */);

    // Constructor: input(SEG pins(a~g) and scanner pins)
    FourDigitSevenSegment(const int* SEG_pins, const int* scan_pins);

    // Constructor: input(SEG pins(a~g and dp) and scanner pins)
    FourDigitSevenSegment(const int* SEG_pins, const int* scan_pins, int dp);
    // ===========================================

    // Deconstructor:
    ~FourDigitSevenSegment();
    // ===========================================
    
    // Functions:

    // Setting Functions:

    // Setting Individual Segments Illuminated pins(a~g)
    void set_SEG_pins(const int* pins/*pins: SEG pins array(g~a)*/);
    
    // Setting Individual Segments Illuminated pins(a~g, and dp)
    void set_SEG_pins(int g, int f, int e, int d, int c, int b, int a, int dp);

    // Setting Scanner pins
    void set_scan_pins(const int* pins/*scan_pins: scanner pins array*/);

    // Setting Scanner pins
    void set_scan_pins(int pin0, int pin1, int pin2, int pin3);

    // Setting Individual Segments Illuminated pins(dp)
    void set_dp_pin(int dp/*dp: SEG pins array(dp)*/);
    // - - - - - - - - - - - - - - - - - - - - - -

    // Getting Functions:

    // Getting length of SEG
    int get_SEG_size();

    // Getting length of scan
    int get_scan_size();
    // - - - - - - - - - - - - - - - - - - - - - -

    // The Others Functions:

    // Scan x times and display numbers
    void scanner(int x/*x: Scanning x times*/, int* disp/*disp: display numbers array*/);

    // Close all LED
    void closeAll();
    // ===========================================
private:
    //Functions:

    // Display numbers
    void setNumber(int number);

    // setup Individual Segments Illuminated pins(a~g)
    void setupSEG();

    // setup scanner pins
    void setupScan();

    // setup Individual Segments Illuminated pins(dp)
    void setupDp();
    // ===========================================

    // Pins:
    int* SEG;       // 宣告顯示信號接腳陣列(a~g)
    int dp;         // 宣告顯示信號接腳(dp)
    int* scan;      // 宣告掃描信號接腳陣列(scanner)
    // ===========================================

    // Data:
    const int SEG_size = 7;         // length of SEG
    const int scan_szie = 4;        // length of scan

    const int SEG_code[10] = {      // 宣告七節顯示碼陣列
  		0xc0,0xf9,0xa4,0xb0,0x99,   // 0~4 
  		0x92,0x82,0xf8,0x80,0x90    // 5~9
    };
    // ===========================================
protected:
};

#endif // !FOURDIGITSEVENSEGMENT_H
