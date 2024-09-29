#ifndef _OURSENSORS_H_
#define _OURSENSORS_H_

class OurSensors
{
public:
  OurSensors();

  void onSetup();

  bool tryToReadSensors(double& insideTemperature, double& outsideTemperature);
};



#endif // _OURSENSORS_H_
