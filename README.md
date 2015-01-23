#Setting up Arduino Yun with Node.js on ITP Sandbox
#####SETUP

 - Download Bonjour Browser.

1. Start Yun and connect to ArduinoXXXXXXXXX wireless connection.
2. Go to Arduino.local/
3. Copy down Yun's MAC address.
4. Resign on to NYU wireless and go to computer.registration.nyu.edu and register your YUN and computer. 
5. Resign on to your Yun's wifi network and configure you wirless network for ITPSandbox. Change name/password. 
6. Sign your computer on the ITP Sandbox
7. Look at Bonjour Browser to find you Yun's IP address. 
8. ssh name@YunIpAdresss
9. http://arduino.cc/en/Tutorial/YunSysupgrade
10. Download this and extract: http://arduino.cc/en/Tutorial/ExpandingYunDiskSpace
11. Make sure you have a microSD card in your Yuns slot and run the YunExpanderSketch
12. Allocate at least 50% of your SD cards disk space to Yun Image
13. Reconfigure Wireless
14. Once your expanded Yun is back the Sandbox SSH into it. 

#####INSTALLING NODE and packages

1. opkg update
2. opkg install node
3. opkg install node-ws 
4. opkg install node-socket.io
6. opkg install node-serialport
6. opkg install openssh-sftp-server
7. type node -v to insure node is installed

#####How WS server works ( how we are using it)

![DIAGRAM1](http://davidptracy.com/files/diagram-02.png
)
![DIAGRAM2](http://davidptracy.com/files/diagram-01.png
)
