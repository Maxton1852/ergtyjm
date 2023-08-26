#include <QTRSensors.h>

#include <QTRSensors.h>
#define A1A 7
#define A1B 8

#define PWMA 6


#define B1A 4
#define B1B 9

#define PWMB 5

#define NUM_SENSORS 6
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN   11
#define BOTON 12
QTRSensorsAnalog qtra((unsigned char []){5,4,3,2,1,0},NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);

unsigned int sensorValues [NUM_SENSORS];

void setup() {
  Serial.begin(9600);
  pinMode (A1A, OUTPUT);
  pinMode (A1B, OUTPUT);
  pinMode (B1A, OUTPUT);
  pinMode (B1B, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(PWMA, OUTPUT);
  
  for (int i=0;i<400;i++){
    qtra.calibrate();
  }
  while (true){
if (digitalRead(BOTON)==1){
  
  break;
  
}
}
}


void loop() {
 /* qtra.read (sensorValues);
  for(int i = 12; i>=10; i--)
  for (unsigned char i= 0; i < NUM_SENSORS; i++){
    Serial.print(sensorValues[1]);
    Serial.print('\t');
  } 
 Serial.println("");
 delay(250);*/
Motores(100 , 100);
}


void Motoriz(int value) {
 if ( value>= 0 ){

  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
 }
else{
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  value *= -1;

 }
 analogWrite(PWMA, value);
}


void Motorder(int value){
 if ( value>= 0 ){

  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
 }
else{
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, LOW);
  value *= -1;

 }
 analogWrite(PWMB, value);
}
void Motores(int left, int right){
    Motorder(right);
    Motoriz(left);
}
