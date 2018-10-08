#include <Servo.h>

/* variables liées aux capteurs ultrasons*/

int pinTrig1 = 2;
int pinEcho1 = 3;
long temps;
int distance;

/* variables liées aux servos*/

Servo monServo1;
Servo monServo2;


void setup() {
  pinMode(pinTrig1, OUTPUT); 
  pinMode(pinEcho1, INPUT);
  digitalWrite(pinTrig1, LOW);  
  Serial.begin(9600);
 
  monServo1.attach(9);
  monServo1.write(0); // definir position du servo 1 
  
  monServo2.attach(8);
  monServo2.write(180); // definir position du servo 2
}




void loop() {

  digitalWrite(pinTrig1, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig1, LOW);
  temps = pulseIn(pinEcho1, HIGH);   // temps du signal 
  distance = temps / 58;  // distance parcourue par le signal

 /* première boucle permettant d'ouvrir la première porte du sas si le capteur ultrason détecte un élève */
 
  if (distance < 50) // si la distance est inférieure à 50cm (à modifier) le moteur fait un quart de tour               
    { 
    monServo1.write(90);
    monServo2.write(90);
    }
  
  else {
    monServo1.write(0);
    monServo2.write(180);
  }

/* fin de la première boucle */
  
}
