
#include <Servo.h>

// create servo object to control a servo
Servo myservo1, myservo2, myservo3, myservo4, myservo5, myservo6;

bool flag = true;
int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
}

void loop() {
  if(flag){
    ++pos;
  }else{
    --pos;
  }
  myservo1.write(pos);   // 0~180    defualt:  90
  myservo2.write(20);   // 0~50     defualt:  20
  myservo3.write(20);   // 0~30     defualt:  20
  myservo4.write(150);  // 75~180   defualt:  150
  myservo5.write(90);   // 0~180    defualt:  90
  myservo6.write(180);  // 120~180  defualt:  180
  delay(15);

  if(pos == 180 || pos == 0){
    flag = !flag;
  }
}
