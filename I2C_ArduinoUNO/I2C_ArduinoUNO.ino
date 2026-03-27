/*******************************************************************
  Este es un sketch de ejemplo básico para mostrar el funcionamiento
  de esta librería:
  Descarga la librería aquí:
  https://github.com/McOrts/WindQX_SolidState_Anemometer

  Para estos dispositivos:
  https://ecdsl.com/en/categoria-producto/windqx/

  Autor: McOrts (Carlos Orts)
  Fecha: enero de 2026
 * ****************************************************************
  Conexión de pines para Arduino UNO

  Pin del WindQX SA.01 | Pin de Arduino UNO
    - (negro)          | GND
    + (rojo)           | 5V
   SCL (blanco)        | PIN 5 (SCL)
   SDA (amarillo)      | PIN 4 (SDA)
 * *****************************************************************/
#include "WindQX.h"

// Crear un objeto sensor
WindQX SA01;

void setup() {
  Serial.begin(115200);
  SA01.Initialize("I2C");  // Inicializar el sensor WindQX SA01
  Serial.println(SA01.getStatus());
}

void loop() {
  if (SA01.getData() == "OK") {                  // Obtener todos los datos del dispositivo WindQX
    float temperatura = SA01.getTemperature();   // Devuelve la temperatura en grados Celsius
    float viento = SA01.getWind();               // Devuelve la velocidad del viento en km/h

    Serial.print(viento, 1);
    Serial.print(" km/h, ");
    Serial.print(temperatura, 2);
    Serial.println("°C");
  } else {
    Serial.println(SA01.getStatus());
  }
  delay(500);
}