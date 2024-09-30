#include "OurSavedReadings.h"

#include <algorithm>


/////////////
// GenericReadings struct can handle any pairs of inside + outside numeric readings (plus an invalid value)

struct GenericReadings
{
  double invalidValue;
  int numReadings;

  // could use vectors instead of arrays (which would give some extra conveniences too but stick with array to keep things simple)
  double insideReadings[OurSavedReadings::ms_MAX_NUM_READINGS];
  double outsideReadings[OurSavedReadings::ms_MAX_NUM_READINGS];
  double currentMinReading;
  double currentMaxReading;

  GenericReadings(double _invalidValue);

  void clearReadings();
  int getNumReadings();

  void addReadings(double insideReading, double outsideReading);

  double getLatestInsideReading();
  double getLatestOutsideReading();

  double getInsideReading(int index);
  double getOutsideReading(int index);

  double getMinReading();
  double getMaxReading();
};


////////
// Implementation of GenericReadings functions

GenericReadings::GenericReadings(double _invalidValue)
    : invalidValue(_invalidValue)
{
  clearReadings();
}

void GenericReadings::clearReadings()
{
  numReadings = 0;
  currentMinReading = currentMaxReading = invalidValue;
}

void GenericReadings::addReadings(double insideReading, double outsideReading)
{
  if (numReadings < OurSavedReadings::ms_MAX_NUM_READINGS)
  {
    insideReadings[numReadings] = insideReading;
    outsideReadings[numReadings] = outsideReading;
    ++numReadings;
  }
  else
  {
    int lastIndex = OurSavedReadings::ms_MAX_NUM_READINGS - 1;
    // if we used a vector we could just pop off one end and push on the other
    for (int targetIndex = 0; targetIndex < lastIndex; ++targetIndex)
    {
      int sourceIndex = targetIndex + 1;
      insideReadings[targetIndex] = insideReadings[sourceIndex];
      outsideReadings[targetIndex] = outsideReadings[sourceIndex];
    }
    insideReadings[lastIndex] = insideReading;
    outsideReadings[lastIndex] = outsideReading;
  }

  double minFromThePair = std::min(insideReading, outsideReading);
  double maxFromThePair = std::max(insideReading, outsideReading);

  if (numReadings == 1)
  {
    currentMinReading = minFromThePair;
    currentMaxReading = maxFromThePair;
  }
  else
  {
    currentMinReading = std::min(currentMinReading, minFromThePair);
    currentMaxReading = std::max(currentMaxReading, maxFromThePair);
  }
}

int GenericReadings::getNumReadings()
{
  return numReadings;
}

double GenericReadings::getInsideReading(int index)
{
  if (index >= numReadings)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return invalidValue;
  }

  return insideReadings[index];
}
double GenericReadings::getOutsideReading(int index)
{
  if (index >= numReadings)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return invalidValue;
  }

  return outsideReadings[index];
}

double GenericReadings::getLatestInsideReading()
{
  if (numReadings == 0)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return invalidValue;
  }

  return insideReadings[numReadings - 1];
}

double GenericReadings::getLatestOutsideReading()
{
  if (numReadings == 0)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return invalidValue;
  }

  return outsideReadings[numReadings - 1];
}

double GenericReadings::getMinReading()
{
  return currentMinReading;
}
double GenericReadings::getMaxReading()
{
  return currentMaxReading;
}

// end of GenericReadings implementation
////////






// Definition of the internal state held by each OurSavedReadings instance
// we store a GenericReadings object for each type of reading that we support
struct OurSavedReadings::Impl
{
  Impl();
  GenericReadings allReadingTypes[static_cast<int>(ReadingTypes::Total_Count)];

  GenericReadings& GetReadings(ReadingTypes readingType);
};

OurSavedReadings::Impl::Impl()
  : allReadingTypes {
    GenericReadings(-300.0),  // temperature readings
    GenericReadings(-400.0),  // pressure readings
    GenericReadings(-500.0),  // humidity readings
  }
{
}

GenericReadings& OurSavedReadings::Impl::GetReadings(ReadingTypes readingType)
{
  int index = static_cast<int>(readingType);
  if ((index < 0) || (index >= static_cast<int>(ReadingTypes::Total_Count)))
  {
    throw std::invalid_argument("Bad index!");
  }
  return allReadingTypes[index];
}



// Finally, onto the implementation of the OurSavedReadings public interface
///////

OurSavedReadings::OurSavedReadings()
    : m_impl(new Impl() )
{
  clearAllReadings();
}

OurSavedReadings::~OurSavedReadings() = default;

void OurSavedReadings::clearAllReadings()
{
  for (int i = 0; i < static_cast<int>(ReadingTypes::Total_Count); ++i)
  {
    clearReadings(static_cast<ReadingTypes>(i));
  }
}

void OurSavedReadings::clearReadings(ReadingTypes readingType)
{
  m_impl->GetReadings(readingType).clearReadings();
}

void OurSavedReadings::addReadings(ReadingTypes readingType, double insideReading, double outsideReading)
{
  m_impl->GetReadings(readingType).addReadings(insideReading, outsideReading);
}

int OurSavedReadings::getNumReadings(ReadingTypes readingType)
{
  return m_impl->GetReadings(readingType).getNumReadings();
}

double OurSavedReadings::getInsideReading(ReadingTypes readingType, int index)
{
  return m_impl->GetReadings(readingType).getInsideReading(index);
}

double OurSavedReadings::getOutsideReading(ReadingTypes readingType, int index)
{
  return m_impl->GetReadings(readingType).getOutsideReading(index);
}

double OurSavedReadings::getLatestInsideReading(ReadingTypes readingType)
{
  return m_impl->GetReadings(readingType).getLatestInsideReading();
}

double OurSavedReadings::getLatestOutsideReading(ReadingTypes readingType)
{
  return m_impl->GetReadings(readingType).getLatestOutsideReading();
}

double OurSavedReadings::getMinReading(ReadingTypes readingType)
{
  return m_impl->GetReadings(readingType).getMinReading();
}

double OurSavedReadings::getMaxReading(ReadingTypes readingType)
{
  return m_impl->GetReadings(readingType).getMaxReading();
}
