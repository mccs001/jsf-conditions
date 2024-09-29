#include "OurPages_GraphView.h"
#include "OurSavedTemperatures.h"
#include "orb.h"

// the contents of this file are mostly copied from the original BTC price tracker project
// https://github.com/VolosR/bitCoinTTGO

#define gray 0x39C7
#define dblue 0x01A9
#define purple 0xF14F
#define green 0x2D51

double last = 0.0;
int fromtop = 60;

void OurPages_GraphView::drawPage(TFT_eSPI &tft, OurSavedTemperatures &ourSavedTemperatures)
{

  tft.fillScreen(TFT_BLACK);
  // tft.fillRect(200,126,4,4,TFT_GREEN);
  tft.fillRect(46, 32, 56, 28, dblue);

  // tft.fillRect(118,22,120,100,dblue);

  for (int i = 0; i < 13; i++)
  {
    tft.drawLine(118 + (i * 10), 22, 118 + (i * 10), 122, gray);
  }
  for (int i = 0; i < 10; i++)
  {
    tft.drawLine(118, 22 + (i * 10), 238, 22 + (i * 10), gray);
  }
  tft.drawLine(118, 22, 118, 122, TFT_WHITE);
  tft.drawLine(118, 122, 238, 122, TFT_WHITE);

  /*
  tft.setTextColor(TFT_WHITE, dblue);
  tft.drawString("updated:", 50, 37);
  tft.drawString("Time", 50, 47);
  */
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // current = v.toDouble();
  double current = ourSavedTemperatures.getLatestInsideReading();

  tft.drawString("PRICE (usd):", 4, fromtop + 4, 2);
  tft.drawString("CHANGE:", 4, fromtop + 32 + 8, 2);
  tft.setFreeFont(&Orbitron_Medium_16);
  tft.setTextColor(green, TFT_BLACK);
  tft.drawString(String(current), 4, fromtop + 20);
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.drawString("bitCoin", 4, 0);
  tft.setTextColor(green, TFT_BLACK);

  tft.drawString(String(current - last), 4, fromtop + 46 + 10, 2);
  tft.setTextColor(0x0B52, TFT_BLACK);
  tft.setTextFont(1);

  char readingBuff[255] = { 0 };
  sprintf(readingBuff, "LAST %d READINGS", OurSavedTemperatures::ms_MAX_NUM_READINGS);
  tft.drawString(readingBuff, 118, 6);
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.setTextFont(1);
  tft.drawString("MAX", 94, 16);
  tft.drawString("MIN", 94, 122, 1);
  last = current;

  double minimal = ourSavedTemperatures.getMinReading();
  double maximal = ourSavedTemperatures.getMaxReading();

  int mx = maximal / 2;
  int mi = minimal / 2;

  int n = ourSavedTemperatures.getNumReadings();
  double p[OurSavedTemperatures::ms_MAX_NUM_READINGS];

  for (int i = 0; i < n; i++)
  {
    int re = ourSavedTemperatures.getInsideReading(i) / 2;
    p[i] = map(re, mi, mx, 0, 100);

    // Serial.println(p[i]);
    //  tft.drawString(String(p[i]),190,i*10);
  }
  if (n >= 1)
  {
    for (int i = 1; i < n; i++)
    {
      tft.drawLine(118 + ((i - 1) * 10), 122 - p[i - 1], 118 + ((i) * 10), 122 - p[i], TFT_RED);
      tft.fillCircle(118 + ((i - 1) * 10), 122 - p[i - 1], 2, TFT_RED);
      tft.fillCircle(118 + ((i) * 10), 122 - p[i], 2, TFT_RED);
    }
  }
}
