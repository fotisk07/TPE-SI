#include <Servo.h>
#include <string.h>
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
  pinMode(OUTPUT, 4);
  pinMode(INPUT, 3);
  pinMode(INPUT, 7);
  init();

}

void loop() {
  // put your main code here, to run repeatedly:
   sorry:
  // put your main code here, to run repeatedly:
  if (digitalRead(3) == HIGH){
    delay(500);
    while (1){
      if (digitalRead(7)== HIGH){
        entree();
        sendInfo();
        while(1){
          recvInfo();
          delay(500);
          if (strstr(receivedChar, 'Y') != NULL){
            sortie();
            goto sorry;
          }
          else{
            if (strstr(receivedChar, 'N') != NULL){
              entree();
              goto sorry;
            }
          }
      }
      }
    }
  }
  
}

void entree() { //Functions to determine
  digitalWrite(4, HIGH);
  delay(1000);
}

void sortie(){ //Functions to determine
  digitalWrite(4,LOW);
  delay(1000);
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

void init(){ \\function to be determined
  
}

