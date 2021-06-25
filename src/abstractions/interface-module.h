#pragma once
#include "module.h"

class InterfaceModule : public Module
{
public:
    virtual void loop() {}
    virtual void init() {}

    virtual void enable() {}
    virtual void reset() {}
};
