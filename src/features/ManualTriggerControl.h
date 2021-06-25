#pragma once
#include "abstractions/interface-module.h"
#include "core/camera-trigger/camera-trigger.h"

class ManualTriggerControl : public InterfaceModule
{
private:
    CameraTrigger* trigger;

public:
    void setState(bool state);

    void enable();
    void reset();

    ManualTriggerControl(CameraTrigger* ctrigger)
    {
        trigger = ctrigger;
    }
};