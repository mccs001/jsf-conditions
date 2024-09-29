#ifndef _OURSAVEDREADINGS_H_
#define _OURSAVEDREADINGS_H_

class OurSavedReadings
{
public:
  enum class ReadingTypes
  {
    Temperature,
    
    Total_Count
  };

  OurSavedReadings();

  void clearAllReadings();

  void clearReadings(ReadingTypes readingType);

  void addReadings(ReadingTypes readingType, double insideReading, double outsideReading);
  int getNumReadings(ReadingTypes readingType);

  double getLatestInsideReading(ReadingTypes readingType);
  double getLatestOutsideReading(ReadingTypes readingType);

  double getInsideReading(ReadingTypes readingType, int index);
  double getOutsideReading(ReadingTypes readingType, int index);

  double getMinReading(ReadingTypes readingType);
  double getMaxReading(ReadingTypes readingType);

  static const int ms_MAX_NUM_READINGS = 12;

private:
  // could use vectors instead of arrays (which would give some extra conveniences too but stick with array to keep things simple)
  
  int m_numReadings;

  double m_insideReadings[ms_MAX_NUM_READINGS];
  double m_outsideReadings[ms_MAX_NUM_READINGS];
  double m_currentMinReading;
  double m_currentMaxReading;
};



#endif // _OURSAVEDREADINGS_H_

