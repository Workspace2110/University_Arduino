/*
Coded by Jheng-Hong Wang (2019)
E-mail : workspace2110@gmail.com
Description:
    Warning: this object only for 6-axisesm robot arm
*/

#ifndef ROBOTARM_H
#define ROBOTARM_H

#include <Arduino.h>
#include <Servo.h>
class RobotArm
{
  public:
    // Constructor
    RobotArm(const int *pins, int axisesm, const int *defaultDegrees);
    //--------------------------------------------

    // Deconstructor
    ~RobotArm();
    //--------------------------------------------

    // Robot arm static control
    void staticControl(const int *i_degrees, int axises);
    //--------------------------------------------

    // Robot arm dynamic test
    void dynamicTest();
    //--------------------------------------------

  private:
    // Functions:
    //--------------------------------------------

    // Data:

    int axises = 6;
    int pos = 0;
    bool flag = true;

    // create servo object to control a servo
    Servo myservo1, myservo2, myservo3, myservo4, myservo5, myservo6;
    const Servo m_servos[6] = {myservo1, myservo2, myservo3, myservo4, myservo5, myservo6};

    int m_defaultDegree[6];
    int bufferDegrees[6];
    //--------------------------------------------
};
#endif // ROBOTARM_H
