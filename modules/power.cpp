#include "power.h"

bool Motor_Status_Enabled[2];

bool LED_Status_Enabled = true;
led_dir LED_Status_Direction = DIR_A;

void initPowerOutputs() {

	// Prepare outputs
	setMotorOutput(WHEEL_MOTOR, false);
	setMotorOutput(CROWD_MOTOR, false);
	setLEDOutput(false);

	// Configure PWM registers
	TCCR1A = B10100001;
	TCCR1B = B00000100;

	// Drive output pins
	pinMode(MOTOR_PIN[WHEEL_MOTOR], OUTPUT);
	pinMode(MOTOR_PIN[CROWD_MOTOR], OUTPUT);
	pinMode(LED_PIN[0], OUTPUT);
	pinMode(LED_PIN[1], OUTPUT);

	return;
}

void setMotorOutput(motor_group motor, bool enable) {
	switch(motor) {
		case WHEEL_MOTOR:
			OCR1BL = (enable ? PWM_SPEED[WHEEL_MOTOR] : 0);
			break;
		case CROWD_MOTOR:
			OCR1AL = (enable ? PWM_SPEED[CROWD_MOTOR] : 0);
			break;
		default:
			break;
	}
	return;
}

void setLEDOutput(bool enable) {
	if(enable && LED_Status_Enabled) {
		digitalWrite(LED_PIN[1], LOW);                              // Disable first to prevent shorting
		digitalWrite(LED_PIN[0], (LED_Status_Direction == DIR_A));
		digitalWrite(LED_PIN[1], (LED_Status_Direction == DIR_B));
	}
	else {
		digitalWrite(LED_PIN[0], LOW);
		digitalWrite(LED_PIN[1], LOW);
	}
	return;
}

void reverseLEDOutput() {
	if(LED_Status_Direction == DIR_A) {
		LED_Status_Direction = DIR_B;
	}
	else {
		LED_Status_Direction = DIR_A;
	}
	setLEDOutput(true);
	return;
}

void disableLEDOutput() {
	LED_Status_Enabled = false;
	setLEDOutput(false);
	return;
}
