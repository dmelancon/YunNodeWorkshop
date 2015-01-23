#include <Process.h>
#include <LiquidCrystal.h>

Process nodejs;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String header = "Sensor Value: ";
String message = "...";

//String topMessage;
String botMessage;

void setup() {

  Serial.begin(9600);

  Bridge.begin();

  while (!Serial);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // launch the echo.js script asynchronously:
  //  nodejs.runShellCommandAsynchronously("killall node");
  //  nodejs.runShellCommandAsynchronously("killall nodejs");
  nodejs.runShellCommandAsynchronously("node /mnt/sda1/arduino/node/wsServerBasic.js");
}

void loop() {

  if (nodejs.running()) {

    char inByte = nodejs.read();
    message = nodejs.readStringUntil('\n');

    if (message.length() > 0) {
      Serial.println("message : " + message);
            
      if (message.length() > 16) {
        botMessage = message.substring(16, message.length());
      } else {
        botMessage = "";
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(message);
      lcd.setCursor(0, 1);
      lcd.print(botMessage);
    }

  }
}
