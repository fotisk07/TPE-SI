#include <Servo.h>
int newData = false ;
char receivedChar = "" ;
char message[6] = "NO" ;
int servo[4] = {9,8,7,6};

Servo entree1;
Servo sortie1;
Servo entree2;
Servo sortie2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ;
  entree1.attach(servo[0]);
  sortie1.attach(servo[1]);
  entree2.attach(servo[2]);
  sortie2.attach(servo[3]); 
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
        if (receivedChar == "1")
          ouvrir_sortie();
        else
          ouvrir_entree();
        newData = false;
        message[6] = "NO";
        receivedChar = "0"; 
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
  entree(90);
  entree(0);
}

void ouvrir_sortie()
{
  sortie(90);
  sortie(0);
}



void entree(angle) 
{
  reverse_angle = map(angle, 180, 0, 0, 180);
  entree1.write(angle);
  entree2.write(reverse_angle);
  delay(5000);
    
}


void sortie(angle)
{
  reverse_angle = map(angle, 180, 0, 0, 180);
  sortie1.write(angle);
  sortie2.write(reverse_angle);
  delay(5000);
}


