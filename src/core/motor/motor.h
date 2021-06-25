#include "AccelStepper.h"
#include "TMCStepper.h"
#include "config/pin_configurations.h"
#include "abstractions/module.h"

#define STEP_DIRECTION = 1.0;
#define STEPS_PER_STEP = 16.0;
#define STEPS_PER_TURN = 200.0 * STEPS_PER_STEP;
#define GEARHEAD_RATIO = 3.0;
#define WORMDRIVE_RATIO = 144.0;
#define ARCSECS_PER_ROTATION = 3600 * 360;
#define STEPS_PER_FULL_ROTATION = (GEARHEAD_RATIO * WORMDRIVE_RATIO * STEPS_PER_TURN);
#define STEPS_PER_ARC_SEC = STEPS_PER_FULL_ROTATION / ARCSECS_PER_ROTATION;
#define STEPS_PER_DEG = STEPS_PER_ARC_SEC * ;
#define TRACKING_SPEED_SIDERIAL_PER_SECOND = 15.041;
#define TRACKING_SPEED_LUNAR_PER_SECOND = 14.685;
#define TRACKING_SPEED_SOLAR_PER_SECOND = 15.0;
#define DEFAULT_TRACKING_SPEED = TRACKING_SPEED_SIDERIAL_PER_SECOND * STEPS_PER_ARC_SEC;

#define R_SENSE 0.11f

class Motor : public Module
{
    boolean isMoving = false;
    double stepsPerSec = 0;

    AccelStepper stepper = AccelStepper(AccelStepper::DRIVER, MOTOR_STEP_PIN, MOTOR_DIR_PIN);
    TMC2130Stepper tmcDriver = TMC2130Stepper(MOTOR_CS_PIN, R_SENSE, MOTOR_SDI_PIN, MOTOR_SDO_PIN, MOTOR_SCK_PIN);

public:
    void setSpeed(double degPerMin);
    void moveDegrees(double degrees);

    void start();
    void stop();

    void init();
    void loop();
};
