#ifndef _OURPAGES_BASE_H_
#define _OURPAGES_BASE_H_

#include <TFT_eSPI.h>

class OurSavedTemperatures;

struct IOurPage
{
  virtual ~IOurPage() { };
  // if we want to support other kinds of 
  virtual void drawPage(TFT_eSPI& tft, OurSavedTemperatures& ourSavedTemperatures) = 0;
};


#endif // _OURPAGES_BASE_H_
