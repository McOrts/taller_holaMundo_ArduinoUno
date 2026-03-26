/*******************************************************************
  This is a basic example sketch to show the working of this library:
  Download the library here: https://github.com/McOrts/WindQX_SolidState_Anemometer
  For these devices: https://ecdsl.com/en/categoria-producto/windqx/
  Author: McOrts (Carlos Orts)
  Date : January 2026
 * ****************************************************************
  Pinout connection for Arduino UNO

  WindQX SA.01 pin | Arduino UNO pin
    - (black)      | GND
    + (red)        | 5V
   SCL (white)     | PIN 5 (SCL)
   SDA (yellow)    | PIN 4 (SDA)
 * *****************************************************************/
#include "WindQX.h"

// Create a sensor object
WindQX SA01;

void setup() {
  Serial.begin(115200);
  SA01.Initialize("I2C");  // Init WindQX SA01 sensor
  Serial.println(SA01.getStatus());
}

void loop() {
  if (SA01.getData() == "OK") {                  // get All data from WindQX device
    float temperature = SA01.getTemperature();  // return temperature in celsius
    float wind = SA01.getWind();                // return wind speed in Km/h
    Serial.print(wind, 1);
    Serial.print(" km/h, ");
    Serial.print(temperature, 2);
    Serial.println("°C");
  } else {
    Serial.println(SA01.getStatus());
  }
  delay(500);
}
