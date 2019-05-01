/*
Coded by Jheng-Hong Wang (2018)
E-mail : workspace2110@gmail.com
Description:
    題目： 機械手臂實作
    功能:
        實作一可超做的機械手臂
*/

#include "RobotArm.h"

// Declare variables:

// Pins of servos:
int servos[6] = {2, 3, 4, 5, 6, 7};
// ===========================================

// Pins of buttons:
int test_switch = A0; // pin of test button
// ===========================================

const int defaultDegrees[6] = {90, 20, 20, 150, 90, 180}; // Robot arm defualt degrees
int bufferDegrees[6] = {90, 20, 20, 150, 90, 180};        // Robot arm degrees buffer
RobotArm *robotArm;                                       // Robot arm object
//--------------------------------------------

// Forward declarations:
long mapping(int pin);
void controller();
void display_A();
//--------------------------------------------

void setup()
{
  robotArm = new RobotArm(servos, 6, defaultDegrees);
  Serial.begin(9600); // for debug

  // setting pins:
  for (int i = 0; i < 6; ++i)
  {
    pinMode(servos[i], OUTPUT);
  }
  pinMode(test_switch, INPUT);
  // ===========================================
}

void loop()
{
  if (analogRead(test_switch))
  {
    robotArm->staticControl(defaultDegrees, 6);
    Serial.println("A");
  }
  else
  {
    robotArm->dynamicTest();
    Serial.println("B");
  }
}
