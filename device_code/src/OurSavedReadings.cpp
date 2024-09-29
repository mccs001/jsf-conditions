#include "OurSavedReadings.h"

#include <algorithm>


static const double S_INVALID_TEMPERATURE = -300.0;

OurSavedReadings::OurSavedReadings()
{
  clearAllReadings();
}

void OurSavedReadings::clearAllReadings()
{
  clearReadings(ReadingTypes::Temperature);
}

void OurSavedReadings::clearReadings(ReadingTypes readingType)
{
  m_numReadings = 0;
  m_currentMinReading = m_currentMaxReading = S_INVALID_TEMPERATURE;
}

void OurSavedReadings::addReadings(ReadingTypes readingType, double insideReading, double outsideReading)
{
  if (m_numReadings < ms_MAX_NUM_READINGS)
  {
    m_insideReadings[m_numReadings] = insideReading;
    m_outsideReadings[m_numReadings] = outsideReading;
    ++m_numReadings;
  }
  else
  {
    int lastIndex = ms_MAX_NUM_READINGS - 1;
    // if we used a vector we could just pop off one end and push on the other
    for (int targetIndex = 0; targetIndex < lastIndex; ++targetIndex)
    {
      int sourceIndex = targetIndex + 1;
      m_insideReadings[targetIndex] = m_insideReadings[sourceIndex];
      m_outsideReadings[targetIndex] = m_outsideReadings[sourceIndex];
    }
    m_insideReadings[lastIndex] = insideReading;
    m_outsideReadings[lastIndex] = outsideReading;
  }

  double minFromThePair = std::min(insideReading, outsideReading);
  double maxFromThePair = std::max(insideReading, outsideReading);

  if (m_numReadings == 1)
  {
    m_currentMinReading = minFromThePair;
    m_currentMaxReading = maxFromThePair;
  }
  else
  {
    m_currentMinReading = std::min(m_currentMinReading, minFromThePair);
    m_currentMaxReading = std::max(m_currentMaxReading, maxFromThePair);
  }
}

int OurSavedReadings::getNumReadings(ReadingTypes readingType)
{
  return m_numReadings;
}

double OurSavedReadings::getInsideReading(ReadingTypes readingType, int index)
{
  if (index >= m_numReadings)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return S_INVALID_TEMPERATURE;
  }

  return m_insideReadings[index];
}

double OurSavedReadings::getOutsideReading(ReadingTypes readingType, int index)
{
  if (index >= m_numReadings)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return S_INVALID_TEMPERATURE;
  }

  return m_outsideReadings[index];
}

double OurSavedReadings::getLatestInsideReading(ReadingTypes readingType)
{
  if (m_numReadings == 0)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return S_INVALID_TEMPERATURE;
  }

  return m_insideReadings[m_numReadings - 1];
}

double OurSavedReadings::getLatestOutsideReading(ReadingTypes readingType)
{
  if (m_numReadings == 0)
  {
    // could also change the function to return a boolean or throw an exception in this case
    return S_INVALID_TEMPERATURE;
  }

  return m_outsideReadings[m_numReadings - 1];
}



double OurSavedReadings::getMinReading(ReadingTypes readingType)
{
  return m_currentMinReading;
}

double OurSavedReadings::getMaxReading(ReadingTypes readingType)
{
  return m_currentMaxReading;
}
