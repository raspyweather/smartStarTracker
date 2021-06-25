#pragma once
#include <Arduino.h>
#include "abstractions/module.h"

class CameraTrigger : public Module
{
    bool isTriggerActive;
    bool triggerPermanently;
    ulong TriggerBreakMs;
    ulong TriggerTimeMs;

    ulong lastTriggerMs;
    ulong lastBreakMs;

public:
    void setState(bool state);
    void setInterval(ulong triggerTimeMs, ulong breakTimeMs);
    void init();
    void loop();
};
