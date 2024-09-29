#include <Arduino.h>
#include "OurSensors.h"
#include <Wire.h>
#include "BlueDot_BME280.h"

BlueDot_BME280 bme1; // Object for Sensor 1    outside
BlueDot_BME280 bme2; // Object for Sensor 2    inside

int bme1Detected = 0;
int bme2Detected = 0;

OurSensors::OurSensors()
{
}

void OurSensors::onSetup()
{
  // this will be called at setup time
  Wire.begin(43, 44);

  bme1.parameter.communication = 0; // I2C communication for Sensor 1 (bme1)
  bme2.parameter.communication = 0; // I2C communication for Sensor 2 (bme2)

  bme1.parameter.I2CAddress = 0x77; // I2C Address for Sensor 1 (bme1)
  bme2.parameter.I2CAddress = 0x76; // I2C Address for Sensor 2 (bme2)

  bme1.parameter.sensorMode = 0b11; // Setup Sensor mode for Sensor 1
  bme2.parameter.sensorMode = 0b11; // Setup Sensor mode for Sensor 2

  bme1.parameter.IIRfilter = 0b100; // IIR Filter for Sensor 1
  bme2.parameter.IIRfilter = 0b100; // IIR Filter for Sensor 2

  bme1.parameter.humidOversampling = 0b101; // Humidity Oversampling for Sensor 1
  bme2.parameter.humidOversampling = 0b101; // Humidity Oversampling for Sensor 2

  bme1.parameter.tempOversampling = 0b101; // Temperature Oversampling for Sensor 1
  bme2.parameter.tempOversampling = 0b101; // Temperature Oversampling for Sensor 2

  bme1.parameter.pressOversampling = 0b101; // Pressure Oversampling for Sensor 1
  bme2.parameter.pressOversampling = 0b101; // Pressure Oversampling for Sensor 2

  bme1.parameter.pressureSeaLevel = 1013.25; // default value of 1013.25 hPa (Sensor 1)
  bme2.parameter.pressureSeaLevel = 1013.25; // default value of 1013.25 hPa (Sensor 2)

  bme1.parameter.tempOutsideCelsius = 15; // default value of 15°C
  bme2.parameter.tempOutsideCelsius = 15; // default value of 15°C

  bme1.parameter.tempOutsideFahrenheit = 59; // default value of 59°F
  bme2.parameter.tempOutsideFahrenheit = 59; // default value of 59°F

  //*************ADVANCED SETUP IS OVER - LET'S CHECK THE CHIP ID!*******

  if (bme1.init() != 0x60)
  {
    Serial.println("Oops! First BME280 Sensor not found!");
    bme1Detected = 0;
  }

  else
  {
    Serial.println("First  BME280 Sensor detected!");
    bme1Detected = 1;
  }

  if (bme2.init() != 0x60)
  {
    Serial.println("Oops! Second BME280 Sensor not found!");
    bme2Detected = 0;
  }

  else
  {
    Serial.println("Second BME280 Sensor detected!");
    bme2Detected = 1;
  }
}

static double getRandomTempChange()
{
  // this returns a random number somewhere between -1.0 and 1.0 (in steps of 0.1)
  return ((double)(random(21) - 10)) / 10.0;
}

bool OurSensors::tryToReadSensors(double &insideTemperature, double &outsideTemperature)
{
  // should really check bme1Detected and bme2Detected ...

  insideTemperature = bme2.readTempC();
  outsideTemperature = bme1.readTempC();

  return true;
}
