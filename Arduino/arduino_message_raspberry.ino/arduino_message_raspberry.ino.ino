char receivedChar;
boolean newData = false;
char message = "";


void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
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


