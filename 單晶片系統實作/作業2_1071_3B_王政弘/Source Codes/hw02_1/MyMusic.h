/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    處理樂曲的播放及其編曲
*/

#ifndef MYMUSIC_H
#define MYMUSIC_H

// Include librarys:
#include "Arduino.h"                // Ardruino base library
//--------------------------------------------
using namespace std;

class MyMusic{
public:
    // Constructor:
    MyMusic();
    // ===========================================

    // Deconstructor:
    ~MyMusic();
    // ===========================================

    // Funcrions:

    // 播放樂曲: 小星星
    double LittleStar(int buzzer/*buzzer: pin of buzzer*/);

    // 播放樂曲: 小蜜蜂
    double Bee(int buzzer/*buzzer: pin of buzzer*/);
    // ===========================================
private:
    // Functions:
    // Play Music and get delay time
    double playMusic(int buzzer/*buzzer: pin of buzzer*/, int* tones/*tones: tones array*/, int tones_size/*tones_size: size of tones array*/, double* beat/*beat: beat array*/, int tempo/*tempo: tempo*/);
    // ===========================================

    // Data:
    // tones:
    const int pause        = 0;         // 休止符
    // 低音
    const int Low_C        = 262;       // C(Do)
    const int Low_C_sharp  = 277;       // C#
    const int Low_D        = 294;       // D(Re)
    const int Low_D_sharp  = 311;       // D#
    const int Low_E        = 330;       // E(Mi)
    const int Low_F        = 349;       // F(Fa)
    const int Low_F_sharp  = 370;       // F#
    const int Low_G        = 392;       // G(So)
    const int Low_G_sharp  = 415;       // G#
    const int Low_A        = 440;       // A(La)
    const int Low_A_sharp  = 466;       // A#
    const int Low_B        = 494;       // B(Si)
    // 中音
    const int Mid_C        = 523;       // C(Do)
    const int Mid_C_sharp  = 554;       // C#
    const int Mid_D        = 587;       // D(Re)
    const int Mid_D_sharp  = 622;       // D#
    const int Mid_E        = 659;       // E(Mi)
    const int Mid_F        = 698;       // F(Fa)
    const int Mid_F_sharp  = 740;       // F#
    const int Mid_G        = 784;       // G(So)
    const int Mid_G_sharp  = 831;       // G#
    const int Mid_A        = 880;       // A(La)
    const int Mid_A_sharp  = 932;       // A#
    const int Mid_B        = 988;       // B(Si)
    // 高音
    const int High_C       =  1046;     // C(Do)
    const int High_C_sharp =  1109;     // C#
    const int High_D       =  1175;     // D(Re)
    const int High_D_sharp =  1245;     // D#
    const int High_E       =  1318;     // E(Mi)
    const int High_F       =  1397;     // F(Fa)
    const int High_F_sharp =  1480;     // F#
    const int High_G       =  1568;     // G(So)
    const int High_G_sharp =  1661;     // G#
    const int High_A       =  1760;     // A(La)
    const int High_A_sharp =  1865;     // A#
    const int High_B       =  1976;     // B(Si)
    // - - - - - - - - - - - - - - - - - - - - - -

    // beat:
    const double Quasihemidemisemiquaver    = 0.03125;  // 一百二十八分音符(美式英文: Hundred twenty-eighth note)
    const double Hemidemisemiquaver         = 0.0625;   // 六十四分音符(美式英文: Sixty-fourth note)
    const double Demisemiquaver             = 0.1818;   // 二十二分音符(美式英文: Thirty-second note)
    const double Semiquaver                 = 0.25;     // 十六分音符(美式英文: Sixteenth note)
    const double Quaver                     = 0.5;      // 八分音符(美式英文: Eighth note)
    const double Crotchet                   = 1;        // 四分音符(美式英文: Quarter note)
    const double Minim                      = 2;        // 二分音符(美式英文: Half note)
    const double Semibreve                  = 4;        // 全音符(美式英文: Whole note)
    // - - - - - - - - - - - - - - - - - - - - - -
    // ===========================================
protected:
};
#endif // !MYMUSIC_H