#ifndef _OURPAGES_SUMMMARYVIEW_H_
#define _OURPAGES_SUMMMARYVIEW_H_

#include "OurPages_Base.h"

class OurPages_SummaryView : public IOurPage
{
public:
  OurPages_SummaryView(OurSavedReadings::ReadingTypes readingType,  const char* pageName);
  void drawPage(TFT_eSPI& tft, OurSavedReadings& ourSavedTemperatures) override;

private:
  OurSavedReadings::ReadingTypes m_readingType;
  std::string m_pageName;
};

#endif // _OURPAGES_SUMMMARYVIEW_H_
