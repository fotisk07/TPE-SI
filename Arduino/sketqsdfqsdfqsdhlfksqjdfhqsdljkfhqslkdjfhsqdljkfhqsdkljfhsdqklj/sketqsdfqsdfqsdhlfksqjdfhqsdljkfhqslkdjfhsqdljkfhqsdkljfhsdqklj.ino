#include <Servo.h>

Servo Servo1;
char receivedChar;
boolean newData = false;
char message = "GO";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,INPUT);
  0Servo1.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (digitalRead(4) == HIGH) {
    sendInfo();
  }
  recvInfo();
  if (newData == true){
    Servo1.write(90);
  }
  receivedChar = "";
  boolean newData = false;
  
}


void recvInfo() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    newData = true;
    }
}

void sendInfo() {
  Serial.println(message);
  delay(100);
}



