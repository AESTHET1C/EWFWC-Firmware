/* ISD1700 Handler Module
 *
 * Used to initialize, manage, and communicate with the ISD1700 chip
 *
 * This includes configuring pins on startup, sending SPI commands,
 * and keeping track of playback state.
 *
 * Written by Alex Tavares <tavaresa13@gmail.com>
 */

#ifndef audio_h
#define audio_h
#include <arduino.h>

/////////////////////////
// CONFIGURATION VARIABLES
/////////////////////////

// Audio clip durations
const unsigned int AUDIO_DURATION[1] = {
	24657
};


/////////////////////////
// PIN DEFINITIONS
/////////////////////////

const byte SPI_SCLK_PIN = 0;
const byte SPI_MOSI_PIN = 1;
const byte SPI_SS_PIN = 8;


/////////////////////////
// ENUMERATIONS
/////////////////////////

// Available audio clips
typedef enum {
	AUDIO_MUSIC = 0
} audio_clip;

/////////////////////////
// ISD1700 CONSTANTS
/////////////////////////

const byte ISD_POWER_UP_DELAY = 100;

// Commands list
const byte ISD_PU = 0x01;
const byte ISD_WR_APC2 = 0x65;
const byte ISD_SET_PLAY = 0x80;

// Configuration data
const uint16_t ISD_APC_DEFAULT_CONFIG = ((B00000100 << 8) + B10100010);

// Audio pointer arrays
const uint16_t ISD_AUDIO_START_PTR[1] = {
	0x010
};
const uint16_t ISD_AUDIO_STOP_PTR[1] = {
	0x0F4
};


/////////////////////////
// AVAILABLE FUNCTIONS
/////////////////////////

void initAudio();
/*
 * Initializes audio playback
 * Must be called at startup
 *
 * Initialization involves setting status variables and pin configurations.
 * The ISD1700 configuration register is also set.
 *
 * Affects Audio_Playing
 */

void playAudio(audio_clip sound);
/*
 * Plays an audio clip without blocking additional code from running
 *
 * Affects Audio_Start Audio_Duration, and Audio_Playing
 * INPUT:  Clip to play
 */

bool audioPlaying();
/*
 * Gets the status of audio playback
 *
 * Affects Audio_Playing
 * OUTPUT: State of audio playing
 */


/////////////////////////
// INTERNAL FUNCTIONS
/////////////////////////

void configAudio(uint16_t configuration);
/*
 * Configures the ISD1700 device
 * Can be used to change volume
 *
 * INPUT:  configuration bytes to use
 */

void sendByte(uint8_t transmission);
/*
 * Sends a single byte via SPI to the ISD1700
 * SPI_SS pin must still be manually set before and after a command
 *
 * INPUT:  Byte to transmit
 */

byte getByte(uint16_t input, byte byteSelect);
/*
 * Gets a single byte out of a two-byte input
 * Used with sendByte() to send SPI commands to the ISD1700
 *
 * INPUT:  Two-byte input
 *         Selection of output byte (0-indexed)
 * OUTPUT: Selected byte
 */


#endif
