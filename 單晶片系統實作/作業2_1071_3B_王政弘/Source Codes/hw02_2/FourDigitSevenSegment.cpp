#include"FourDigitSevenSegment.h"
using namespace std;

// Constructor: default
FourDigitSevenSegment::FourDigitSevenSegment(/* args */)
{
    SEG = new int[SEG_size];    // Instance SEG array
    scan = new int[scan_szie];  // Instance scan array

    // Make default scanner pins
    for(int i=0; i<get_scan_size(); ++i){
        scan[i] = i+2;
    }

    // Make default Individual Segments Illuminated pins
    for(int i=0; i<get_SEG_size(); ++i){
        SEG[i] = i+6;
    }

    // Setup pins:
    setupScan();
    setupSEG();
    // ===========================================
}
//--------------------------------------------

// Constructor: input(SEG pins(a~g) and scanner pins)
FourDigitSevenSegment::FourDigitSevenSegment(const int* SEG_pins, const int* scan_pins)
{
    SEG = new int[SEG_size];    // Instance SEG array
    scan = new int[scan_szie];  // Instance scan array

    // Setting pins:
    set_SEG_pins(SEG_pins);
    set_scan_pins(scan_pins);
    // ===========================================
}
//--------------------------------------------

// Constructor: input(SEG pins(a~g and dp) and scanner pins)
FourDigitSevenSegment::FourDigitSevenSegment(const int* SEG_pins, const int* scan_pins, int dp)
{
    SEG = new int[SEG_size];    // Instance SEG array
    scan = new int[scan_szie];  // Instance scan array

    // Setting pins:
    set_SEG_pins(SEG_pins);
    set_scan_pins(scan_pins);
    set_dp_pin(dp);
    // ===========================================
}
//--------------------------------------------

// Deconstructor
FourDigitSevenSegment::~FourDigitSevenSegment()
{
}
//--------------------------------------------

// Setting Individual Segments Illuminated pins(a~g)
void FourDigitSevenSegment::set_SEG_pins(const int* pins/*pins: SEG pins array(g~a)*/){
    for(int i=0; i<get_SEG_size(); ++i){
        SEG[i] = pins[i];
    }

    setupSEG();
}
//--------------------------------------------

// Setting Individual Segments Illuminated pins(a~g, and dp)
void FourDigitSevenSegment::set_SEG_pins(int g, int f, int e, int d, int c, int b, int a, int dp){
    SEG[0] = g;
    SEG[1] = f;
    SEG[2] = e;
    SEG[3] = d;
    SEG[4] = c;
    SEG[5] = b;
    SEG[6] = a;
    setupSEG();

    set_dp_pin(dp);
}
//--------------------------------------------

// Setting Scanner pins
void FourDigitSevenSegment::set_scan_pins(const int* pins/*scan_pins: scanner pins array*/){
    for(int i=0; i<get_scan_size(); ++i){
        scan[i] = pins[i];
    }

    setupScan();
}
//--------------------------------------------

// Setting Scanner pins
void FourDigitSevenSegment::set_scan_pins(int pin0, int pin1, int pin2, int pin3){
    scan[0] = pin0;
    scan[1] = pin1;
    scan[2] = pin2;
    scan[3] = pin3;

    setupScan();
}
//--------------------------------------------

// Setting Individual Segments Illuminated pins(dp)
void FourDigitSevenSegment::set_dp_pin(int dp/*dp: SEG pins array(dp)*/){
    this->dp = dp;
    setupDp();
}
//--------------------------------------------

// Getting length of SEG
int FourDigitSevenSegment::get_SEG_size(){
    return SEG_size;
}
//--------------------------------------------

// Getting length of scan
int FourDigitSevenSegment::get_scan_size(){
    return scan_szie;
}
//--------------------------------------------

// Scan x times and display numbers
void FourDigitSevenSegment::scanner(int x/*x: Scanning x times*/, int* disp/*disp: display numbers array*/){
    for(int i=0; i<x; ++i){             // Do x times
        for(int j=0; j<get_scan_size(); ++j){       
            if(disp[j]>9 || disp[j]<0){ // Prevent Error
                return;
            }

            closeAll();                 // Close all LED(Prevent afterimage)

            setNumber(disp[j]);         // Display numbers

            digitalWrite(scan[j], 0);   //Output Scanning signal
            delay(1);                   //delay 1ms
        }
    }
}
//--------------------------------------------

// Close all LED
void FourDigitSevenSegment::closeAll(){
    for(int k=0; k<get_scan_size(); ++k){
        digitalWrite(scan[k], 1);   // Close kth LED (低態動作)
    }
}
//--------------------------------------------

// Display numbers
void FourDigitSevenSegment::setNumber(int number){
    if(number>9 || number<0){   // Prevent Error
        return;
    }
    
    int DISP = SEG_code[number];    // Getting SEG code of number

    for(int k=0; k<get_SEG_size(); ++k){
        if(bitRead(DISP, k)){
            digitalWrite(SEG[k], 1);    // Close LED(a,b,c,...,g) which SEG code is HIGH(低態動作)
        }else{
            digitalWrite(SEG[k], 0);    // Open LED(a,b,c,...,g) which SEG code is LOW(低態動作)
        }
    }
}
//--------------------------------------------

// setup Individual Segments Illuminated pins(a~g)
void FourDigitSevenSegment::setupSEG(){
    for(int i=0; i<get_SEG_size(); ++i){
        pinMode(SEG[i], OUTPUT);
    }
}
//--------------------------------------------

// setup scanner pins
void FourDigitSevenSegment::setupScan(){
    for(int i=0; i<get_scan_size(); ++i){
        pinMode(scan[i], OUTPUT);
    }
}
//--------------------------------------------

// setup Individual Segments Illuminated pins(dp)
void FourDigitSevenSegment::setupDp(){
    pinMode(dp, OUTPUT);
}
//--------------------------------------------