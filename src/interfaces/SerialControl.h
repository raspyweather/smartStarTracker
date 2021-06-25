#include <Arduino.h>
#include "abstractions/module.h"
#include "features/Intervalometer.h"
#include "features/ManualTriggerControl.h"
#include "logger.h"

class SerialControl : public Module
{
private:
    Intervalometer* inveralometer;
    ManualTriggerControl* manualTriggerControl;

    String currentStr;
    int currentSize;
    int maxSize = 250;
    void tryParse();
    bool checkPrefix(String prefix, int startIndex);
    int getNextPrefix(String prefix, int startIndex);
    String extractValue(String input, int startIndex);
    ulong extractAndParseValue(String input, int startIndex);

public:
    SerialControl(Intervalometer* intervalometer, ManualTriggerControl* manualTriggerControl)
    {
        this->inveralometer = intervalometer;
        this->manualTriggerControl = manualTriggerControl;
    }

    void init();
    void loop();
};
