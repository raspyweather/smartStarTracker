#include "ManualTriggerControl.h"

void ManualTriggerControl::setState(bool state)
{
    ManualTriggerControl::trigger->setState(state);
}

void ManualTriggerControl::enable()
{}

void ManualTriggerControl::reset()
{
   ManualTriggerControl::trigger->setState(false);
}