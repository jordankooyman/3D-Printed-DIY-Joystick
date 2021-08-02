This guide assumes you are building what I have built (including active-high button signaling)

# Joystick Build Instructions
Handle:

- Choose 12 6mm*6mm push buttons for the face panel (differing lengths can be used to make certain buttons stand out) and fit one button cap (shorter variant) to each one. If one does not stay on, a small dab of hot glue will help.

- Check the fit of the hat switch with hat included in the face plate. All 5 clicks should be accessible. If they are not, either change the spacing between the hat switch and face plate, or enlarge the hole. Once fit is good, glue in the spacer (if used) with a thin glue such as super glue, then continue.

- Arrange the 12 buttons in the face panel assembly such that one side of each button forms a common link with the buttons adjacent (the longer the chains, the less wires will be needed to join these together on the common side). Check which sides of the button are joined and which are only connected when the button is pressed (there are typically 4 pins, with 2 bars separating the 4 pins into 2 sets, and each set is joined together). Use hot glue to fill the gaps between the buttons to hold everything in place. Ensure enough space is left for the hat switch (or the spacer is glued in).

- Bridge one side of all the push buttons, using short lengths of red wire where necessary to form the common 5V line.

- Test the fit of this assembly in the both sides of the handle. Make any adjustments necessary for a good fit when the handle halves are held closed.

- Solder ~2 inch (50mm) lengths of different colored wires (not red or black) to all the buttons, one to each button. Ensure none of them are on the common side.

- Prepare the hat switch by tinning the 6 leads, measuring out and cutting 6 wires (1 color: ~8 inch (~250mm),4 colors: ~2.5 inch (~65mm), red: ~1 inch (~25mm)). Connect the red wire to the common pin, the long wire to the center click pin, and the remaining wires to the remaining pins. Solder the wires such that each wire runs across the back of the hat switch, forming a V of inter-woven wires.

