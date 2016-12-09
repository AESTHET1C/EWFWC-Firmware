OVERVIEW

The Eli Whitney Ferris Wheel Controller ("EWFWC") is an ATmega 328P-powered board that attaches to the bottom of the ferris wheel module within the Eli Whitney Museum's seasonal train display and controls various features of the module. It is intended to be run from a single 12 volt power source. The EWFWC is intended to control the following elements of the ferris wheel module:

+ Activate features only when a button is pressed by the public
+ Rotate the ferris wheel
+ Rotate a disc that simulates an excited crowd
+ Flash two sets of LEDs in an alternating pattern
+ Play music and/or sound effects

Additionally, the EWFWC has an on-board LED to display status and error codes to the staff in the event of a malfunction.


#Capabilities

The EWFWC contains a socketed Adafruit Pro Trinket 5V and Nuvoton ISD1740 for ease of programming and debugging. It uses several MOSFETs to drive high-power loads and a bipolar H-bridge to offer a reversible output. The EWFWC features the following elements:

+ Two high-power, PWM-capable, non-reversible outputs
+ One reversible output
+ One speaker output, with up to approximately 25 seconds of pre-recorded sounds
+ One general-purpose input/output (GPIO)
+ One on-board LED

The two high-power outputs contain snubber diodes to prevent voltage spikes when powering reactive loads.


#Connectivity

**Note:** This section assumes connector contacts and housings are purchased separately.

With the exception of the power connector, the EWFWC interfaces with all inputs and outputs through gold-plated 0.1"-pitch male headers. It is suggested to use only high-normal-force, gold-plated female contacts (Molex 16-02-1124 or 16-02-1125) to prevent failures or degraded performance due to vibration or oxidation. Other suitable contacts can be found in the Molex 71851 product series.

The two high-power outputs feature shrouded right-angle headers with latch holders (Molex 70553-0001). While standard non-polarized connectors will fit, it is suggested to use a latched housing (Molex 50-57-9402). 24 AWG (or thicker) wire should be used with these connectors due to current draw.

The remaining connections (left to right: GPIO, reversible output, speaker) share a standard 3x2 right-angle header, where each pin belongs to a vertical pair. On the GPIO pair, the top pin is an unbuffered connection to the ATmega 328P and the lower pin is ground. To utilize all three pairs, standard non-polarized housings (Molex 50-57-9002) should be used.


#Power Supply and Ratings

While intended to be run from a 12 volt supply, the EWFWC is capable of being run from any voltage between approximately 5.5 and 16 volts. The two high-power outputs and H-bridge use this voltage, while the GPIO connection is 5 volt logic via an internal regulator.

The two high-power outputs are rated for 3 amps of continuous current. The GPIO output is rated for a continuous 40 milliamps. The H-bridge is rated for a continuous 150 milliamps.  Peak currents are not rated.