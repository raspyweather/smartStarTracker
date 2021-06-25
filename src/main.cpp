#include <Arduino.h>
#include <functional>

#include "core/camera-trigger/camera-trigger.h"
#include "core/motor/motor.h"

#include "features/Intervalometer.h"
#include "features/ManualTriggerControl.h"

#include "interfaces/SerialControl.h"

#include "SPI.h"

CameraTrigger *cameraTrigger;
Motor *motor;

Intervalometer *intervalometer;
ManualTriggerControl *manualTriggerControl;

SerialControl *serialControl;

Module *modules[5];

void setup()
{
  cameraTrigger = new CameraTrigger();
  motor = new Motor();

  intervalometer = new Intervalometer(cameraTrigger);
  manualTriggerControl = new ManualTriggerControl(cameraTrigger);

  for (Module *m : modules)
  {
    m->init();
  }
  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
}