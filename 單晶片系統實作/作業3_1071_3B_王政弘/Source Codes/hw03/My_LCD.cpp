#include "My_LCD.h"

// Constructor: default
My_LCD::My_LCD(){
    this->LCD = new LiquidCrystal_I2C(this->Address, this->column, this->row);    // Initialize LCD object
    LCD->begin();                // LCD初始化
    LCD->backlight();            // 開啟背光
    LCD->createChar(0, _left);   // 載入自建字型編碼陣列
    LCD->createChar(1, _right);  // 載入自建字型編碼陣列
}
//--------------------------------------------

// Constructor: input(rows, column)
My_LCD::My_LCD(int rows, int column):row(row), column(column){
    this->LCD = new LiquidCrystal_I2C(this->Address, this->column, this->row);    // Initialize LCD object
    LCD->begin();                // LCD初始化
    LCD->backlight();            // 開啟背光
    LCD->createChar(0, _left);   // 載入自建字型編碼陣列
    LCD->createChar(1, _right);  // 載入自建字型編碼陣列
}
//--------------------------------------------

// Deconstructor
My_LCD::~My_LCD(){

}
//--------------------------------------------

// setting display words
void My_LCD::set_words(char* title, char* message){
    LCD->setCursor(0, 0);   // 移至第0列的指標開始位置
    LCD->print(title);      // display title

    LCD->setCursor(0, 1);   // 移至第1列的指標開始位置
    LCD->print(message);    // display message

    delay(500);
    LCD->clear();
}
//--------------------------------------------

// setting display words
void My_LCD::set_words(char* title, int title_size, char* message, int message_size){

    LCD->setCursor(get_start_cursor(title_size), 0);    // 移至第0列的指標開始位置
    LCD->print(title);       // display title

    LCD->setCursor(get_start_cursor(message_size), 1);  // 移至第1列的指標開始位置
    LCD->print(message);     // display message

    //delay(500);
    LCD->clear();
}
//--------------------------------------------

// Getting start cursor of words(Alignment: center)
int My_LCD::get_start_cursor(int words_size){
    return ( (this->column - words_size)>0?(this->column - words_size):0 );
}
//--------------------------------------------
