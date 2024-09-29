#ifndef _OURPAGES_SUMMMARYVIEW_H_
#define _OURPAGES_SUMMMARYVIEW_H_

#include "OurPages_Base.h"

class OurPages_SummaryView : public IOurPage
{
public:
  void drawPage(TFT_eSPI& tft, OurSavedReadings& ourSavedTemperatures) override;
};

#endif // _OURPAGES_SUMMMARYVIEW_H_
