#include <ESP32Servo.h>

const int PinoServo = 5;
#define PINO_SOLO 34 
#define ledVerde 19
#define ledVermelho 18

Servo servoMotor;

int calcularUmidadeSoloPercentual(int leituraBruta){
  int umidade = map(leituraBruta, 4095, 1200, 0, 100);
  umidade = constrain(umidade, 0, 100);
  return umidade;
}
 
void setup() {
  Serial.begin(115200);
  servoMotor.attach(PinoServo);
  servoMotor.write(0);
  pinMode(PINO_SOLO, INPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
}

void loop() {
  int leituraSoloBruto = analogRead(PINO_SOLO);
  int umidadesolo = calcularUmidadeSoloPercentual(leituraSoloBruto);
  Serial.print("umidade do solo  ");
  Serial.println(umidadesolo);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH);


  if (umidadesolo < 30){
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);
    for (int ang = 0; ang <=180;ang++){
      servoMotor.write(ang);
      Serial.print("angulo ");
      Serial.println(ang);
      Serial.print("umidade ");
      Serial.println(umidadesolo);
      delay(10);

      if (umidadesolo >= 30) return;
    }

    for (int ang = 180; ang <=0;ang--){
      servoMotor.write(ang);
      Serial.print("angulo  volta  ");
      Serial.println(ang);
      Serial.print("umidade ");
      Serial.println(umidadesolo);
      delay(20);
    
    if (umidadesolo >= 30) return;
    
    }
  }
    else{
      servoMotor.write(0);
    }

  }

