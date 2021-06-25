#pragma once
#include <Arduino.h>
#include "abstractions/module.h"

class Awaiter
{
    ulong nextTrigger = 0;

public:
    void setTimeout(ulong duration);

    void abort();
    bool check();
};
