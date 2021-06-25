#include "motor.h"
#include "logger.h"
#include "conversions.h"

void Motor::init()
{
    Log_InitModule("Motor");

    pinMode(MOTOR_CS_PIN, OUTPUT);

    tmcDriver.begin();
    tmcDriver.rms_current(600); // Set stepper current to 600mA. The command is the same as command TMC2130.setCurrent(600, 0.11, 0.5);
    tmcDriver.en_pwm_mode(1);   // Enable extremely quiet stepping
    tmcDriver.pwm_autoscale(1);
    tmcDriver.microsteps(16);

    stepper.setPinsInverted(false, false, true);

    stepper.enableOutputs();
    stepper.move(200);

    Log_InitializedModule("Motor");
}

void Motor::loop()
{
    if (isMoving)
    {
        stepper.run();
    }
}

void Motor::setSpeed(double degPerMin)
{
    Log_Info("Motor", "SetSpeed");
    double stepsPerSec = DEG_TO_ARCSEC(degPerMin / 60.0);
    stepper.setSpeed(stepsPerSec);
    Motor::stepsPerSec = stepsPerSec;
}

void Motor::start()
{
    isMoving = true;
}

void Motor::stop()
{
    stepper.stop();
    isMoving = false;
}