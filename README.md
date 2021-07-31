# 3D-Printed-DIY-Joystick
A 3D-Printable Joystick for use with PC flight simulators
This model uses hall-effect sensors for high accuracy inputs into flight simulators. The Joystick features 3 axes of movement (Pitch, Roll, and Yaw), and one potentiometer mounted in the base to act as a Throttle input (but it can be used as trim as well). 606 Bearings are used on the pitch and roll axes for smooth operation and longevity. A steel rod is used as the pivot point for the yaw axis. Due to the number of buttons included in the joystick (24), 3 8-bit shift registers are used to reduce the output wire count to a more reasonable number. Everything is connected to an Arduino Pro Micro, which uses an Atmega 32u4 processor, which is capable of handling USB communications without additional hardware or software. This means that although this joystick is custom-built, it is compatible with any PC that accepts USB Game Controllers (and maybe some consoles as well).
An optional Throttle-Assembly has also been created. A joystick (and base) is simply mounted to the sliding carriage on the Throttle-Assembly, a single 3-pin wire is plugged into the joystick's base, and a switch is flipped. That is all it takes to swap from using the internal Throttle potentiometer to an external Throttle-Assembly.

Credit Goes To:
	Thingiverse user akaki for the original joystick model that I modified:  https://www.thingiverse.com/thing:4576634
	Thingiverse user droftarts for their OpenSCAD pulley generator:          https://www.thingiverse.com/thing:16627
	Thingiverse user Area51 for their GT2 Belt Clip:                         https://www.thingiverse.com/thing:2354961
	Matthew Heironimus for his Arduino Joystick library:                     https://github.com/MHeironimus/ArduinoJoystickLibrary
	Adafruit for their ADS11x5 Arduino Library which can be downloaded directly in the Arduino IDE



# Changes Made to Original Model
-The handle has been thinned drastically to allow for more space for the extra wires associated with 24 (instead of 6) buttons and 3 shift registers.
-The mounting pillar for the handle has been split with some wings added. The split allows the handle to be rotated in the yaw axis, and the wings allow for two arms to be mounted, with a spring in-between them to return the handle to 0 rotation.
-A hole has been cut in the bottom of the base to give additional clearance, as well as access, to the new yaw-axis hall-effect sensor.
-The front electronics section of the base has been doubled in length to give additional space for wiring as well as space for a 16-bit ADC (analog-to-digital converter) that is used in place of the 12-bit ADC built into the Arduino Pro Micro.
-3 holes have been added to the front of the front cover peice to act as posts to wrap the usb cable around and to tie it in-place with. This is opposed to just wrapping the USB cable around the handle.
-All holes intended for M3 bolts have been enlarged to allow for Brass M3 Threaded inserts to be inserted to allow for better bolt pull-out resistance as well as increased longevity of the bolt threads.
-Most tolerances between parts increased to between 0.4mm and 0.6mm
--My Version D is a modification to akaki's Version C, so a number of my parts retain the Version C label as they have been changed minorly at most



# Print Settings
I used a 0.4mm Nozzle with PETG at 30% infill on most of the parts. The only exceptions are the Button Caps, which are so thin that a 0.2mm Nozzle is required, and the joystick left and right side, which are quite thin compared to the original and should probably be printed at around 60% to 80% infill.
I used Silver for most of the parts, with the Button Caps being printed in Translucent Aqua, and the trigger and Hat cover being printed in Translucent Glittery Dark Blue (called Starry Night).



