#include <Servo.h>
int pinTrig = 2;
int pinEcho = 3;
long temps;
float distance;

Servo monServo;
int positionDuServo = 0;
int angle = 90;

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinTrig, LOW);  
  Serial.begin(9600);
  monServo.attach(9);
  monServo.write(positionDuServo);
}



void loop() {

  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  temps = pulseIn(pinEcho, HIGH);    

  if (temps < x) // si la distance est inférieure à x (à modifier) le moteur fait un demi tour
  {              
    /*for (positionDuServo = 0; positionDuServo <= 180; positionDuServo ++)
    { 
    monServo.write(positionDuServo);
    delay(15);
    */
    monServo.write(angle);
    }
  }

  else {
    
  }
  
}
