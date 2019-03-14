#include <Servo.h>
#include <string.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int newData = false;
char receivedChar = "" ;
char message[6] = "GO" 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(3);
servo2.attach(4);
servo3.attach(5);
servo4.attach(6);
bool pass = false;
pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(2)==1)
{
servo3.write(90);
servo4.write(90);
sendInfo();
pass = true;
}
if (digitalRead(2)==0) {
servo3.write(0);
servo4.write(180);
}

if (pass == true){
  recvInfo();
}

if (digitalRead(7)==1) {
servo1.write(90);
servo2.write(180);
}

if (digitalRead(7)==0) {
servo1.write(180);
servo2.write(90);

}
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