# Bill of Materials
	1 Joystick:
	1 Arduino Pro Micro
	1 ADS1115 (Optional: built in 12-bit ADC can be used instead)
	3 AH3503 Linear Hall-Effect Sensors
	1 15mm 10k 3 pin potentiometer
	24 10k Ohm Resistors (1 for each button, use a lower value is using active-low (button connects to ground) instead of active-high (button connects to VCC) button signals)
	3 74HC165 Parallel-to-Serial Shift Registers
	18 6mm*6mm Tactile Pushbutton Momentary Switches - Assorted button lengths
	1 SPDT Long Hinge Roller Arm Microswitch - Approximately 28mm*10mm*16mm
	1 10*10*9 6 pin 5-way Momentary Tactile Switch SMD (Optional) (A Nintendo Switch Replacement Joycon thumbstick might fit here instead (that would change the wiring fairly significantly, be aware)
	1 Micro USB to USB cable - Any length 4ft of longer
	1 5mm*65mm Steel Rod - Grind Flats as indicated in the 3D Model- Used as the Yaw-axis pivot
	1 M4*15 Button-Head Bolt (Can be substituted for any M4 head variant)
	1 M4*15 Cap-Head Bolt
	6 5mm*2mm Neodymium magnets
	2 4pin*2pin Dupont-Style Connectors and assosiated crimpable pins (Precrimped wires can also be used) - Other connector styles can also be used
	35 Brass M3 Threaded Inserts (Approximate number)
	4 606 Bearings (any variant)
	1 3pin Dupont-Style Connector and 3 crimpable pins (Precrimped is also acceptable) - The pins and holes combination is arbitrary - (Optional: Only Needed if Throttle-Assembly is built)
	1 3 position slide switch - single pole (double pole also works) (Optional: Only Needed if Throttle-Assembly is built)
	Assorted M3 Bolts (6mm, 8mm, 10mm, 16mm, 25mm Recommended)
	Pin headers for use with Arduino and ADS1115 (Optional)
	Wire of Assorted Colors (I used 22awg)
	Heatshrink of Assorted Sizes
	Thin Steel Sheet strips - Must be ferromagnetic (Can be obtained by cutting up the bottom of a Pringles can)
	5-minute Epoxy
	Isopropal Alcohol
	Mini Hot Glue Gun and Glue Sticks (Regular size also works, but not as easy to fit everywhere)
	Wire Strippers (Optional, but highly recommended)
	~400g of filament
	
---Printed Parts---
	Base (Version D):
		1 axis_for_ver_C v3
		1 base_cover
		1 Bottom
		1 cable cap
		1 cam_arm
		1 hinge_cam
		1 hinge_cam_slider_for_ver_C v3
		1 hinge_ver_C_-_17x6_mm_bearings v3
		1 Mount Base
		1 Top
		1 trim knob (Optional)
		1 Wire Storage Clip or Wire Storage Clip Hook (Optional)
		1 Yaw Rod Retention Clip
		2 Yaw Spring 2
		4 M4 Bearing Spacers
	
	Handle:
		1 5-way button spacer (Optional)
		6 Button Cap Body - Print with 0.2mm Nozzle
		12 Button Cap Face - Print with 0.2mm Nozzle
		1 Face Plate
		1 joystick_grip_left_side v2 - with Left Side Handle Insert lined up, as seen in joystick grip left side filled.3mf
		1 joystick_grip_right_side v2
		1 Stadium Hat or Trim Hat
		1 trigger


Throttle-Assembly Only:
	2 8mm*330mm Steel Rods
	4 8mm*15mm*45mm Linear Bearings (Shorter bearings are also compatible, only 2 are necessary)
	4 606 Bearings (any variant)
	1 15mm 10k 3 pin potentiometer
	3 3mm*300mm Steel Rods (Optional: Recommended, but not needed if base is printed in 2 pieces)
	1 1m GT2 Timing Belt
	2 M3*35mm Bolts
	10 M3*10mm Bolts
	10 M3 Washers
	1 70mm Closed Loop MXL Belt - Can be subsituted for another type of belt, ideally a closed loop of about this length or slightly longer
	~600g of filament
	
---Printed Parts---
Fit Test:
	1 Base - Ensure the 8mm*330mm Steel Rods fit
	1 Mount - Ensure the 8mm*15mm*45mm Linear Bearings Fit
	
Build:
	4 Adjustable Bearing Pillow Block v2
	1 Adjustable Pot Mount
	1 Base 1
	1 Base 2
	1 Cover 1
	1 Cover 2
	1 Belt Pin Spacer
	1 Drive Axle
	1 Idler Axle (lower into print bed to create a flat side for better printing reliability)
	1 Mount
	1 Mount Side
  Imported Parts:
	2 X-Belt-Holder-Thin-GT2
	2 GT2 2mm 6mm Wide 50 Tooth Idler M4 Shaft  (Sample - Generate and Test your own to ensure they fit your belt and Drive Axle and Idler Axle)
	1 40T 2.75mm MXL Pulley for Pot  (Sample - Generate and Test your own to ensure they fit your belt and potentiometer)
	1 20T 2.75mm MXL Pulley  (Sample - Generate and Test your own to ensure they fit your belt and Drive Axle)
			Use the OpenSCAD pulley generator for these 4 pulleys, using about the same size for all and the 2:1 gear ratio for the potentiometer. More drastic changes will require the model to be reworked.
			


# Build Guides:
Check out the videos I made for the major steps of the build as well as tips while building.
Check out the BuildSteps.md file for more step-by-step instructions with fewer pictures.
Check out my Calibration Guide video to learn how to calibrate your own joystick using the code I wrote.
	Use the Sample Code provided and modify as needed to test and program your Arduino Pro Micro(s)
	--My Joysticks' code is included for reference purposes only and is not written to be modified as easily



# Project Videos:
Project Overview:                                                 https://youtu.be/krna4ZIIvYI
Chair Mounting Solution and Throttle-Assembly Build Explanation:  https://youtu.be/rQSjNkJ6G9A
Joystick Approximate Build Guide:                                 https://youtu.be/sCnEafJgWUY
Joystick Calibration Guide:                                       https://youtu.be/MGDJYMHP4_0
Full Build Timelapse (5x Real Speed):                             https://youtu.be/Amg51pNDD08

Elite Dangerous Sample Gameplay Using My Joysticks:
	Bounty Hunting:                                https://youtu.be/YqyOV4E18Ls
	Mining:                                        https://youtu.be/bz7r8q-hPg0
	Traveling Between Systems:                     https://youtu.be/_PC3MqTWRCQ
	-Vulture Ship Outfitting (bounty hunting):     https://youtu.be/YhuHz4nPciU
	-Anaconda Ship Outfitting (mining):            https://youtu.be/gqCUKOQVyXI