#include "error.h"

bool Error_Status;
unsigned long Error_Tick_Start = 0;

void initErrors() {
	setError(false);
	pinMode(ERROR_PIN, OUTPUT);
	return;
}

void handleErrorCodeDisplay() {
	unsigned int Tick_Elapsed_Time = millis() - Error_Tick_Start;

	if(Tick_Elapsed_Time >= ERROR_TICK_TIME) {
		if(Error_Status) {
			digitalWrite(ERROR_PIN, HIGH);
		}
		Error_Tick_Start = millis();
	}
	else if(Tick_Elapsed_Time >= ERROR_BLINK_TIME) {
		digitalWrite(ERROR_PIN, LOW);
	}
	return;
}

void setError(bool status) {
	Error_Status = status;
	return;
}
