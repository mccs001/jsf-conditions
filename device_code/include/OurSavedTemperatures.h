#ifndef _OURSAVEDTEMPERATURES_H_
#define _OURSAVEDTEMPERATURES_H_

class OurSavedTemperatures
{
public:
  OurSavedTemperatures();

  void clearReadings();

  void addReadings(double insideTemp, double outsideTemp);
  int getNumReadings();

  double getLatestInsideReading();
  double getLatestOutsideReading();

  double getInsideReading(int index);
  double getOutsideReading(int index);

  double getMinReading();
  double getMaxReading();

private:
  // could use vectors instead of arrays (which would give some extra conveniences too but stick with array to keep things simple)
  static const int ms_MAX_NUM_READINGS = 12;
  int m_numReadings;

  double m_insideReadings[ms_MAX_NUM_READINGS];
  double m_outsideReadings[ms_MAX_NUM_READINGS];
  double m_currentMinReading;
  double m_currentMaxReading;
};



#endif // _OURSAVEDTEMPERATURES_H_

