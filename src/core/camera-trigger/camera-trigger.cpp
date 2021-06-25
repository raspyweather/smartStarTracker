#include <Arduino.h>
#include "config/pin_configurations.h"
#include "camera-trigger.h"
#include "logger.h"

void CameraTrigger::setInterval(ulong mSecondsTrigger, ulong mSecondsBreak)
{
    this->TriggerTimeMs = mSecondsTrigger;
    this->TriggerBreakMs = mSecondsBreak;
}

void CameraTrigger::setState(bool state)
{
    this->triggerPermanently = state;
    if (this->triggerPermanently)
    {
        Log_Info("CameraTrigger","Permanent Trigger activated");
    }
    else
    {
        Log_Info("CameraTrigger","Permanent Trigger deactivated");
    }
}

void CameraTrigger::init()
{
    Log_InitModule("CameraTrigger");
    pinMode(CAM_PIN, OUTPUT);
    Log_InitializedModule("CameraTrigger");
}

void CameraTrigger::loop()
{
    ulong currentMs = millis();

    if (this->isTriggerActive && this->triggerPermanently)
    {
        if (digitalRead(CAM_PIN) != LOW)
        {
            digitalWrite(CAM_PIN, LOW);
        }
        return;
    }

    // TODO implement time based trigger
    if (this->TriggerTimeMs)

        if (!this->isTriggerActive)
        {
            digitalWrite(CAM_PIN, HIGH);
        }
}