#Overview of the Firmware

The Eli Whitney Ferris Wheel Controller ("EWFWC") is an ATmega 328P-powered board that attaches to the bottom of the ferris wheel module within the Eli Whitney Museum's seasonal train display and controls various features of the module. The EWFWC Firmware is specific to both the EWFWC board and the ferris wheel module itself. It allows public interaction with the ferris wheel module in the following ways:

+ Offer a single arcade button for the public to press
+ Begin playing music when the arcade button is pressed
+ Start the following process when the arcade button is pressed*:
	+ Rotate the ferris wheel for 7 seconds
	+ Move the fake crowd for 2 seconds when the ferris wheel stops moving
+ Flash two colors of LEDs on the ferris wheel in an alternating pattern during this process
+ Repeat this process until the music ends and the arcade button is released
+ Repeatedly loop the music as needed, with a 5 second gap between playback
+ Continue these actions uninterrupted so long as the arcade button is being pressed

*As of 2016, the fake crowd is unused and therefore the wheel rotates uninterrupted

The Firmware also features a brief self-check on startup to prevent short circuits on the LED circuit. In the event that a short is detected, the Firmware will disable the operation of the LEDs and display an error code on the EWFWC board's LED.


#Setup Checklist

This checklist assumes the EWFWC board is already screwed to the bottom of the ferris wheel module and that both motors are already plugged into the board, in addition to the speaker, LEDs, and button connectors. For information on electrical cennections and their locations, see "**Wiring Connections**".

---

- [ ] Plug in connector D5 to the train table and apply power
- [ ] Verify the self-check routine does not fail (See "**Startup Self-Check**")


#Startup Self-Check

**Note:** As of 2016, the self check should never fail, as the wheel LEDs are unused. This section may be ignored.

Due to the wiring method of the wheel LEDs, the Firmware must verify that no accidental shorts are made between the frame and ground. To do this, a quick (2-second) and automated self-check sequence occurs on power-up. This check involves attempting to power the LEDs in both polarities and detecting if a brown-out reset is caused. The sequence also accounts for standard supply noise.

If the LEDs are found to be shorted, the status (red) LED on the EWFWC board will continuously flash to indicate an error. Normal operation of the Firmware continues with the LED output disabled. This error state can be cleared by removing the short and resetting the EWFWC board.


#Wiring Connections

**Note:** As of 2016, the crowd motor and wheel LEDs are unused. These positions should not have anything plugged in to them.

The two motor connections are located on the bottom right of the EWFWC board. From left to right, they are:

+ Ferris wheel motor
+ Crowd motor

The three low-power connections are located on the bottom left of the EWFWC board. From left to right, they are:

+ Arcade button
+ Wheel LEDs
+ Speaker

These low-power connections are in non-polarized vertical pairs. Attaching connectors horizontally may cause damage to the EWFWC board.