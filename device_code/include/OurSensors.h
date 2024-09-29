#ifndef _OURSENSORS_H_
#define _OURSENSORS_H_

class OurSensors
{
public:
  OurSensors();

  void onSetup();

  bool tryToReadSensors(
    double& insideTemperature, double& outsideTemperature,
    double& insidePressure, double& outsidePressure,
    double& insideHumidity, double& outsideHumidity
  );
};



#endif // _OURSENSORS_H_
