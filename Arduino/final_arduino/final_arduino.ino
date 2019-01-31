#include <Servo.h>
int newData = false ;
char receivedChar = "" ;
char message[6] = "HE" ;
int servo[4] = {9,8,7,6};

Servo entree1;
Servo sortie1;


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
    ouvrir_entree();
    while (true)
    {
      message[6] = "Hello";
      sendInfo();
      recvInfo();
      if (newData == true)
      {
        if (receivedChar == "Yes")
          ouvrir_sortie();
        else
          ouvrir_entree();
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

void ouvrir_entree() 
{
    entree1.write(180);
    delay(5000);
    entree1.write(0);
}

void ouvrir_sortie()
{
  sortie1.write(180);
  delay(5000);
  sortie1.write(0);
}


