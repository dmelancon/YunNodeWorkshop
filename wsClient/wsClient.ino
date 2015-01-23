#include <Bridge.h>
#include <Process.h>
#include <LiquidCrystal.h>

// make a new Process for calling Node
Process ws;    

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool wsPressed = false;

String header = "Sensor Value: ";
String message = "...";

char sensorStr[3];

void setup() {
  
  Bridge.begin();
  Serial.begin(9600);
  
  while(!Serial);
  
  pinMode(7, INPUT);  
  pinMode(8, OUTPUT);   

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);  
  
  // launch the echo.js script asynchronously:
  ws.runShellCommandAsynchronously("node /mnt/sda1/arduino/node/wsClientBasic.js");
  
  Serial.println("SKETCH STARTED!"); 
}

void loop() {
  
    // ============ WS Button ================
  
   if (digitalRead(7) == HIGH) {
     digitalWrite(8, HIGH);
     wsPressed = true; 
     int sensorReading = analogRead(A0);
     message = String(sensorReading);
     Serial.println(sensorReading);
 
     message.toCharArray(sensorStr, 3); 
        for( int i = 0; i < message.length(); ++i ) {
          ws.write(message.charAt(i));
        }  
     ws.write('\n');    
   }
   else{
     digitalWrite(8, LOW); 
     wsPressed = false; 
   }
   
   while (ws.available()) {
    char c = ws.read();
    Serial.print(c);    
  }
   
   lcd.setCursor(0,0);
   lcd.print(header);   
   lcd.setCursor(0,1);
   lcd.print(message);  

}
