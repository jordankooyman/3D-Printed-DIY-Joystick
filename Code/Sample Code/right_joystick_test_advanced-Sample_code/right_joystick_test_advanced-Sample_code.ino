//Written By: Jordan Kooyman
//		7/2021

//Button Number Mapping:

//Face: (up,down,left,right,click)
//           (8,10,9,16,15)
//       14                3
//   12      13         2     4
//       11       1        5
//           0        6
//                7


//Grip (Side View):
//                   18
//                22  17
//
//  19 (Trigger)
//
//         23         21
//
//
//                    20

#define Axis_output 0  //Set to 0 to enable, set to any other number to disable
#define Deadzone_output 0 //Set to 0 to enable, set to any other number to disable
#define Shift_output 0 //Set to 0 to enable, set to any other number to disable
#define Output_delay 100  //How long is waited between each program cycle, default is 100

// Correctly set the adc pin number for each axis <-- Not discussed in calibration video!


//          Min/Max Values, Center Deadzone Range, ADC Pin number, and Inversion Configuration - if Software center is left of Joystick center, increase the min, if it is right, decrease the max
#define Pitch_max_value 14600  //Set to the max value of Pitch Axis
#define Pitch_min_value 11500  //Set to the min value of Pitch Axis
#define deadzone_lower_Pitch 13000  //Set these to the lower and upper limits of Pitch wiggle on joystick before springs kick in
#define deadzone_upper_Pitch 13400  //Set to the same as the lower to disable
#define deadzone_Loffset_Pitch 200  //Determined through Trial/Error testing, the lower offset up to make the numbers below the deadzone range exactly end at 0
#define deadzone_Uoffset_Pitch 500//Determined through Trial/Error testing, the upper offset down to make the numbers below the deadzone range exactly end at 0
#define Pitch_ADC_Num 1  // The pin number the throttle input is connected to on the ADC
#define invert_Pitch -1  //Change the sign on the 1 to invert the Pitch axis

#define Roll_max_value 0  //Set to the max value of Roll Axis    (subtraction because this joystick's wiring limits range)
#define Roll_min_value 0  //Set to the min value of Roll Axis
#define deadzone_lower_Roll 0 //12380  //Set these to the lower and upper limits of Roll wiggle on joystick before springs kick in
#define deadzone_upper_Roll 0 //12480  //Set to the same as the lower to disable
#define deadzone_Loffset_Roll 0  //Determined through Trial/Error testing, the lower offset up to make the numbers below the deadzone range exactly end at 0
#define deadzone_Uoffset_Roll 0//Determined through Trial/Error testing, the upper offset down to make the numbers below the deadzone range exactly end at 0
#define Roll_ADC_Num 2  // The pin number the throttle input is connected to on the ADC
#define invert_Roll -1  //Change the sign on the 1 to invert the Roll axis

#define Yaw_max_value 0  //Set to the max value of Yaw Axis
#define Yaw_min_value 0  //Set to the min value of Yaw Axis
#define deadzone_lower_Yaw 0 //13150  //Set these to the lower and upper limits of Yaw wiggle on joystick before springs kick in
#define deadzone_upper_Yaw 0 //13250  //Set to the same as the lower to disable
#define deadzone_Loffset_Yaw 0  //Determined through Trial/Error testing, the lower offset up to make the numbers below the deadzone range exactly end at 0
#define deadzone_Uoffset_Yaw 0//Determined through Trial/Error testing, the upper offset down to make the numbers below the deadzone range exactly end at 0
#define Yaw_ADC_Num 0  // The pin number the throttle input is connected to on the ADC
#define invert_Yaw -1  //Change the sign on the 1 to invert the Yaw axis

#define Throttle_max_value 0  //Set to the max value of Throttle Axis
#define Throttle_min_value 0  //Set to the min value of Throttle Axis
#define deadzone_lower_Throttle 0  //Set these to the lower and upper limits of Throttle wiggle on joystick before springs kick in
#define deadzone_upper_Throttle 0  //Set to the same as the lower to disable
#define deadzone_Loffset_Throttle 0  //Determined through Trial/Error testing, the lower offset up to make the numbers below the deadzone range exactly end at 0
#define deadzone_Uoffset_Throttle 0//Determined through Trial/Error testing, the upper offset down to make the numbers below the deadzone range exactly end at 0
#define Throttle_ADC_Num 3  // The pin number the throttle input is connected to on the ADC
#define invert_Throttle 1  //Change the sign on the 1 to invert the Throttle axis



