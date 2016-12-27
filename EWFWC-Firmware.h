/* EWMC Firmware
 *
 * Allows for interactive control of the Ferris wheel module
 *
 * See the EWFWC Firmware documentation for details.
 *
 * Written by Alex Tavares <tavaresa13@gmail.com>
 */

#ifndef main_h
#define main_h
#include <arduino.h>
#include <EEPROM.h>
#include "modules/power.h"
#include "modules/error.h"
#include "modules/audio.h"

/////////////////////////
// CONFIGURATION VARIABLES
/////////////////////////

const unsigned int MOTOR_CYCLE_TIME[2] = {7000, 0};
const unsigned int LED_CYCLE_TIME = 1000;
const unsigned int AUDIO_COOLDOWN_DELAY = 5000;

// Startup check values
const unsigned int CHECK_DELAY[3] = {500, 250, 250};
const uint16_t EEPROM_TESTING_PTR = 0x000;


/////////////////////////
// PIN DEFINITIONS
/////////////////////////

const byte BUTTON_PIN = 12;


/////////////////////////
// ENUMERATIONS
/////////////////////////

// Audio operation states
typedef enum {
	IDLE,
	COOLDOWN,
	PLAY
} audio_state;


/////////////////////////
// INTERNAL FUNCTIONS
/////////////////////////

void setup();
/*
 * Initializes all modules and runs startup check
 * Runs automatically on program startup
 *
 * Once check is complete, the main program loop begins.
 */

void loop();
/*
 * Handles the main state machines
 * Automatically loops endlessly after setup()
 *
 * Operation of the LEDs, motors, and audio are handled as three devices. Changes in LED state are
 * determined by the current state of the motors, and changes in motor state are determined by
 * either the current state of audio playback or the arcade button.
 */