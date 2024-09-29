#ifndef _OURPAGES_BASE_H_
#define _OURPAGES_BASE_H_

#include <TFT_eSPI.h>

#include "OurSavedReadings.h"

struct IOurPage
{
  virtual ~IOurPage() { };
  // if we want to support other kinds of 
  virtual void drawPage(TFT_eSPI& tft, OurSavedReadings& ourSavedTemperatures) = 0;
};


#endif // _OURPAGES_BASE_H_