//          The Shift Register pins the HAT switch is connected to
#define hat_up 8
#define hat_down 10
#define hat_left 9
#define hat_right 16 //Other shift register - Look at left reference code for changes made



//          Colors for output wires on Joystick Handle
#define CLOCK_PIN2 10  //
#define SERIAL_IN_PIN2 5 //
#define LOAD_DATA_PIN2 7  //
#define CLOCK_PIN 15  //
#define SERIAL_IN_PIN 8 //
#define LOAD_DATA_PIN 6  //


// SCL PIN 3
// SDA PIN 2


//          End of User Configuration





#define deadzone_range_Pitch ((deadzone_lower_Pitch - deadzone_upper_Pitch) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Pitch_range ((Pitch_max_value - Pitch_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Pitch (Pitch_range - deadzone_range_Pitch)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Pitch_offset (Pitch_range + Pitch_min_value + offset_Pitch)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Pitch (Pitch_range  - deadzone_range_Pitch)  //Do not touch - calculate the software max value based on previous configuration
#define min_Pitch (-1 * max_Pitch)  //Do not touch - calculate the software min value based on previous configuration
#define Pitch_Rescale ((Pitch_max_value - (deadzone_range_Pitch + deadzone_Uoffset_Pitch)) / ((Pitch_min_value + (deadzone_range_Pitch + deadzone_Loffset_Pitch)) * -1))  //Do not touch -  Calculate the rescale factor by dividing the larger number (shifted) by the smaller number (shifted)

#define deadzone_range_Roll ((deadzone_lower_Roll - deadzone_upper_Roll) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Roll_range ((Roll_max_value - Roll_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting 
#define offset_Roll (Roll_range - deadzone_range_Roll)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Roll_offset (Roll_range + Roll_min_value + offset_Roll)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Roll (Roll_range + deadzone_range_Roll)  //Do not touch - calculate the software max value based on previous configuration
#define min_Roll (-1 * max_Roll)  //Do not touch - calculate the software min value based on previous configuration
#define Roll_Rescale ((Roll_max_value - (deadzone_range_Roll + deadzone_Uoffset_Roll)) / ((Roll_min_value + (deadzone_range_Roll + deadzone_Loffset_Roll)) * -1))  //Do not touch -  Calculate the rescale factor by dividing the larger number (shifted) by the smaller number (shifted)

#define deadzone_range_Yaw ((deadzone_lower_Yaw - deadzone_upper_Yaw) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Yaw_range ((Yaw_max_value - Yaw_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Yaw (Yaw_range - deadzone_range_Yaw)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Yaw_offset (Yaw_range + Yaw_min_value + offset_Yaw)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Yaw (Yaw_range - deadzone_range_Yaw)  //Do not touch - calculate the software max value based on previous configuration
#define min_Yaw (-1 * max_Yaw)  //Do not touch - calculate the software min value based on previous configuration
#define Yaw_Rescale ((Yaw_max_value - (deadzone_range_Yaw + deadzone_Uoffset_Yaw)) / ((Yaw_min_value + (deadzone_range_Yaw + deadzone_Loffset_Yaw)) * -1))  //Do not touch -  Calculate the rescale factor by dividing the larger number (shifted) by the smaller number (shifted)

#define deadzone_range_Throttle ((deadzone_lower_Throttle - deadzone_upper_Throttle) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Throttle_range ((Throttle_max_value - Throttle_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Throttle (Throttle_range - deadzone_range_Throttle)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Throttle_offset (Throttle_range + Throttle_min_value + offset_Throttle)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Throttle (Throttle_range - deadzone_range_Throttle)  //Do not touch - calculate the software max value based on previous configuration
#define min_Throttle (-1 * max_Throttle)  //Do not touch - calculate the software min value based on previous configuration
#define Throttle_Rescale ((Throttle_max_value - (deadzone_range_Throttle + deadzone_Uoffset_Throttle)) / ((Throttle_min_value + (deadzone_range_Throttle + deadzone_Loffset_Throttle)) * -1))  //Do not touch -  Calculate the rescale factor by dividing the larger number (shifted) by the smaller number (shifted)




#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

