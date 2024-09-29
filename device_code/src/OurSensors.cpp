#include <Arduino.h>
#include "OurSensors.h"

/* placeholder implementation using random numbers until actually getting sensors working */

static double s_currentInnerTemp = 20.0;
static double s_currentOuterTemp = 12.0;


OurSensors::OurSensors()
{
  // this will be called when the object is constructed (before the Arduino setup function is called)
  randomSeed(analogRead(0));

}

void OurSensors::onSetup()
{
  // this will be called at setup time

}

static double getRandomTempChange()
{
  // this returns a random number somewhere between -1.0 and 1.0 (in steps of 0.1)
  return ((double) (random(21) - 10)) / 10.0;
}

bool OurSensors::tryToReadSensors(double& insideTemperature, double& outsideTemperature)
{
  s_currentInnerTemp += getRandomTempChange();
  s_currentOuterTemp += getRandomTempChange();

  insideTemperature = s_currentInnerTemp;
  outsideTemperature = s_currentOuterTemp;

  return true;
}
