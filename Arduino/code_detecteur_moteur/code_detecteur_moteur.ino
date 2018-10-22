#include <Servo.h>

int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  // variable for reading the pin status
 
Servo monServo;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  monServo.attach(9);
  monServo.write(0);
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    monServo.write(180);
    Serial.println("OK");
  } else {
   monServo.write(0);
    Serial.println("PAS OK");
    }
 
}
