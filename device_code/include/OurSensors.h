#ifndef _OURSENSORS_H_
#define _OURSENSORS_H_

#include <memory>

class OurSensors
{
public:
  OurSensors();
  ~OurSensors();

  void onSetup();

  bool tryToReadSensors(
    double& insideTemperature, double& outsideTemperature,
    double& insidePressure, double& outsidePressure,
    double& insideHumidity, double& outsideHumidity
  );

private:
  struct Impl;
  std::unique_ptr<Impl> m_impl;
};



#endif // _OURSENSORS_H_
