#include <ESP32Servo.h>

const int PinoServo = 5;
const int Ldr =35;


Servo servoMotor;
void setup() {
  Serial.begin(115200);
  servoMotor.attach(PinoServo);
  servoMotor.write(0);
}

void loop() {
  int leitura = analogRead(Ldr);
  Serial.println(leitura);

  if (leitura > 2250){

    for (int ang = 0; ang <=180;ang++){
      servoMotor.write(ang);
      Serial.println(ang);
      Serial.println(leitura);
      delay(20);

      if (analogRead(Ldr) <= 2250) return;
    }

    for (int ang = 180; ang <=0;ang--){
      servoMotor.write(ang);
      Serial.println(ang);
      Serial.println(leitura);
      delay(20);
    
    if (analogRead(Ldr) <= 2250) return;
    
    }
  }
    else{
      servoMotor.write(0);
    }

  }

