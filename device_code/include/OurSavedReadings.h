#ifndef _OURSAVEDREADINGS_H_
#define _OURSAVEDREADINGS_H_

#include <memory>

class OurSavedReadings
{
public:

  // current design decision to fix the types of readings that we support at compile-time
  // alternatively this could be done dynamically at runtime in order to support any number of types of reading
  enum class ReadingTypes
  {
    Temperature,
    Pressure,
    Humidity,
    
    Total_Count
  };

  OurSavedReadings();
  ~OurSavedReadings();

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
  
  
  struct Impl;
  std::unique_ptr<Impl> m_impl;

};



#endif // _OURSAVEDREADINGS_H_

