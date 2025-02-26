#define Temperatura A0
#define ledR 6
#define rojo 9
#define verde 10
#define azul 11
#define PULSADOR 7
#define buzzer 5
int ValorTemp, ValorMV, ValorSensor;
void setup() {
  Serial.begin(9600);
  pinMode(PULSADOR, INPUT);
}

void loop() {
  ValorSensor=analogRead(Temperatura);
  ValorMV = map(ValorSensor, 0, 1023,0,5000);
  ValorTemp = map(ValorMV, 0, 5000, 0, 100);
  Serial.println(ValorMV/10);
  if(ValorTemp >= 15 && ValorTemp < 25){
    analogWrite(verde, 255);
    analogWrite(rojo,0);
    analogWrite(azul, 0);
    analogWrite(buzzer, 0);
    delay(50);
  }
  else if(ValorTemp >=25 && ValorTemp <30){
    analogWrite(verde, 255);
    analogWrite(rojo,255);
    analogWrite(azul, 0);
    analogWrite(buzzer, 0);
    delay(50);
  }
  else if(ValorTemp > 30){
    analogWrite(verde, 0);
    analogWrite(rojo,255);
    digitalWrite(ledR, 1);
    analogWrite(azul, 0);
    analogWrite(buzzer, 255);
    delay(50);
  }
  else{
    analogWrite(verde, 0);
    analogWrite(rojo,0);
    analogWrite(azul, 255);
    analogWrite(buzzer, 0);
    delay(50);
  }

}