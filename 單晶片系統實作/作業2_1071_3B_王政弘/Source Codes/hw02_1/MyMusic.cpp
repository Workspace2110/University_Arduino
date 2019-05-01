#include "MyMusic.h"

// Constructor
MyMusic::MyMusic(){
    
}
//--------------------------------------------

// Deconstructor
MyMusic::~MyMusic(){

}
//--------------------------------------------

// 播放樂曲: 小星星
double MyMusic::LittleStar(int buzzer/*buzzer: pin of buzzer*/){

    int tempo = 300;
    double beat[] = {
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim
    }; 

    int tones[] = {
        Mid_C, Mid_C, Mid_G, Mid_G, Mid_A, Mid_A, Mid_G,  // Twinkle, twinkle, little star, 
        Mid_F, Mid_F, Mid_E, Mid_E, Mid_D, Mid_D, Mid_C,  // How I wonder what you are!
        Mid_G, Mid_G, Mid_F, Mid_F, Mid_E, Mid_E, Mid_D,  // Up above the world so high,
        Mid_G, Mid_G, Mid_F, Mid_F, Mid_E, Mid_E, Mid_D,  // Like a diamond in the sky.
        Mid_C, Mid_C, Mid_G, Mid_G, Mid_A, Mid_A, Mid_G,  // Twinkle, twinkle, little star,
        Mid_F, Mid_F, Mid_E, Mid_E, Mid_D, Mid_D, Mid_C   // How I wonder what you are!
    };

    // Play Music and return delay time
    return playMusic(buzzer, tones, sizeof(tones)/sizeof(tones[0]), beat, tempo);
}
//--------------------------------------------

// 播放樂曲: 小蜜蜂
double MyMusic::Bee(int buzzer/*buzzer: pin of buzzer*/){

    int tempo = 300;
    double beat[] = {
        Crotchet, Crotchet, Minim, Crotchet, Crotchet, Minim, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Minim, Crotchet, Crotchet, Minim, Crotchet, Crotchet, Crotchet, Crotchet, Semibreve,
        Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Crotchet, Minim,
        Crotchet, Crotchet, Minim, Crotchet, Crotchet, Minim, Crotchet, Crotchet, Crotchet, Crotchet, Semibreve
    };

    int tones[] = {
        Mid_G, Mid_E, Mid_E, Mid_F, Mid_D, Mid_D, Mid_C, Mid_D, Mid_E, Mid_F, Mid_G, Mid_G, Mid_G,
        Mid_G, Mid_E, Mid_E, Mid_F, Mid_D, Mid_D, Mid_C, Mid_E, Mid_G, Mid_G, Mid_E,
        Mid_D, Mid_D, Mid_D, Mid_D, Mid_D, Mid_E, Mid_F, Mid_E, Mid_E, Mid_E, Mid_E, Mid_E, Mid_F, Mid_G,
        Mid_G, Mid_E, Mid_E, Mid_F, Mid_D, Mid_D, Mid_C, Mid_E, Mid_G, Mid_G, Mid_C
    };

    // Play Music and return delay time
    return playMusic(buzzer, tones, sizeof(tones)/sizeof(tones[0]), beat, tempo);
}
//--------------------------------------------

// Play Music and get delay time
double MyMusic::playMusic(int buzzer, int* tones, int tones_size, double* beat, int tempo){
    double delay_time = 0; // fixed delay time

    for(int i=0; i<tones_size; ++i){

        if(tones[i] != 0){                                  // if the tone is not pause.
            tone(buzzer, tones[i], beat[i]*tempo);          // play one tone with one beat
        }

        delay_time += ( ((double)tempo) /1000 )*beat[i];    // Computing fix time

        delay(beat[i]*tempo);   // Waitting one beat
        noTone(buzzer);         // Close buzzer (Prevent afterimage)
    }

    return delay_time;          // return fix time
}
//--------------------------------------------