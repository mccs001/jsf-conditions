#ifndef _OURPAGES_GRAPHVIEW_H_
#define _OURPAGES_GRAPHVIEW_H_

#include "OurPages_Base.h"

class OurPages_GraphView : public IOurPage
{
public:
  void drawPage(TFT_eSPI& tft, OurSavedReadings& ourSavedTemperatures) override;
};

#endif // _OURPAGES_GRAPHVIEW_H_
