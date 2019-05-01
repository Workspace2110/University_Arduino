/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    功能:
        處理時鐘的運行及邏輯
    接腳:
        LCD(I2C匯流排):
            SDA : A4
            SCL : A5
*/

#ifndef MY_LCD_H
#define MY_LCD_H

// include libraries:
#include <Arduino.h>            // Ardruino base library
#include <Wire.h> 			    // Wire.h
#include "LiquidCrystal_I2C.h" 	// Liquid Crystal(I2C) library
//--------------------------------------------

class My_LCD{
public:
    // Constructors:

    // Constructor: default
    My_LCD(/* args */);

    // Constructor: input(rows, column)
    My_LCD(int rows, int column);
    // ===========================================

    // Deconstructor
    ~My_LCD();
    // ===========================================

    // Functions:

    // Setting Functions:

    // Setting display words
    void set_words(char* title, char* message);
    void set_words(char* title, int title_size, char* message, int message_size);
    // - - - - - - - - - - - - - - - - - - - - - -

    // Getting Functions:

    // Getting start cursor of words(Alignment: center)
    int get_start_cursor(int words_size);
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
private:
    // Data:
    LiquidCrystal_I2C* LCD;     // LiquidCrystal Object
    const int Address = 0x27;   // I2C address
    int row = 2;                // How many rows (defualt: 2)
    int column = 16;            // How may column in one row (defualt: 16)

    // 自建字型編碼:
    byte _left[8] = {
        0b00010,
        0b00110,
        0b00110,
        0b01110,
        0b01110,
        0b11110,
        0b11110,
        0b00000
    };

    byte _right[8] = {
        0b01000,
        0b01100,
        0b01100,
        0b01110,
        0b01110,
        0b01111,
        0b01111,
        0b00000
    };
    // - - - - - - - - - - - - - - - - - - - - - -

    // ===========================================
protected:
};
#endif // MY_LCD_H
