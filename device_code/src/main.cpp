#include <Arduino.h>
#include <OneButton.h>

#include "OurSavedReadings.h"
#include "OurPages.h"
#include "OurSensors.h"

#define PIN_BUTTON_1                 0
#define PIN_BUTTON_2                 14

static const unsigned long TIME_BETWEEN_READINGS_ms = 10000;

OneButton g_button1(PIN_BUTTON_1, true);
OneButton g_button2(PIN_BUTTON_2, true);


OurSavedReadings g_ourSavedReadings;
OurSensors g_ourSensors;


OurPages g_ourPages;



bool g_forceNewReading = true;
bool g_forceRefresh = true;
unsigned long g_timestampOfLastReading_ms = 0;

void onPressButton1()
{
  g_ourPages.toggleCurrentPage();
  g_forceRefresh = true;
}

void onLongPressButton2()
{
  g_ourSavedReadings.clearReadings();
  g_forceRefresh = true;
}


void setup()
{
  Serial.begin(115200);
  Serial.println("Hello setup");

  // these can use C++ lambdas but sticking with defined functions for simplicity
  g_button1.attachClick(onPressButton1);
  g_button2.attachLongPressStart(onLongPressButton2);

  g_ourSensors.onSetup();
  g_ourPages.onSetup();
}

void loop()
{
  // Serial.println("Hello loop");

  
  g_button1.tick();
  g_button2.tick();

  unsigned long currentTimestamp_ms = millis();

  if (g_forceNewReading || ((currentTimestamp_ms - g_timestampOfLastReading_ms) >= TIME_BETWEEN_READINGS_ms))
  {
    Serial.println("Hello new reading");
    g_timestampOfLastReading_ms = currentTimestamp_ms;
    g_forceNewReading = false;

    // take a new reading
    double insideTemp = 0.0;
    double outsideTemp = 0.0;

    if (g_ourSensors.tryToReadSensors(insideTemp, outsideTemp))
    {
      g_ourSavedReadings.addReadings(insideTemp, outsideTemp);
      g_forceRefresh = true;
    }
    else
    {
      // failed to read the sensors ... take some action
    }
  }

  if (g_forceRefresh)
  {
    Serial.println("Hello draw new page");

    g_forceRefresh = false;

    g_ourPages.drawCurrentPage(g_ourSavedReadings);
  }
  
}

