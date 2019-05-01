#include "RobotArm.h"

// Constructor
RobotArm::RobotArm(const int *pins, int axises, const int *defaultDegrees) : axises(axises)
{
    Serial.begin(9600);
    //    m_servos = new Servo[this->axises];
    //    m_defaultDegree = new int[this->axises];

    for (int i = 0; i < this->axises; ++i)
    {
        // Attaches the servo on pin to the servo objects
        m_servos[i].attach(pins[i]);
        // ===========================================

        // Setting default degrees
        m_defaultDegree[i] = defaultDegrees[i];
        // ===========================================

        // Normalize Servos
        m_servos[i].write(m_defaultDegree[i]);
        // ===========================================
    }
}
//--------------------------------------------

// Deconstructor
RobotArm::~RobotArm()
{
}
//--------------------------------------------

// Robot arm static control
void RobotArm::staticControl(const int *i_degrees, int axises)
{
    int i = 0;
    for (i = 0; i < (this->axises - 1); ++i)
    {
        m_servos[i].write((i_degrees[i] <= 180 && i_degrees[i] >= 0) ? i_degrees[i] : m_defaultDegree[i]);
    }

    m_servos[i].write((i_degrees[i] <= 180 && i_degrees[i] >= 120) ? i_degrees[i] : m_defaultDegree[i]);
    delay(15); // waits 15ms for the servo to reach the position
}
//--------------------------------------------

// Robot arm dynamic control
void RobotArm::dynamicTest()
{
  bufferDegrees[0] = pos;
  staticControl(bufferDegrees, 6);
  if(flag){
    ++pos;
  }else{
    --pos;
  }
  delay(15);

  if(pos == 180 || pos == 0){
    flag = !flag;
  }
}
//--------------------------------------------
