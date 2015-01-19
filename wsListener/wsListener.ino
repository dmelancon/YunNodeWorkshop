#include <Process.h>
#include <LiquidCrystal.h>

Process nodejs;

String fromNode = "";

void setup() {
  
  Serial.begin(9600);
  
  Bridge.begin();
   
  while (!Serial);
  
  // launch the echo.js script asynchronously:
  nodejs.runShellCommandAsynchronously("killall node");
  nodejs.runShellCommandAsynchronously("node /mnt/sda1/arduino/node/wsServerBasic.js");
}

void loop() {
  
  if (nodejs.running()) {
    
      char inByte = nodejs.read();      
      fromNode = nodejs.readStringUntil('\n');

      if (fromNode.length() > 0){
        Serial.println("message : " + fromNode);      
      }
      
  }
  
  
  
}
