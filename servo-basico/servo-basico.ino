#include <ESP32Servo.h>

const int PinoServo = 5;



Servo servoMotor;
void setup() {

  servoMotor.attach(PinoServo);
}

void loop() {
  servoMotor.write(0);
  delay(1000);
  servoMotor.write(90);
  delay(1000);
  servoMotor.write(180);
  delay(500);
  servoMotor.write(90);
  delay(1000);
}
