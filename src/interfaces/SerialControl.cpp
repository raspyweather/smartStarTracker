#include "SerialControl.h"

void SerialControl::init()
{
}

void SerialControl::loop()
{
    int available = Serial.available();
    if (available)
    {
        currentStr += Serial.readString();
        currentSize += available;
    }

    if (currentSize > maxSize)
    {
        currentStr = "";
        currentSize = 0;
    }

    if (currentStr.indexOf('\n') > -1 || currentStr.indexOf('\r') > -1)
    {
        tryParse();
        currentStr = "";
        currentSize = 0;
    }
}

bool SerialControl::checkPrefix(String prefix, int startIndex)
{
    return (currentStr.indexOf("[" + prefix + "]", startIndex) > -1);
}

int SerialControl::getNextPrefix(String prefix, int startIndex)
{
    int newIndex = currentStr.indexOf("[" + prefix + "]", startIndex);
    if (newIndex > -1)
    {
        return newIndex + 2 + prefix.length();
    }

    return startIndex;
}

String SerialControl::extractValue(String input, int startIndex)
{
    int s_startIndex = input.indexOf('[', startIndex);

    if (s_startIndex == -1)
    {
        return emptyString;
    }

    int s_endIndex = input.indexOf(']', s_startIndex);
    if (s_endIndex == -1 || s_endIndex <= s_startIndex)
    {
        return emptyString;
    }

    return input.substring(s_startIndex, s_endIndex);
}

ulong SerialControl::extractAndParseValue(String input, int startIndex)
{
    int s_startIndex = input.indexOf('[', startIndex);

    if (s_startIndex == -1)
    {
        return NULL;
    }

    int s_endIndex = input.indexOf(']', s_startIndex);
    if (s_endIndex == -1 || s_endIndex <= s_startIndex)
    {
        return NULL;
    }

    String interMediateStr = input.substring(s_startIndex, s_endIndex);

    interMediateStr.trim();

    return interMediateStr.toInt();
}

void SerialControl::tryParse()
{

    /*
    [Intervalometer][stop]
    [Intervalometer][]
    [Intervalometer]
    
    [ManualTriggerControl][start]
    [ManualTriggerControl][stop]
    */
    int startIndex = 0;

    if (checkPrefix("ManualTriggerControl", startIndex))
    {
        startIndex = this->getNextPrefix("ManualTriggerControl", startIndex);

        if (checkPrefix("start", startIndex))
        {
            SerialControl::manualTriggerControl->setState(true);
            return;
        }

        if (checkPrefix("stop", startIndex))
        {
            SerialControl::manualTriggerControl->setState(false);
            return;
        }

        Log_Error("SerialControl", "Could not parse");
    }
    else if (checkPrefix("Intervalometer", startIndex))
    {
        startIndex = this->getNextPrefix("Intervalometer", startIndex);

        if (checkPrefix("stop", startIndex))
        {
            SerialControl::inveralometer->stop();
            return;
        }
        if (checkPrefix("start", startIndex))
        {
            SerialControl::inveralometer->start();
            return;
        }
        if (checkPrefix("break", startIndex))
        {
            String input = extractValue(currentStr, startIndex);
            if (!input)
            {
                Serial.println(input);
                Log_Error("SerialControl", "Could not parse value");
                return;
            }
            int parsedInput = input.toInt();
            SerialControl::inveralometer->setBreak(parsedInput);
            return;
        }
        // TODO Implement abort for intervalometer
        // TODO implement loopable timer
    }
}
