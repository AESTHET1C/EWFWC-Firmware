/* Error Module
 *
 * Used to initialize and control the status LED on the EWFWC hardware to show an error state
 *
 * When enabled, an error code is displayed by constantly blinking the status LED.
 *
 * Each error code blink is displayed within a "tick". Each tick lasts for ERROR_TICK_TIME milliseconds.
 * Within each tick, the LED is enabled for the first ERROR_BLINK_TIME milliseconds.
 *
 * |_________           |_________           |
 * |         |__________|         |__________| and so on...
 *  --blink--            --blink--
 *  --------tick-------- --------tick--------
 *
 * Written by Alex Tavares <tavaresa13@gmail.com>
 */

#ifndef error_h
#define error_h
#include <arduino.h>

/////////////////////////
// CONFIGURATION VARIABLES
/////////////////////////

const unsigned int ERROR_TICK_TIME = 250;
const unsigned int ERROR_BLINK_TIME = 100;


/////////////////////////
// PIN DEFINITIONS
/////////////////////////

const byte ERROR_PIN = 13;


/////////////////////////
// AVAILABLE FUNCTIONS
/////////////////////////

void initErrors();
/*
 * Initializes error code handling
 * Must be called at startup
 *
 * Initialization involves setting status variable and pin configuration.
 *
 * Affects Error_Status
 */

void handleErrorCodeDisplay();
/*
 * Updates the EWFWC status LED to display error status
 * Must be placed within a loop that executes regularly
 *
 * Affects Error_Tick_Start
 */

void setError(bool status);
/*
 * Flags or clears error status
 *
 * Affects Error_Status
 * INPUT:  New error status
 */


#endif
