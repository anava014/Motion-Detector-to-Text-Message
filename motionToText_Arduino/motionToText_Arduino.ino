#include <Bridge.h>
#include <HttpClient.h>

#define SENSITIVITY 4

int pirPin = 6;
int ledPin = 9;
int movementCounter = 0;
int movementTimer = 0;
boolean movement = false;

void setup() {
  Bridge.begin();
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void motionDetect () {
  movement = digitalRead(pirPin);
  if (movement == true) {
      ++movementCounter;
      movementTimer = millis();
      if(movementCounter >= SENSITIVITY){
        digitalWrite(ledPin, HIGH);
        
        /*client connects to Raspberry Pi which has its own server and 
        uses php to receive a trigger that then runs an exec command */
        HttpClient client;
        client.get("192.168.1.109/security.php?trigger=1");
        
        //Delay for 30 seconds to avoid spamming of text messages
        delay(30000);
        digitalWrite(ledPin, LOW);
      }
  }
}
  
void motionDetectorReset(){
  if(movementCounter > 0 && millis() > movementTimer + 10000)
    movementCounter = 0;
}
  
void loop() {
  motionDetect ();
  motionDetectorReset();
  delay(3000);
}
