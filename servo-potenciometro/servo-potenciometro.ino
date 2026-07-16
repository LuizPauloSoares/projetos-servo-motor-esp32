#include <ESP32Servo.h>

const int Pinopot = 35;
const int PinoServo = 5;
int valorPot;


Servo servoMotor;
void setup() {

  // configura a resolução do ADC
  // 9 bits  = 0 a 511
  // 10 bits = 0 a 1023
  // 11 bits = 0 a 2047
  // 12 bits = 0 a 4095
  Serial.begin(115200);
  analogReadResolution(10);

  // a função .attach conecta o servo ao pino 
  servoMotor.attach(PinoServo);
}

void loop() {
  valorPot = analogRead(Pinopot);

  int angulo = map(valorPot, 0, 1023, 0, 180);
 
  servoMotor.write(angulo);

  Serial.print("potenciometro : ");
  Serial.print(valorPot);
  Serial.print(" -> angulo :");
  Serial.println(angulo);

  delay(20);
}
