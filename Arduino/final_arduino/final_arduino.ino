#include <Servo.h>
int newData = false ;
char receivedChar = "" ;
char message[5] = "No" ;
int servo[3] = [9,8,7,6];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  entree1.attach(servo[0]);
  sortie1.attach(servo[2]); 
  pinMode(INPUT, 4);
  
  entree1.write(0);
  sortie1.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(4) == HIGH)
  {
    entree1.write(180);
    delay(5000);
    entree1.write(0);
    while true
    {
      message = "Hello";
      sendInfo();
      recvInfo();
      if newData = true
      {
        if receivedChar == "Yes"
        {
          sortie1.write(180);
          delay(5000);
          sortie1.write(0);
        }
        else
        {
          entree1.write(180);
          delay(5000);
          entree1.write(0);
        }
      }
    }
    
    
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

