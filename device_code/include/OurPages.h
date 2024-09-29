#ifndef _OURPAGES_H_
#define _OURPAGES_H_

class OurSavedTemperatures;

class OurPages
{
public:
  OurPages();

  void onSetup();

  void toggleCurrentPage();
  void drawCurrentPage(OurSavedTemperatures& ourSavedTemperatures);

private:
  int m_currentPageIndex;
};

#endif // _OURPAGES_H_
