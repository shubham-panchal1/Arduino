/*
  https://www.cheers2engineering.com/guided-projects/advanced-grades-9-12/arduino-advanced/i2c-scanner
   I2CScanner - to display I2C devices connected Arduino
   Arduino Nano - the SDA (data line) and SCL (clock line) are on the A4 and A5 pin respectively
  */
#include <Wire.h>
 void setup() {
  Wire.begin();
  Serial.begin(9600);
while (!Serial);// wait for serial monitor 
  Serial.println("I2C Scanner");
}
 
void loop() {
  byte error, address;
  int connectedDevices;
  Serial.println("Scanning...");
  connectedDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
  // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    error = Wire.endTransmission();
    if (error == 0) {  //device found
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      connectedDevices++;
    }
    else if (error==4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (connectedDevices == 0) {
    Serial.println("No I2C devices found");
  }
  else {
    Serial.println("done");
  }
  delay(5000);          
}
