#pragma once
#include "abstractions/interface-module.h"
#include "core/camera-trigger/camera-trigger.h"

class Intervalometer : public InterfaceModule
{
private:
    CameraTrigger* trigger;
    int msDuration = 1000;
    int msBreak = 1000;

public:
    void setBreak(int msBreak);
    void setDuration(int msDuration);
    void start();
    void stop();

    void enable();
    void reset();

    Intervalometer(CameraTrigger* ctrigger)
    {
        trigger = ctrigger;
    }
};
