#include <Bridge.h>
#include <HttpClient.h>

int pirPin = 6;
int ledPin = 9;
boolean movement = false;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void motionDetect () {
  
  movement = digitalRead(pirPin);
  if (movement == true) {
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
  
  
void loop() {
  motionDetect ();

  delay(3000);

}
