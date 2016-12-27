/* Power Output Handling Module
 *
 * Used to initialize, control, and manage the power output capabilities of the EWFWC hardware
 *
 * This includes one bidirectional output for LEDs, and two unidirectional PWM-enabled outputs for
 * the wheel and crowd motors.
 *
 * Functionality is built in for easy disabling of LEDs until reset. Upon disabling LED outputs,
 * attempts to change LED state will be ignored.
 *
 * Written by Alex Tavares <tavaresa13@gmail.com>
 */

#ifndef power_h
#define power_h
#include <arduino.h>

/////////////////////////
// CONFIGURATION VARIABLES
/////////////////////////

// PWM presets
const uint8_t PWM_SPEED[2] = {255, 255};


/////////////////////////
// PIN DEFINITIONS
/////////////////////////

const byte MOTOR_PIN[2] = {10, 9};
const byte LED_PIN[2] = {6, 5};


/////////////////////////
// ENUMERATIONS
/////////////////////////

typedef enum {
	WHEEL_MOTOR = 0,
	CROWD_MOTOR = 1
} motor_group;

typedef enum {
	DIR_A,
	DIR_B
} led_dir;


/////////////////////////
// AVAILABLE FUNCTIONS
/////////////////////////

void initPowerOutputs();
/*
 * Initializes all three power outputs
 * Must be called at startup
 *
 * Initialization involves setting status variables and pin configuration.
 *
 * Affects Motor_Status_Enabled[] and LED_Status_Enabled
 */

void setMotorOutput(motor_group motor, bool enable);
/*
 * Enables or disables a motor output
 *
 * Affects Motor_Status_Enabled[]
 * INPUT:  Motor in question (0-indexed)
 *         State of being enabled
 */

void setLEDOutput(bool enable);
/*
 * Enables or disables LED output
 *
 * Affects LED_Status_Enabled
 * INPUT: State of being enabled
 */

void reverseLEDOutput();
/*
 * Reverses the polarity of the LED output
 *
 * Affects LED_Status_Direction
 */

void disableLEDOutput();
/*
 * Disables the LED output until reset
 *
 * Calls to setLEDOutput() will be ignored after disabling LEDs.
 *
 * Affects LED_Disabled and LED_Status_Enabled
 */


#endif
