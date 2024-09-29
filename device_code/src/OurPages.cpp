#include <memory>

#include <TFT_eSPI.h>

#include "OurPages.h"
#include "OurPages_SummaryView.h"
#include "OurPages_GraphView.h"

// cheat and keep a single TFT_eSPI tft instance that is then passed to the pages
TFT_eSPI s_tft;

// for now keep a filescope collection of available pages (sadly no std::make_unique)...
static const std::unique_ptr<IOurPage> s_ourPages[] = 
{
  std::unique_ptr<IOurPage>(new OurPages_GraphView(OurSavedReadings::ReadingTypes::Temperature, "Temperatures")),
  std::unique_ptr<IOurPage>(new OurPages_SummaryView(OurSavedReadings::ReadingTypes::Temperature, "Temperatures")),
};

static const int s_numPages = sizeof(s_ourPages) / sizeof(s_ourPages[0]);

OurPages::OurPages() :
  m_currentPageIndex(0)
{

}

void OurPages::onSetup()
{
  // any common set-up for all pages can go here
  s_tft.init();
  s_tft.setRotation(1);
  s_tft.fillScreen(TFT_BLACK);
}

void OurPages::toggleCurrentPage()
{
  m_currentPageIndex = (m_currentPageIndex + 1) % s_numPages;
}

void OurPages::drawCurrentPage(OurSavedReadings& ourSavedTemperatures)
{
  s_ourPages[m_currentPageIndex]->drawPage(s_tft, ourSavedTemperatures);
}