int j;
int l;
int k;
int value;
int lastButtonState[5] = {2,2,2,2,2};  //Up, Right, Down, Left, Cleared --  Hat Button State
int lastClickState[20] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};  //The 20 non-HAT buttons
int Axis_min[4] = {30000,30000,30000,30000}; //X, Y, Z, Throttle
int Axis_max[4] = {0,0,0,0}; //X, Y, Z, Throttle



void setup() {
  pinMode(LOAD_DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(SERIAL_IN_PIN, INPUT);
  pinMode(LOAD_DATA_PIN2, OUTPUT);
  pinMode(CLOCK_PIN2, OUTPUT);
  pinMode(SERIAL_IN_PIN2, INPUT);

  ads.begin();
//  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV (default)
//  ads.setGain(GAIN_ONE);     // 1x gain   +/- 4.096V  1 bit = 2mV
//  ads.setGain(GAIN_TWO);     // 2x gain   +/- 2.048V  1 bit = 1mV
//  ads.setGain(GAIN_FOUR);    // 4x gain   +/- 1.024V  1 bit = 0.5mV
//  ads.setGain(GAIN_EIGHT);   // 8x gain   +/- 0.512V  1 bit = 0.25mV
//  ads.setGain(GAIN_SIXTEEN); // 16x gain  +/- 0.256V  1 bit = 0.125mV
  Serial.begin(9600);
}

void loop() {
  Serial.println("Start");
  //Front Panel Shift Registers (2 daisy-chained)
  digitalWrite(LOAD_DATA_PIN, 0);  // Allow data to load on clock pulse
  digitalWrite(CLOCK_PIN, 0);  // load in data
  digitalWrite(CLOCK_PIN, 1);
  digitalWrite(LOAD_DATA_PIN, 1);  // Stop data updates on clock pulse

  //Handle Shift Register
  digitalWrite(LOAD_DATA_PIN2, 0);  // Allow data to load on clock pulse
  digitalWrite(CLOCK_PIN2, 0);  // load in data
  digitalWrite(CLOCK_PIN2, 1);
  digitalWrite(LOAD_DATA_PIN2, 1);  // Stop data updates on clock pulse

for(k = 12; k < 20; k++) { // Handle Shift Register with offset to allow for the first two to take the first 13 inputs (3 go to HAT Switch)
  value = digitalRead(SERIAL_IN_PIN2);
  if (k != hat_right - 4) {  // not the HAT switch pin connected to this shift register
    if (lastClickState[k] != value) {  //  Button in new state
      Serial.print("Joystick.setButton("); //pin HIGH means button PRESSED
      Serial.print(k);
      Serial.print(", ");
      Serial.print(value);
      Serial.println(")");
      lastClickState[k] = value;  //  Update reference array to reflect new state
    }
  }
  else { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[1]) {  // if the value has changed since the last check
          if (value == 1) {Serial.println("Joystick.setHatSwitch(0, 90)");}  //  if the value is not release (because there is seperate code to release later on) - (0, 0) is up, (0, 90) is right, (0, 180) is down, (0, 270) is left, and (0, -1) is released.
          lastButtonState[1] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }


  digitalWrite(CLOCK_PIN2, LOW);  //  Toggle Clock Pin for another bit of data
  digitalWrite(CLOCK_PIN2, HIGH);
}

for(j = 0; j < 16; j++) {
  //Serial.print(j);
  value = digitalRead(SERIAL_IN_PIN);
      if (j == hat_up) {
        if (value != lastButtonState[0]) { // if the button state has changed
          if (value == 1) {Serial.println("Joystick.setHatSwitch(0, 0)");}  //  if the value is not release (because there is seperate code to release later on) - (0, 0) is up, (0, 90) is right, (0, 180) is down, (0, 270) is left, and (0, -1) is released.
          lastButtonState[0] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_down) {
        if (value != lastButtonState[2]) { // if the button state has changed
          if (value == 1) {Serial.println("Joystick.setHatSwitch(0, 180)");}  //  if the value is not release (because there is seperate code to release later on) - (0, 0) is up, (0, 90) is right, (0, 180) is down, (0, 270) is left, and (0, -1) is released.
          lastButtonState[2] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_left) {
        if (value != lastButtonState[3]) { // if the button state has changed
          if (value == 1) {Serial.println("Joystick.setHatSwitch(0, 270)");}  //  if the value is not release (because there is seperate code to release later on) - (0, 0) is up, (0, 90) is right, (0, 180) is down, (0, 270) is left, and (0, -1) is released.
          lastButtonState[3] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else {
        l = j;
        if (j > hat_down) {l -= 3;}  //Missing hat switch numbers adjustment
        if (lastClickState[l] != value) {
          Serial.print("Joystick.setButton("); //pin HIGH means button PRESSED
          Serial.print(l + 1);
          Serial.print(", ");
          Serial.print(value);
          Serial.println(")");
          lastClickState[l] = value;
        }
      }
      if ((lastButtonState[4] == 0) // Reset hat switch position if no other position is set and it has not already been done
        && (lastButtonState[1] == 0)
        && (lastButtonState[2] == 0)
        && (lastButtonState[3] == 0)
        && (lastButtonState[0] == 0)){
        Serial.println("Joystick.setHatSwitch(0, -1)");
        lastButtonState[4] = 1;  // Prevent this code from running again until necessary
    }

  
  digitalWrite(CLOCK_PIN, LOW);  //  Toggle Clock Pin for another bit of data
  digitalWrite(CLOCK_PIN, HIGH);
}

//Use the 16-bit ADC (ADS1115) connected via I2C to read the 4 encoders (3 hall sensors and 1 potentiometer) instead of using the built in 12-bit ADC
int16_t adcYaw; // 16 bits ADC read of Yaw input
adcYaw = ads.readADC_SingleEnded(Yaw_ADC_Num);
int16_t adcPitch; // 16 bits ADC read of Pitch input
adcPitch = ads.readADC_SingleEnded(Pitch_ADC_Num);
int16_t adcRoll; // 16 bits ADC read of Roll input
adcRoll = ads.readADC_SingleEnded(Roll_ADC_Num);
int16_t adcThrottle; // 16 bits ADC read of Throttle input
adcThrottle = ads.readADC_SingleEnded(Throttle_ADC_Num);

//Update the currently stored minimum and maximum values for each axis
if (adcYaw < Axis_min[0]) {
  Axis_min[0] = adcYaw;
}
if (adcYaw > Axis_max[0]) {
  Axis_max[0] = adcYaw;
}
if (adcPitch < Axis_min[1]) {
  Axis_min[1] = adcPitch;
}
if (adcPitch > Axis_max[1]) {
  Axis_max[1] = adcPitch;
}
if (adcRoll < Axis_min[2]) {
  Axis_min[2] = adcRoll;
}
if (adcRoll > Axis_max[2]) {
  Axis_max[2] = adcRoll;
}
if (adcThrottle < Axis_min[3]) {
  Axis_min[3] = adcThrottle;
}
if (adcThrottle > Axis_max[3]) {
  Axis_max[3] = adcThrottle;
}


//Deadzone addition
if (Deadzone_output == 0) {
  if (adcYaw < deadzone_lower_Yaw) {  // If below the deadzone
    adcYaw += deadzone_range_Yaw + deadzone_Loffset_Yaw;  // Shift the number up by half the size of the deadzone
  }
  else if (adcYaw > deadzone_upper_Yaw) {  // If above the deadzone
    adcYaw -= deadzone_range_Yaw + deadzone_Uoffset_Yaw;  // Shift the number down by half the size of the deadzone
  }
  else {  // If in the deadzone
    adcYaw = ((0 + Yaw_offset - offset_Yaw));  // Set number to 0
  }   
  adcYaw += offset_Yaw;  // Add a predetermined offset to center the number range on 0
  
  if (adcPitch < deadzone_lower_Pitch) {  // If below the deadzone
    adcPitch += deadzone_range_Pitch + deadzone_Loffset_Pitch;  // Shift the number up by half the size of the deadzone
  }
  else if (adcPitch > deadzone_upper_Pitch) {  // If above the deadzone
    adcPitch -= deadzone_range_Pitch + deadzone_Uoffset_Pitch;  // Shift the number down by half the size of the deadzone
  }
  else {  // If in the deadzone
    adcPitch = ((0 + Pitch_offset - offset_Pitch));  // Set number to 0
  } 
  adcPitch += offset_Pitch;  // Add a predetermined offset to center the number range on 0
  
  if (adcThrottle < deadzone_lower_Throttle) {  // If below the deadzone
    adcThrottle += deadzone_range_Throttle + deadzone_Loffset_Throttle;  // Shift the number up by half the size of the deadzone
  }
  else if (adcThrottle > deadzone_upper_Throttle) {  // If above the deadzone
    adcThrottle -= deadzone_range_Throttle + deadzone_Uoffset_Throttle;  // Shift the number down by half the size of the deadzone
  }
  else {  // If in the deadzone
    adcThrottle = ((0 + Throttle_offset - offset_Throttle));  // Set number to 0
  }  
  adcThrottle += offset_Throttle;  // Add a predetermined offset to center the number range on 0
  
  if (adcRoll < deadzone_lower_Roll) {  // If below the deadzone
    adcRoll += deadzone_range_Roll + deadzone_Loffset_Roll;  // Shift the number up by half the size of the deadzone
  }
  else if (adcRoll > deadzone_upper_Roll) {  // If above the deadzone
    adcRoll -= deadzone_range_Roll + deadzone_Uoffset_Roll;  // Shift the number down by half the size of the deadzone
  }
  else {  // If in the deadzone
    adcRoll = ((0 + Roll_offset - offset_Roll));  // Set number to 0
  }   
  adcRoll += offset_Roll;  // Add a predetermined offset to center the number range on 0
}

if (Shift_output == 0) {
  // Rescale one side of each input to match the size of the other side of that input (such as change -11560, 0, 13560 to -11560, 0, 11600)
  if (adcYaw > 0) {adcYaw = adcYaw / Yaw_Rescale;}
  if (adcPitch > 0) {adcPitch = adcPitch / Pitch_Rescale;}
  if (adcRoll > 0) {adcRoll = adcRoll / Roll_Rescale;}
  if (adcThrottle > 0) {adcThrottle = adcThrottle / Throttle_Rescale;}
  
  // Axis inversion
  adcRoll = ((adcRoll - Roll_offset) * invert_Roll);
  adcPitch = ((adcPitch - Pitch_offset) * invert_Pitch);
  adcYaw = ((adcYaw - Yaw_offset) * invert_Yaw);
  adcThrottle = ((adcThrottle - Throttle_offset) * invert_Throttle);

  //Prevent the values from exceding the defined limits
  if (adcYaw > max_Yaw - 1) {adcYaw = max_Yaw - 1;}
  if (adcYaw < min_Yaw + 1) {adcYaw = min_Yaw + 1;}
  if (adcPitch > max_Pitch - 1) {adcPitch = max_Pitch - 1;}
  if (adcPitch < min_Pitch + 1) {adcPitch = min_Pitch + 1;}
  if (adcRoll > max_Throttle - 1) {adcRoll = max_Throttle - 1;}
  if (adcRoll < min_Throttle + 1) {adcRoll = min_Throttle + 1;}
  if (adcThrottle > max_Roll - 1) {adcThrottle = max_Roll - 1;}
  if (adcThrottle < min_Roll + 1) {adcThrottle = min_Roll + 1;}
}
else if (Shift_output == 1) {  // Output the offset of each axis
  Serial.print("Roll_offset: "); Serial.println(Roll_offset);
  Serial.print("Pitch_offset: "); Serial.println(Pitch_offset);
  Serial.print("Yaw_offset: "); Serial.println(Yaw_offset);
  Serial.print("Throttle_offset: "); Serial.println(Throttle_offset);
}


if (Axis_output == 0) {  // Print out each axis value (may be shifted) and the min and max (not shifted)
  Serial.print("adc0 (Yaw): ");  Serial.print(adcYaw);  Serial.print("     Max: ");  Serial.print(Axis_max[0]);  Serial.print("  Min: ");  Serial.println(Axis_min[0]);
  Serial.print("adc1 (Pitch): ");  Serial.print(adcPitch);  Serial.print("     Max: ");  Serial.print(Axis_max[1]);  Serial.print("  Min: ");  Serial.println(Axis_min[1]);
  Serial.print("adc2 (Roll): ");  Serial.print(adcRoll);  Serial.print("     Max: ");  Serial.print(Axis_max[2]);  Serial.print("  Min: ");  Serial.println(Axis_min[2]);
  Serial.print("adc3 (Throttle): ");  Serial.print(adcThrottle);  Serial.print("     Max: ");  Serial.print(Axis_max[3]);  Serial.print("  Min: ");  Serial.println(Axis_min[3]);
}
delay(Output_delay);
}


//Written By: Jordan Kooyman
//		7/2021
