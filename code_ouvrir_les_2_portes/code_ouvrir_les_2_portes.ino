#include <Servo.h>
 int inputPin1 = 2;               // choose the input pin (for PIR sensor)
int pirState1 = LOW;             // we start, assuming no motion detected
int val1 = 0;  // variable for reading the pin status
 
Servo monServo1;
Servo monServo2;
 void setup() {
  pinMode(inputPin1, INPUT);     // declare sensor as input
  monServo1.attach(7);
  monServo1.write(90);
  monServo2.attach(8);
  monServo2.write(90);
  Serial.begin(9600);
}
 
void loop(){
  val1 = digitalRead(inputPin1);  // read input value
  if (val1 == HIGH) {            // check if the input is HIGH
    monServo1.write(0);
    monServo2.write(180);
    Serial.println("OK");
  } else {
   monServo1.write(90);
   monServo2.write(90);
    Serial.println("PAS OK");
    }
 
}
