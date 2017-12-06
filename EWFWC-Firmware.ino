#include "EWFWC-Firmware.h"

// Audio state variables
audio_state Audio_State = IDLE;
unsigned long Audio_Delay_Start = 0;

void setup() {

	// Do some basic MCU initialization
	pinMode(BUTTON_PIN, INPUT_PULLUP);
	initAudio();
	initError();
	initPowerOutputs();

	// Startup self-check routine
	if(EEPROM.read(EEPROM_TESTING_PTR)) {       // Warm boot; test failed
		disableLEDOutput();
		setError(true);
		EEPROM.write(EEPROM_TESTING_PTR, false);
	}
	else {																			// Cold boot; begin test
		delay(CHECK_DELAY[0]);
		EEPROM.write(EEPROM_TESTING_PTR, true);
		setLEDOutput(true);
		delay(CHECK_DELAY[1]);
		reverseLEDOutput();
		delay(CHECK_DELAY[2]);
		EEPROM.write(EEPROM_TESTING_PTR, false);
		setLEDOutput(false);
	}
}

void loop() {
	if(!digitalRead(BUTTON_PIN)) {
		bool Module_Active = true;    // Ferris wheel module is currently moving

		motor_group Active_Motor = WHEEL_MOTOR;
		unsigned long Motor_Cycle_Start = millis();

		unsigned long LED_Cycle_Start = Motor_Cycle_Start;

		setLEDOutput(true);
		setMotorOutput(Active_Motor, true);
		while(Module_Active) {
			bool Audio_Playing_Temp = audioPlaying();

			if(!Audio_Playing_Temp) {
				switch(Audio_State) {
					default:
					case IDLE: {
						if(!digitalRead(BUTTON_PIN)) {
							playAudio(AUDIO_MUSIC);
							Audio_State = PLAY;
						}
						break;
					}
					case COOLDOWN: {
						if((millis() - Audio_Delay_Start) >= AUDIO_COOLDOWN_DELAY) {
							Audio_State = IDLE;
						}
						break;
					}
					case PLAY: {
						Audio_State = COOLDOWN;
						Audio_Delay_Start = millis();
						break;
					}
				}
			}
			if((millis() - Motor_Cycle_Start) >= MOTOR_CYCLE_TIME[Active_Motor]) {
				if(Audio_Playing_Temp || (!digitalRead(BUTTON_PIN))) {
					switch(Active_Motor) {
						default:
						case WHEEL_MOTOR: {
							setMotorOutput(WHEEL_MOTOR, false);
							setMotorOutput(CROWD_MOTOR, true);
							Active_Motor = CROWD_MOTOR;
							Motor_Cycle_Start = millis();
							break;
						}
						case CROWD_MOTOR: {
							setMotorOutput(CROWD_MOTOR, false);
							setMotorOutput(WHEEL_MOTOR, true);
							Active_Motor = WHEEL_MOTOR;
							Motor_Cycle_Start = millis();
							break;
						}
					}
				}
				else {
					setMotorOutput(Active_Motor, false);
					Module_Active = false;
				}
			}
			if(Module_Active && ((millis() - LED_Cycle_Start) >= LED_CYCLE_TIME)) {
				reverseLEDOutput();
				LED_Cycle_Start += LED_CYCLE_TIME;
			}
			handleErrorCodeDisplay();
		}

		while((millis() - LED_Cycle_Start) < LED_CYCLE_TIME) {
			handleErrorCodeDisplay();
		}
		setLEDOutput(false);
	}
	handleErrorCodeDisplay();
}
