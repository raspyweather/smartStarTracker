#include "awaiter.h"

void Awaiter::setTimeout(ulong duration)
{
    Awaiter::nextTrigger = duration;
}

void Awaiter::abort(){
    Awaiter::nextTrigger = -1;
}

bool Awaiter::check()
{
    ulong currentMs = millis();
    if (currentMs >= Awaiter::nextTrigger)
    {
        return true;
    }
}