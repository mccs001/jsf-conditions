#ifndef _OURPAGES_GRAPHVIEW_H_
#define _OURPAGES_GRAPHVIEW_H_

#include "OurPages_Base.h"

class OurPages_GraphView : public IOurPage
{
public:
  OurPages_GraphView(OurSavedReadings::ReadingTypes readingType,  const char* pageName);
  void drawPage(TFT_eSPI& tft, OurSavedReadings& ourSavedTemperatures) override;

private:
  OurSavedReadings::ReadingTypes m_readingType;
  std::string m_pageName;
  double m_last;
};

#endif // _OURPAGES_GRAPHVIEW_H_
