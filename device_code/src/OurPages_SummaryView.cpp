#include "OurPages_SummaryView.h"
#include "OurSavedTemperatures.h"


void OurPages_SummaryView::drawPage(TFT_eSPI& tft, OurSavedTemperatures& ourSavedTemperatures)
{
  double temp2 = ourSavedTemperatures.getLatestInsideReading();
  double temp1 = ourSavedTemperatures.getLatestOutsideReading();
  double min1 = ourSavedTemperatures.getMinReading();
  double max1 = ourSavedTemperatures.getMaxReading();

  // don't support humidity or pressure yet
  double h1 = 0.0;
  double h2 = 0.0;
  double pressure = 0.0;


  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setCursor(0, 30);
  tft.setFreeFont(&Orbitron_Light_24);
  tft.println(" Inside        Outside");
  tft.drawLine(0, 35, 370, 35, TFT_BLUE);
  tft.setCursor(0, 60);
  tft.print((temp2));
  tft.setCursor(150, 60);
  tft.print(temp1);
  tft.setCursor(240, 60);
  tft.print(("c"));
  tft.setCursor(0, 90);
  tft.print(h2);
  tft.setCursor(150, 90);
  tft.print(h1);
  tft.setCursor(240, 90);
  tft.print(("%"));
  tft.setCursor(0, 120);
  tft.print(("Pressure"));
  tft.setCursor(150, 120);
  tft.print((pressure));
  tft.setCursor(240,120);
  tft.print(("mBar"));
  tft.setCursor(0, 150);
  tft.print("Out: m/M");
  tft.setCursor(140, 150);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  tft.print((min1));
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setCursor(235, 150);
  tft.print((max1));
}