- Place the hat switch in its position and ensure it still fits with hat cover on. Then tack in with a small amount of hot glue before putting globs of hot glue all around it to hold it in place (ensure it can still move freely before and after the globs of hot glue are added. If it cannot, remove the hot glue by using isopropyl alcohol (pour small amounts around the edge of the glob and peel the hot glue off).

- Prepare 2 SN74HC165 Shift Registers by tinning all the leads that are needed (VCC, GND, 8 Inputs, Clock, Enable, Load Data, Serial Output, and Serial Input (only this one on 1 of the 2)). Find a wiring diagram online to determine which pins are what.

- Separate the 17 wires from the buttons into 5 groups: 1 group of 1 wire (the long wire from the hat switch) and 4 groups of 4 wires (try to keep each group to one line of buttons as best as possible and filling in gaps with the hat switch leads, as this makes soldering to the shift registers, and later debugging any issues, much easier). Trim each group of wires to a common length, ensuring they are all long enough to connect to an input pin on a shift register placed above it, upside down, strip ~3mm off each wire, and tin the end of each wire.

-  Continue by soldering in both shift registers to the button leads. Start with the middle 2 groups, connecting one to each shift register, then solder the outer 2 groups of wires to the outward facing inputs on each shift register.

- Connect a short length of red wire from the VCC input of each shift register to somewhere along the common path on the buttons.

- Cut a large diameter piece of heat shrink (ideally about 0.875 inches (~20mm) tall when flattened) to a length of ~1.5 inches (~30mm) and place between the 2 shift registers to prevent short circuits (do not unfold to 1 layer unless you do not have a large enough piece of heat shrink tubing).

- Test the fit of this assembly in the both sides of the handle. Make any adjustments necessary for a good fit when the handle halves are held closed.

- Prepare 16 10k registers by trimming one side to ~10mm and tinning the shortened leads.

- Solder the shortened end of each resistor to one input pin for all input pins on all shift registers. 

- Then do a half twist of all the long resistor leads above each shift register and separate out and bend one lead to go down to the GND pin and one lead to go to the Enable pin on each shift register, soldering them in place. 

- Then solder each ball of resistor leads together with a large blob of solder, followed by trimming all excess resistor leads. Then solder in a short length of black wire between the two solder balls.

- Connect the serial output of one shift register to the serial input of the other shift register (the one with that lead already tinned, preferably) with a short length of wire running along the bottom (now top) of the IC casing, staying under the resistors.

- Prepare 3 ~6 inch (~150mm) lengths of colored wire and connect one to each of the following pins on the shift register that has the serial input used: Load Data, Serial Output, and Clock. 

- Then, using a short length of the same colors of wire, connect the corresponding pins on the other shift register to this shift register and the pins with the long wires connected to it. 

- Write down which color of wire is connected to which pin.

- Connect a ~3 inch (~80mm) red wire to the common section of the buttons and a ~6 inch (~130mm) black wire to one of the solder balls.

- Test the fit of this assembly in the both sides of the handle. Make any adjustments necessary for a good fit when the handle halves are held closed.

- Test that everything is working by connecting all 6 wires to an Arduino Pro Micro (ideally using a single pin header) (red to VCC, black to GND, and the 4 colors to any I/O pin). Using the shift register test Sample code, test that every button works properly by updating the pin numbers to reflect which pins are used. Additionally, test this assembly again while it is pressed into both halves of the handle.

	- If a button is not giving an input, make sure the wire corresponding to has not come loose. If a button is showing as clicking multiple buttons, verify it is not shorting against other pins. If a button is showing as always on, make sure the wire for that button is not connected to the common side.

- Once everything is verified to be working, set this button panel assembly aside to begin working on the handle assembly.

- Begin by selecting 6 6mm*6mm push buttons of varying lengths, one for each hole in the primary side of the handle (left for right joystick, or right for left joystick). Ensure that each button can be clicked with a button cap (longer variant) pressed or glued to the end.

- Continue by tinning all 4 leads of all 6 buttons, then soldering a common red wire between all 6 (ensuring it is the proper length to reach each button when all are installed) and a colored wire that is long enough to reach slightly into the indent used for mounting the handle to the base. Additionally, ensure that the colored wires are not connected to or shorting against the common wire in any location (a continuity check works well).

- Solder an additional ~3 inch (~75mm) red wire to the common side of the furthest down button. Repeat this step for the button just above that (lowest) button.

- Once all the wires are soldered to all 6 handle buttons and all the buttons are fitted into the handle, apply a generous sized glob to the back of each button to hold it in place. Once the glue has cooled, ensure all buttons can still be pressed easily (if not, try twisting them or dropping a small amount of isopropyl alcohol down the button shaft and twisting it).

- Set the primary handle side aside to work on the secondary side.

- Prepare the large microswitch by soldering 2 ~2 inch (~25mm) wires to it, one to the common (this is ideally red), and a color to the normally open pin on the microswitch.

- Using the trigger, a long M3 Bolt (nut optional but useful), and the microswitch, determine the position of the microswitch such that the trigger can easily click the microswitch, the spring of the microswitch pushes the trigger back out entirely, and when the trigger is not pressed, the microswitch is also not clicked. Once that position has been found, use hot glue to hold the microswitch in position by applying hot glue around the 3 edges that do not have the button and lever arm (also, ensure that the hot glue does not impede the movement of the lever arm in any way).

- Then, bend the two wires soldered to the microswitch 180 degrees to come back alongside the side of the microswitch, trim the two wires to be even (in the bent shape) about 10mm from the upper edge (the side the lever arm overhangs) of the microswitch, place a short length of heat shrink tubing of appropriate size on each wire, slide the heat shrink as far down as possible, solder the two wires to a 2-pin pin header (or some other 2 pin connector), and insulate the solder joints with the heat shrink tubing. A small dab of hot glue can be used on one of the wires to help keep them bent around the microswitch, just ensure the connector has enough freedom of movement to reach to the other side of the joystick handle when closed up (with some extra movement if possible, as this makes final assembly and maintenance much easier).

- Set aside the secondary handle side and return to working on the primary handle side

- Now prepare the third shift register by tinning the pins being used (8 inputs, Clock, Enable, Load Data, Serial Output).

- Next, using the shift register (again, with pins pointing up the handle)  as reference, trim all wires (excluding the further up red wire) to be about ~5mm to ~10mm longer than necessary to connect to an appropriate pin (either input of VCC). Tin the wires and solder all wires in place. There should be 2 unused input pins, preferably on the outward facing side of the shift register.

- Now, using the secondary side as reference, bend the extra red wire from the primary side around until in lines up with the connector from the trigger microswitch, trimming off excess if needed (ensure some wire is left to allow for movement). Then, setting the secondary side to the side again, measure out a length of colored wire to reach from the end of the red wire down to an available shift register pin, giving extra length to follow any bends in the red wire and to reach the shift register in the flattest possible path. Then prepare the end of the red wire and both ends of the colored wire for soldering by stripping them and tinning them, as well as putting short lengths of heat shrink tubing on both.

- Solder the other end of the 2-pin pin header (used with the microswitch) to the red wire and colored wire, then slide up and shrink the heat shrink tubing. Additionally, solder the other end of the colored wire to an input pin on the shift register.

- Prepare 8 more 10k registers by trimming one side to ~10mm and tinning the shortened leads.

- Solder one resistor to each input pin, just as was done on the face button assembly. Then join the long leads in a ball using a half twist and bend one lead to the GND input and one lead to the Enable pin, soldering them in place. Then solder the resistor ball together and trim the excess leads.

- Ensure the shift register can fit inside the handle when both halves are pressed closed. Also ensure the microswitch connectors align and do not interfere with anything when connected and the handle is closed.

- Next, test the fit of the face button assembly, and if everything still fits and works, use a generous amount (half of a mini stick approximately) of hot glue (while still working fast) across the top section where this assembly fits in the primary side of the handle to glue the face button assembly into place.

- Once cooled, desolder the pin header from the wires and run the 17th button wire down the handle, keeping it as low-profile as possible, to the shift register. Then trim the wire to the appropriate length to reach the 1 remaining input pin. Then solder in place.

-  Next, trim the red wire from the button assembly to be long enough to reach one of the red wires connecting all the buttons together. Strip a short section of insulation off of both red wires, tin them, and solder together. Ensure all buttons are still connected together on the common side.

- Then, run the black wire down the handle to connect to the solder ball above the bottom of the third shift register, trimming to length (again using the lowest profile path possible), and soldering in place.

- Now, run the 3 communications wires from the face button assembly down the handle, rearranging wires where necessary to ensure it can fit under the microswitch when the handle is closed (check the fit now). 

- Then, measure out two lengths of 4 sets of wires (ideally ribbon cable with a red wire on one set of 4 and a black wire on the other set of 4, but any ribbon cable will do). One set must reach up into the joystick to go about ~1 inch (~25mm) past the end of the wires for the face button assembly. The other set must reach up into the joystick handle to go to the handle shift register. Both should reach out ~5 inches (~120mm).

- Next, solder one set of wires to the 3 communications wires from the face assembly (again writing down which color is which). Solder the fourth wire to the common 5V line.

- Solder the other set of wires to the Clock, Serial Output, and Load Data pins on the shift register (again writing down which color is which), and connecting the fourth wire to the solder ball above the bottom of the lower shift register.

- Now, connect all the wires up to the Arduino and test using the shift register code once again. Debug where needed.

- Once every button is verified to be working, use hot glue to tack down the wires and the shift register. Use a large blob to keep the wires that run out of the handle from being pulled out further (include a little slack on the inside if possible).

- Test that everything is still working. Debug where needed.

- Join the two halves of the handle assembly together using 3 M3 bolts and nuts. The bolt the trigger pivots on cannot be tightened too much, as it causes the trigger to bind (tighten it until the trigger does not spring back out, then slowly loosen until it pops out, then add another quarter turn of looseness). The other bolt near the top should be tightened first, then the trigger, then the one near the bottom of the handle.

- Once the handle is entirely closed up, test to make sure every button still works as expected. Debug where needed.

- Once the handle is fully closed and every button still works, it can be set aside.



Base:

- Begin by removing any supports still on the printed models.

- Use a drill to sand down axis_for_ver_D v3 until it fits easily through a 606 bearing, but not so far that it wobbles.

- Fit the 4 606 bearings, 2 in the Mount Base, 2 in hinge_ver_D_-_606_bearings v3. If the bearings are tight, a light sanding (rotary tool recommended) of the plastic may be necessary. If the part cannot be pressed in easily, you risk fracturing the part by pushing harder. If the fit is loose, a little bit of 5 minute epoxy around the edges can hold them in place. Just make sure that if you glue it, they can still spin freely and that they are still aligned (use a long rod through both to ensure alignment).

- Cut and grind the 5mm shaft to match Yaw Shaft (Steel) model if not already done so. Ensure the Yaw Rid Retention Clip can fit over the center flat section. If not, the lips of the printed part can be trimmed or the rod can be thinned more (just do not go so far that it bends easily)

- Next, using the soldering iron and a tip that fits in your M3 brass inserts without sticking out the other end, press an insert into all of the following:
	- 4 on the bottom of Mount Base
	
	- 1 in the corner on the top of Mount Base
	
	- 3 into both Yaw Spring 2 parts (all on the same side)
	
	- 2 into Top (the upper (the large hole faces down) one must be quite deep as a M3*6mm bolt needs to sit flush with the surface of the part there, use the flat end of the yaw axis shaft to ensure it is not too deep).
	
	- 1 into Bottom
	
	- 3 into the front of base_cover (Optional, only if using the front wire storage solution)
	
- Using an M3 bolt, clean out the squeezed-out plastic from every insert accessible from both ends.

- Drill out the following parts using a drill bit that is just a little too large for the hole:
	- Main yaw axis shaft in Top and Bottom - Some brass may also be drilled out from Top.
		
	- The upper hole for Top, must be large enough to fit an M3 bolt head, drill down to brass insert.
		
	- Enlarge the hole to the left of the bearing when looking from the front cover side on Mount Base to fit an M4 bolt threaded into the plastic (if enlarged too far, use an M5 bolt instead or use an M3 bolt with another threaded insert)
	
- Continue by preparing the potentiometer. Cut a red, black, and colored wire to ~7 inches (~180mm), and connect the colored wire to the middle pin. Connect the remaining 2 wires to the outer 2 pins of the potentiometer.

- Fit the potentiometer into the Mount Base in the single large hole in the main cavity. The shaft should be pointing out of the assembly. Use a washer and nut that should be included with the potentiometer to secure it in place as tightly as possible. There should be a locater pin on the potentiometer that should align with a small secondary hole above the main hole for the potentiometer. Run the 3 wires from the potentiometer into the front electronics area, using the cutout on that side of the divider.

- Prepare the 3 AH3503 Hall Effect Sensors by soldering ~10 inch (~255mm) black, red, and colored wires to their leads (research online for the pinout). Add a piece of heat shrink over all 3 leads of all 3 sensors.

- Select one sensor and bend the leads 90 degrees such that the beveled face of the sensor is facing up when the wires are held vertical. Using super glue or 5 minute epoxy, glue the sensor to the small post in the main cavity of Mount Base with the leads/wires running down the vertical face and going towards the cutout on the left (when looking at it from the electronics section).

- Using 5 minute epoxy, glue 2 neodymium magnets into the small cavity on the bottom of hinge_ver_D_-_606_bearings v3. Before using glue, check the fit of the magnets. The magnets must have opposite poles facing each other when glued in (such that they are attracting (NOT repelling) each other).

- Take 1 strip of thin steel sheet and bend into a U shape large enough that 1 neodymium magnet can go an the inside of either tab (also touching the bottom of the bracket) and a hall effect sensor can fit in between and has enough space to spin without hitting anything. The magnets must be affixed such that they are attracting (NOT repelling) each other. Use 5 minute epoxy to glue the magnets in position after cleaning the magnets and steel strip with isopropyl alcohol. Repeat this step to make a second magnet bracket.

- Also use 5 minute epoxy to affix 1 or 2 washers over all 4 M3 threaded inserts on the bottom of Mount Base. These will act as spacers when the joystick is mounted to a mounting plate and prevent the yaw axis hall effect sensor from rubbing on anything and getting damaged or unglued.

- After the epoxy has set on both magnet brackets, the excess steel (and sharp edges) can be trimmed to match the profile of the round magnets.

- Next, fit the steel shaft through Bottom and align the double flat section in the middle with the square cutout in the printed part, the flat end should extend out from the side with the wings. Fit the Yaw Rod Retention Clip over the steel shaft (if it is loose, affix to the shaft using a small amount of super glue (ensure it does not glue anything else together!)).

- Then, fit Top onto the protruding section of the shaft, aligning the flat spot with the location of the inset M3 bolt. After pushing the shaft up (if it can move up/down), secure Top to it using the inset M3 bolt. Once fully tightened, the head of the M3 bolt should be flush with the outside edge of Top (if it protrudes slightly, (< 2mm), this is acceptable).

- Next, fit 1 Yaw Spring 2 to each wing on Bottom, securing the skinny end to Bottom using an M3 bolt from the bottom of the wing into the threaded insert. The bolt should be moderately tight, but still allowing for free rotation of the Yaw Spring 2 parts. Another M3 bolt of the same length should be installed in the middle hole of Yaw Spring 2, keeping the bolt head slightly below the bottom edge of the wing. A third M3 bolt, shorter this time, should be installed in the wide end of Yaw Spring 2 with a short extension spring. The spring should be connected to both Yaw Spring 2 levers and should return Top to center when it is rotated. If the spring is not strong enough, it can be replaced later, once the handle is mounted and spring strength can be accurately tested.

- Now, slide the Bottom part down into hinge_ver_D_-_606_bearings v3 until the perpendicular hole in Bottom lines up with the two bearings in the hinge. Hold it in place using axis_for_ver_D, sliding it flat side first from the side of the hinge with a longer protruding arm. It should stop almost flush with the bearing, but still protruding slightly.

- Slide hinge_cam_slider_for_ver_C v3 into the rectangular slot in the side of hinge_ver_D_-_606_bearings, matching up the long side with the longer hook arm and the rounded section against the V of the Bottom.

- Affix 1 extension spring to either side of hinge_ver_D_-_606_bearings, hooking onto the protruding arms and the hinge_cam_slider_for_ver_C.

- Use isopropyl alcohol to clean the bottoms of both magnet brackets previously prepared.

- Ensuring that the handle mount (Bottom and Top) is in the centered position (the 2 new extension springs are as compressed as possible), use 5 minute epoxy (also recommended: gloves) to glue 1 magnet bracket onto the end of axis_for_ver_D on the side of the hinge assembly that has a gap between the spring and the body. Ensure the bracket is as centered as possible, not stuck to anything beyond the axis shaft (the inner race of the bearing is also acceptable), and is parallel with the bottom of hinge_ver_D_-_606_bearings. Hold it in place until the epoxy sets.

- Clean the end of a short section of the yaw axis shaft protruding from the bottom of the handle mount assembly using isopropyl alcohol.

- Use 5 minute epoxy to glue the other magnet bracket to the end of the yaw axis shaft, ensuring Top is as centered rotationally as possible and that the magnet bracket is rotated such that the open sides of the U face the long face of the bottom of Bottom. Also ensure no epoxy sticks to the printed parts and impedes the rotation of the magnet bracket to +/- ~40 degrees.

- Once both magnet brackets are installed and can rotate freely (and the epoxy has cured), select 1 hall effect sensor (previously prepared), bend the sensor body 90 degrees from the leads/wires, and glue to the side of the hinge_ver_D_-_606_bearings with the sensor body centered between the two magnets in the magnet bracket and on the center of rotation as best as possible using hot glue. Bend the wires such that they follow the top edge of the side profile of hinge_ver_D_-_606_bearings until about 15mm from the front edge (the end with the cavity with the magnets on the bottom) and bend them downwards. Use hot glue to hold the wires in position. Ensure the bearing can still move freely.

- Bend the leads/wires of the third hall effect sensor such that the sensor body is 90 degrees from the leads, and about 10mm away, the wires bend down and flatten out in the same direction as the sensor. Using hot glue, glue the wires to the bottom of Bottom, keeping the sensor body centered in the magnet bracket and over the center of rotation as best as possible.

- Set aside the hinge/handle mount assembly

- Prepare a 3 pin dupont-style (or other style) connector with a black (~3 inch (~75mm)), red(~3 inch (~75mm)), and colored (~1 inch (~25mm)) wires. This is for the external throttle input, so it this step is Optional. Any pinout works, but I recommended having the signal in the middle, then polarity is almost irrelevant (switching the VCC and GND pins simply inverts the input). Ensure the loose end of the colored wire is also stripped. Additionally, prepare the 3 position switch with a ~2 inch (~50mm) colored wire on the middle pin. If using a double pole switch, I recommended connecting the two independent sets of pins in the middle.

- Use the 2 M2*4mm bolts to hold the 3 position switch in its mounting hole. Then slide the wires of the 3 pin connector through the small slot above the switch and bend the colored wire down to the side of the switch that has the E label on the outside and solder in place. Trim the colored wire coming from the internal potentiometer to reach the switch, then strip and solder to the other side of the switch, there should be an I label on the outside on that side of the switch.

- Fit 2 M4 Bearing Spacers in the 2 606 bearings in Mount Base. Fit an M4 nut in the slot near either end of the hinge_ver_D_-_606_bearings, using an M4 bolt to align it properly and holding it in place with a block of hot glue around it, ensuring the hot glue does not interfere with anything else.

- Now, mount the hinge/handle mount assembly in Mount Base using 2 M4 Bolts. A button-head M4 bolt must be used on the interior bearing. The exterior bearing can use any style of M4 Bolt, as long as it is the correct length.

- Pull all wires from the mounting assembly through the side next to the external throttle input.

- Separate all the blacks wires and all the red wires and trim each to a common length, keeping the two groups at different lengths (if possible) so that they cannot short against each other. Strip all these wires and solder all black wires together and all red wires together.

- Prepare the ADC with pin headers. Then, fit the ADC in the base assembly below the external throttle input. Connect the center wire from the switch to one analog input of the ADC. Connect the 3 colored wires from the hall effect sensors to the other 3 analog inputs of the ADC. Connect a black wire long enough to reach from the common ground point to the GND pin of the ADC. Repeat with a red wire from the common 5V point to the VCC pin of the ADC. Trim and solder a 4.7K Ohm resistor to the SDA and SCL pins of the ADC. Connect the other end of the resistors to 5V. Then solder a ~1 inch (~25mm) colored wire to SDA and SCL. Write down which wire goes to which pin.

- Fit the Arduino Pro Micro (and pin headers) into the electronics section, ensuring the micro usb port is pointing towards the cutout on the side of the potentiometer. Use a small glob of hot glue to secure the Arduino board in place.

- Connect the SDA pin from the ADC to pin 2 of the Arduino Pro Micro. Connect the SCL pin of the ADC to pin 3 of the Arduino Pro Micro. Then use a short length of red wire to connect the VCC pin of the Arduino to the common 5V point and a short length of black wire to connect a GND pin from the Arduino to the common ground point.

- Test that the ADC is working properly using the joystick test code and all optional settings disabled. As each axis is moved the values should increase or decrease. Ensure that all 4 axes are working properly and that nothing has come loose or collided. (Remember that the potentiometer is on a switch, so it should be set to the I side before the internal one works.

- Test the fit of base_cover, moving wires and trimming base_cover where needed. Test all 4 axes again to ensure everything still works

- Once everything is verified to be working as intended, the handle can be mounted. Remove the single M3 bolt in the lower section of the handle assembly. Fit the handle on the Top piece, the handle should be tilted towards the electronics area. Once fit properly, the M3 bolt removes from the handle should be reinserted and should slide through the hole in the side of Top as well. Drill out the hole if necessary.

- Bend the wires from the handle in a wide loop such that they end pointing towards the rectangular cutout in base_cover. Ensure the handle maintains its full range of motion (including yaw) with the wires pinned at the end here. Also adjust the length needed.

- Once a satisfactory position and length for the wires has been found, trim the wires to length and separate all the wires at the end ~1 inch (~25mm). Remove base_cover.

- Prepare an 8 pin dupont-style connector (or other 8 pin connector) by crimping long and short pins to all 8 wires from the joystick. Ensure there is at least 1 of both types of pin. Fit all 8 wires into a connector part, writing down which pin on the connector is which communications or power wire. (If building multiple joysticks, I recommended using the same pinout for both on this connector)

- Create the other end of the 8 pin connector that was just made for the handle. Use wires long enough to reach from the Arduino Pro Micro, out the rectangular cutout in base_cover, and to the desired connecting position for the handle. Also include an extra ~5mm just in case. Crimp the appropriate pins to each wire and fit in the connector housing. As the wires are soldered to the Arduino Pro Micro, write down which Arduino pin is connected to which function based on where that wire is positioned in the connector.

- Using the test code once again, ensure that all the axes still work as expected and that every button works individually.

- Once everything is verified to be working, reinstall base_cover and hold in place using a few ~1 inch (~25mm) lines of hot glue along the seem. Test everything is still working. Use isopropyl alcohol to peel the hot glue off if needed.

- Once everything is still working with the base_cover installed, trace along the entirety of the seem between the cover and the base with hot glue.

- The build is now finished. Calibrate your joystick, then you can use it!


# Throttle Build Instructions
- If the base and cover were printed in 2 pieces, cut the 3 3mm rods into 7 80mm lengths. Bevel both ends of all 7 rods.

- Clean the 7 rods with isopropyl alcohol. Prep the base and cover to be glued together by placing a piece of masking tape on one side of the joint that overlaps halfway with the joint.

- If using rubber gloves, put them on now.

- Use 5 minute epoxy to glue 5 of the rods into the base by dripping some epoxy into each rod hole on both sides, smearing some epoxy along the plastic V, inserting the rods into the holes on one side, then pressing the other side onto the rods until the two plastic surfaces meet, then use the masking tape to cover the joint and prevent epoxy from leaking out.

- Use 5 minute epoxy to glue the remaining two rods into the cover by dripping some epoxy down both holes on both sides of the cover, then smearing epoxy along the mating surface on one side. Slide the rods into the holes on one half of the cover, then slide the other half of the cover over the rods. Once fully pressed together, use the masking tape to reduce epoxy leakage.

- Use 5 minute epoxy to glue 1 50 tooth GT2 pulley to the middle of the Idler Axle (ensure it is as perpendicular to the axle as possible). Then glue the 20 tooth MXL pulley (or substitute) to one end of the Drive Axle.

- Use the 8 small zip ties to affix the 4 linear bearings to the bottom of Mount, 2 zip ties per bearing, looping through the holes and guides. I recommended Keeping the heads of the zip ties towards the middle to avoid clearance issues.

- Use 5 minute epoxy to glue Mount Side to Mount, lining up the grooved teeth. Test fit before applying epoxy, removing material from the joint where necessary. Try not to glue the zip ties into place.

- Prepare the 4 Adjustable Bearing Pillow Blocks by fitting 1 606 bearing into each (if loose, use epoxy to affix after cleaning the grease off with isopropyl alcohol).

- Prepare the Adjustable Pot Mount by fitting the potentiometer and fixing it in place using the included washer and nut.

- Use 5 minute epoxy to glue in 6 neodymium magnets into the 6 holes along the perimeter of Base. Also glue in 6 magnets into Cover, ensuring that all magnets are attracting each other.

- Once the epoxy has set on the Drive Axle, fit one Adjustable Bearing Pillow Block on the long end of the Drive Axle, then a washer (can be printed), then use 5 minute epoxy to glue on the other 50 tooth GT2 pulley, trapping the bearing and pillow block in the middle.

- Once all the epoxy has cured, use the soldering iron and the tip for the M3 inserts to press 4 inserts into the bottom of the Base, 2 inserts into the top side of the holes on Mount Side, and 2 inserts into the bottom of all 5 (Adjustable Bearing Pillow Block * 4 and Adjustable Pot Mount * 1) adjustable mounts.

- Using short M3 bolts and washers, affix all 5 adjustable mounts on Base. The potentiometer mount is the only mount that should stretch across two slots.

- Clean the 2 8mm*330mm steel rods using isopropyl alcohol.

- Apply a few drops of grease inside each linear bearing.

- Fit the 2 8mm*330mm steel rods in the two holes in the base. As they are slide through, slide the linear bearings on the bottom of Mount onto the steel rods. Slide in as far as possible (they should go into holes in the other end of the large slots). The Mount carriage should slide freely from end to end. Hold the rods in place by filling the holes they were slide through with hot glue up to the surface of the printed part.

- Measure out ~18 inches (~450mm) of 3 wires (ideally joined in a ribbon cable). Solder one end to the three pins on the potentiometer. Tack a section of the wire to the base near the middle so that the wire can still bend freely beyond that point and can reach the groove in Mount Side between the 2 M3 inserts. Glue the wire in that groove, leaving enough past it so that it can bend around and reach the external throttle connector when a joystick is mounted to the carriage.

- Split the 3 wires apart at the loose end and join in a connector, matching the connector and pinout used on the external throttle connector on the joystick. 

- Next, fit 2 M3*35 bolts through Belt Pin Spacer, then screw both bolts into the two m3 inserts in Mount Side, keeping the potentiometer wire below the spacer.

- Then, measure out the appropriate length of GT2 belt and cut to length, ensuring enough extra is left for it to wrap around the 2 bolts as well as the 2 50 tooth pulleys.

- Loop the GT2 belt under and around both 50 tooth pulleys, then back towards to bolts on mount side.

- Fit a X-Belt-Holder-Thin-GT2 over either end of the belt, then loop one side over the closer bolt, fold back on itself around the bolt such that the teeth of the belt interlocks, then slide the belt holder over the overlap to hold it in place. Repeat this for the other end of the belt around the other bolt, this time pulling the belt moderately tight.

- Loosen the bolts on the bottom of the idler pulley assembly, then pull both bearing blocks back, tightening the belt. Then tighten the bolts on the bottom again to lock this position in.

- Slide the carriage to one extreme.

- Press the 40 tooth MXL pulley onto the potentiometer shaft and turn potentiometer to the same extreme end as the carriage.

- Loosen the 2 bolts holding the potentiometer mount in position and install the closed loop MXL belt over the 20 tooth and 40 tooth pulleys. Then tighten the belt by sliding the potentiometer mount and tighten on bolts on the bottom of the potentiometer mount when a satisfactory tension has been reached.

- Ensure that the carriage moves with little resistance in its full range of motion and that the potentiometer is spun for the whole range of motion.

- Install a joystick using 4 M3 bolts through the 4 mounting holes in Mount. The bolts are fed up from the bottom, on either side of 2 of the linear bearings. Then plug in the connector from the mounting carriage into the external input, and slide the switch to the external side.

- Calibrate the throttle input as desired then the throttle is completed and ready for use.