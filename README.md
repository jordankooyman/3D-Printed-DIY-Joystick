# 3D-Printed DIY Joystick
A 3D-Printable Joystick for use with PC flight simulators
![Throttle Joystick Side Videw](https://user-images.githubusercontent.com/62574509/198843605-3d08749d-ac97-4a73-a574-a6bc1cc1a229.png)


Updated!
New arduino code has been included in the code folder that should be much more reliable and easier to modify and work with.

This model uses hall-effect sensors for high accuracy inputs into flight simulators. The Joystick features 3 axes of movement (Pitch, Roll, and Yaw), and one potentiometer mounted in the base to act as a Throttle input (but it can be used as trim as well). 606 Bearings are used on the pitch and roll axes for smooth operation and longevity. A steel rod is used as the pivot point for the yaw axis. Due to the number of buttons included in the joystick (24), 3 8-bit shift registers are used to reduce the output wire count to a more reasonable number. Everything is connected to an Arduino Pro Micro, which uses an Atmega 32u4 processor, which is capable of handling USB communications without additional hardware or software. This means that although this joystick is custom-built, it is compatible with any PC that accepts USB Game Controllers (and maybe some consoles as well).

I have also created an optional Throttle-Assembly. To use it, a joystick can be mounted onto the sliding carriage on the Throttle-Assembly and a 3-pin-wire can be plugged into the joystick from the Throttle-Assembly, and a switch can be flipped on the joystick base to enable the external throttle input instead of the internal throttle input.


Overall, I spent about $175 on this project, but I had some of the parts on hand and I bought others in larger-than-necessary quantities. Depending on where and when your buy your parts  (and exactly what you intend to build), you overall cost will vary significantly.



-- This is NOT a beginner-friendly project as this is still an early prototype with some convoluted assembly --



# Credit Goes To:
Thingiverse user akaki for the original joystick model that I modified:		https://www.thingiverse.com/thing:4576634

Thingiverse user droftarts for their OpenSCAD pulley generator:				https://www.thingiverse.com/thing:16627

Thingiverse user Area51 for their GT2 Belt Clip:							https://www.thingiverse.com/thing:2354961

Matthew Heironimus for his Arduino Joystick library:						https://github.com/MHeironimus/ArduinoJoystickLibrary

Adafruit for their ADS11x5 Arduino Library which can be downloaded directly in the Arduino IDE



# Changes Made to Original Model
- The handle has been thinned drastically to allow for more space for the extra wires associated with 24 (instead of 6) buttons and 3 shift registers.

- The mounting pillar for the handle has been split with some wings added. The split allows the handle to be rotated in the yaw axis, and the wings allow for two arms to be mounted, with a spring in-between them to return the handle to 0 rotation.

- A hole has been cut in the bottom of the base to give additional clearance, as well as access, to the new yaw-axis hall-effect sensor.

- The front electronics section of the base has been doubled in length to give additional space for wiring as well as space for a 16-bit ADC (analog-to-digital converter) that is used in place of the 12-bit ADC built into the Arduino Pro Micro.

- 3 holes have been added to the front of the front cover peice to act as posts to wrap the usb cable around and to tie it in-place with. This is opposed to just wrapping the USB cable around the handle.

- All holes intended for M3 bolts have been enlarged to allow for Brass M3 Threaded inserts to be inserted to allow for better bolt pull-out resistance as well as increased longevity of the bolt threads.

- Most tolerances between parts increased to between 0.4mm and 0.6mm

- My Version D is a modification to akaki's Version C, so a number of my parts retain the Version C label as they have been changed minorly at most


# Code Configuration
The sample code is based on my right joystick code, which has one of the 4 hat switch inputs on the lower shift register. The reference code for the left joystick does not have this.
The same applies to the new V4.0 code as well. The new calibration process is very similiar to the old one, but it should be much more reliable and quicker.



# Print Settings
I used a 0.4mm Nozzle with PETG at 30% infill on most of the parts. The only exceptions are the Button Caps, which are so thin that a 0.2mm Nozzle is required, and the joystick left and right side, which are quite thin compared to the original and should probably be printed at around 60% to 80% infill.

Supports were enabled for all parts, but only touching the build plate. I used Cura's Tree Supports to reach most overhangs. Unless your support settings are tuned such that supports on top of printed parts peel off extremely easily, do not print supports on the parts, only on the build plate. Otherwise, you will likely need to use a rotary tool (such as a dremel) to remove them all.

I used Silver for most of the parts, with the Button Caps being printed in Translucent Aqua, and the trigger and Hat cover being printed in Translucent Glittery Dark Blue (called Starry Night).



# Joystick (Handle and Base) Bill of Materials
	1 Joystick:
	1 Arduino Pro Micro (Must have a ATmega 32u4 processor)(if pin headers are not already soldered in, I recommended soldering them to point up rather than down)
	1 ADS1115 (Optional: built in 12-bit ADC can be used instead)
	3 AH3503 Linear Hall-Effect Sensors
	1 15mm 10k 3 pin potentiometer with washer and nut
	24 10k Ohm Resistors (1 for each button, use a lower value is using active-low (button connects to ground) instead of active-high (button connects to VCC) button signals)
	2 4.7k Ohm Resistors (Optional: Only needed if using ADS1115 or similar board that uses I2C)
	3 74HC165 Parallel-to-Serial Shift Registers
	18 6mm*6mm Tactile Pushbutton Momentary Switches - Assorted button lengths
	1 SPDT Long Hinge Roller Arm Microswitch - Approximately 28mm*10mm*16mm
	1 10*10*9 6 pin 5-way Momentary Tactile Switch SMD (Optional) (A Nintendo Switch Replacement Joycon thumbstick might fit here instead (that would change the wiring fairly significantly, be aware)
	1 Micro USB to USB cable - Any length 4ft of longer
	1 5mm*65mm Steel Rod (Aluminum or Brass also acceptable)- Grind Flats as indicated in the 3D Model- Used as the Yaw-axis pivot
	2 M4*15 Socket-Head Bolt (Can be substituted for any M4 head variant)
	1 M4*15 Button-Head Bolt
	2 M4 Hex Nuts
	6 5mm*2mm round Neodymium magnets
	2 4pin*2pin Dupont-Style Connectors and assosiated crimpable pins (Precrimped wires can also be used) - Other connector styles can also be used
	2 M2*4mm Bolts (Optional: Only needed if installing external throttle input)
	17 Brass M3 Threaded Inserts - 6mm tall, 5mm diameter (use about 200 degrees C on soldering iron to press in)
	4 606 Bearings (any variant)
	1 3pin Dupont-Style Connector and 3 crimpable pins (Precrimped is also acceptable) - The pins and holes combination is arbitrary - (Optional: Only Needed if Throttle-Assembly is built)
	1 3 position slide switch - single pole (double pole also works) (Optional: Only Needed if Throttle-Assembly is built)
	Assorted M3 Bolts (6mm, 8mm, 10mm, 16mm, 25mm Recommended) Hex Socket Head recommended
	Assorted small extension springs (larger than pen springs, however)
	Pin headers for use with Arduino and ADS1115 (Optional)
	Wire of Assorted Colors (I used 22awg)
	Heatshrink of Assorted Sizes
	Thin Steel Sheet strips - Must be ferromagnetic (Can be obtained by cutting up the bottom of a Pringles can)
	5-minute Epoxy
	Isopropyl Alcohol
	Super Glue
	Disposable Rubber Gloves (Optional but recommended
	
	Rotary Tool (or some other way to cut steel (or your choosen metal shaft material))
	Mini Hot Glue Gun and Glue Sticks (Regular size also works, but not as easy to fit everywhere)
	Dupont-Style Crimping Tool
	Soldering Iron
	Tip for Soldering Iron that fits in the M3 inserts without sticking out the other end - expect to get plastic on this
	Wire Strippers (Optional, but highly recommended)
	Multimeter with continuinty testing (Optional, but highly recommended)
	~400g of filament
	
   # Printed Parts - Joystick
	Base (Version D):
		1 axis_for_ver_D v3  --  Print Flat
		1 base_cover  --  Print Front-Down
		1 Bottom  --  Print with wings down
		1 cable cap  --  Print Vertical, longest continuous side down
		1 cam_arm  --  Print Flat
		1 hinge_cam  --  Print Flat
		1 hinge_cam_slider_for_ver_C v3  --  Print Flat
		1 hinge_ver_D_-_606_bearings v3  --  Print Flat
		1 Mount Base  --  Print Bottom-Down
		1 Top  --  Print Tall with lengthwise hole facing up
		1 trim knob (Optional)
		1 Wire Storage Clip or Wire Storage Clip Hook (Optional)  --  Print Flat
		1 Yaw Rod Retention Clip  --  Print Flat
		2 Yaw Spring 2  --  Print Flat
		2 M4 Bearing Spacers  --  Print Flang-Down
	
	Handle:
		1 5-way button spacer (Optional)
		6 Button Cap Body - Print with 0.2mm Nozzle - Print Spares  --  Print Opening-Up
		12 Button Cap Face - Print with 0.2mm Nozzle - Print Spares  --  Print Opening-Up
		1 Face Plate  --  Print Rounded-Edge-Down
		1 joystick_grip_left_side v2 - with Left Side Handle Insert lined up, as seen in joystick grip left side filled.3mf  --  Print with hollow inside down
			- Mirror this part to make a left handle instead of a right handle
		1 joystick_grip_right_side v2  --  Print with hollow inside down
			- Mirror this part to make a left handle instead of a right handle
		1 Stadium Hat or Trim Hat  --  Print with short stem down
		1 trigger  --  Print Side-Down


# Throttle-Assembly Bill of Materials: - Requires Joystick to Use
	2 8mm*330mm Steel Rods - must be perfectly straight
	4 8mm*15mm*45mm Linear Bearings (shorter bearings are also compatible, and only 2 are necessary, but Mount will need to be redesigned)
	4 606 Bearings (any variant)
	1 15mm 10k 3 pin potentiometer with washer and nut
	3 3mm*300mm Steel Rods (other metals also acceptable) (Optional: Recommended, but not needed if base is printed in 2 pieces)
	1 1m GT2 Timing Belt
	16 Brass M3 Threaded Inserts - 6mm tall, 5mm diameter (use about 200 degrees C on soldering iron to press in)
	2 M3*35mm Bolts
	10 M3*10mm Bolts
	10 M3 Washers
	12 5mm*2mm round Neodymium magnets
	8 small zipties
	1 70mm Closed Loop MXL Belt - Can be subsituted for another type of belt, ideally a closed loop of about this length or slightly longer
	Masking tape
	5 minute epoxy
	Isopropyl Alcohol
	Grease (for the linear bearings)
	Disposable Rubber Gloves (not necessary, but recommended)
	
	Rotary tool (or some other way to cut the 3mm metal rods to 80mm lengths (7 are needed))
	Mini Hot Glue Gun and Glue Sticks (Regular size also works, but not as easy to fit everywhere)
	Dupont-Style Crimping Tool
	Soldering Iron
	Wire Strippers (Optional, but highly recommended)
	Multimeter with continuinty testing (Optional, but highly recommended)
	Tip for Soldering Iron that fits in the M3 inserts without sticking out the other end - expect to get plastic on this
	~600g of filament
	
   # Printed Parts - Throttle Assembly
	Fit Test:
		1 Base - Ensure the 8mm*330mm Steel Rods fit  --  Print with hole horizontal
		1 Mount - Ensure the 8mm*15mm*45mm Linear Bearings Fit
	Build:
		4 Adjustable Bearing Pillow Block v2  --  Print Side-Down
		1 Adjustable Pot Mount  --  Print Potentiometer-Hole-Horizontal
		1 Base 1  --  Print Flat
		1 Base 2  --  Print Flat
		1 Cover 1  --  Print Flat
		1 Cover 2  --  Print Flat
		1 Belt Pin Spacer  --  Print Flat
		1 Drive Axle  --  Print Flat-Side-Down
		1 Idler Axle (lower into print bed to create a flat side for better printing reliability)  --  Print Flat
		1 Mount  --  Print Top-Down
		1 Mount Side  --  Print Tab-Up
  	Imported Parts:
		2 X-Belt-Holder-Thin-GT2  --  Print Vertical
		2 GT2 2mm 6mm Wide 50 Tooth Idler M4 Shaft  (Sample - Generate and Test your own to ensure they fit your belt and Drive Axle and Idler Axle)  --  Print with teeth vertical
		1 40T 2.75mm MXL Pulley for Pot  (Sample - Generate and Test your own to ensure they fit your belt and potentiometer)  --  Print with teeth vertical
		1 20T 2.75mm MXL Pulley  (Sample - Generate and Test your own to ensure they fit your belt and Drive Axle)  --  Print with teeth vertical
				Use the OpenSCAD pulley generator for these 4 pulleys, using about the same size for all and the 2:1 gear ratio for the potentiometer. More drastic changes will require the model to be reworked.
			


# Build Guides:
Check out the videos I made for the major steps of the build as well as tips while building.

Check out the BuildSteps.md file for more step-by-step instructions without pictures. Reference the video to see pictures of all major steps.

Check out my Calibration Guide video to learn how to calibrate your own joystick using the code I wrote. Some aspects of the calibration process has been updated since the video, check the comments at the top of the sample code for details.
	
* Use the Sample Code provided and modify as needed to test and program your Arduino Pro Micro(s) for your joystick(s)
	
	* My Joysticks' code is included for reference purposes only and is not written to be modified as easily, nor is as well documented



# Project Videos:
Project Overview:													https://youtu.be/e_4dbrvhuwY

Chair Mounting Solution and Throttle-Assembly Build Explanation:	https://youtu.be/rQSjNkJ6G9A

Joystick Approximate Build Guide:									https://youtu.be/sCnEafJgWUY

Joystick Calibration Guide (Outdated):							https://youtu.be/MGDJYMHP4_0

Full Build Timelapse (5x Real Speed):								https://youtu.be/Amg51pNDD08


# Elite Dangerous Sample Gameplay Videos Using My Joysticks:

Bounty Hunting:									https://youtu.be/YqyOV4E18Ls
	
Mining:											https://youtu.be/bz7r8q-hPg0
	
Traveling Between Systems:						https://youtu.be/_PC3MqTWRCQ
	
- Vulture Ship Outfitting (bounty hunting):		https://youtu.be/YhuHz4nPciU
	
- Anaconda Ship Outfitting (mining):			https://youtu.be/gqCUKOQVyXI



# Future Ideas:
- Redesign the handle from scratch with a slightly increased diameter, larger face plate, and reworked thumb section for more wiring space and more strength.

- Add more buttons to the handle by adding a fourth shift registers

- Connecting all shift registers to one communications set instead of two seperate communications sets (this requires other passive components from what I have seen)

- Change the hat switch out for a Joycon thumbstick - likely connected to the Arduino Pro Micro's 12-bit ADC (should need two inputs)

- Improve the cable storage technique 

- Design a standalone handle with some buttons and an Arduino Pro Micro to mount on the throttle assembly and use it without a Joystick connected

- Design a function pedal unit that uses an Arduino Pro Micro - or hooks into the external potentiometer connector on a joystick - must be stable enough to use - anchor to chair?

- Rework the front cover part to clip in instead of glue in

- Design a custom PCB(s) for the face buttons - include the option for a few different layouts (such as using a joycon part over hat switch) - potentially use a large connector to join all buttons onto handle PCB and include shift registers there instead(?)

- Design a custom PCB for the handle - likely using short extension wires for each button

- Use a 10K Ohm Bourne (?) Resistor Array (9 pin, bussed) for each shift register on a PCB (and try to avoid SMD components so all can be hand soldered easily)

- Design a custom PCB for the Joystick Base electronics section (with the ability to use an auxiliary ADC, or use internal ADC (and trim board shorter??))

- Improve the ribbon cable that joins the joystick handle and base (more flexibility and/or durability?)

- Improve the external throttle connection location (as well as the slide switch)

- Improve Yaw axis mounting

- Simplify Build Guide and add a picture to each step
