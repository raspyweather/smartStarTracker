#include "Intervalometer.h"

void Intervalometer::setBreak(int msBreak)
{
    Intervalometer::msBreak = msBreak;

    Intervalometer::trigger->setInterval(
        Intervalometer::msDuration,
        Intervalometer::msBreak);
}

void Intervalometer::setDuration(int msDuration)
{
    Intervalometer::msDuration = msDuration;

    Intervalometer::trigger->setInterval(
        Intervalometer::msDuration,
        Intervalometer::msBreak);
}

void Intervalometer::enable()
{
}

void Intervalometer::reset()
{
    Intervalometer::msBreak = 1000;
    Intervalometer::msDuration = 1000;
    Intervalometer::stop();
}

void Intervalometer::start()
{
    Intervalometer::trigger->setState(true);
}

void Intervalometer::stop()
{
    Intervalometer::trigger->setState(false);
}