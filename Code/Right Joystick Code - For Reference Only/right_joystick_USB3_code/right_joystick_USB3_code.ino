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


//          Min/Max Values, Center Deadzone Range, and Inversion Configuration - if Software center is left of Joystick center, increase the min, if it is right, decrease the max
#define Pitch_max_value 14500  //Set to the max value of Pitch Axis
#define Pitch_min_value 11000  //Set to the min value of Pitch Axis
#define deadzone_lower_Pitch 12900 //11696  //Set these to the lower and upper limits of Pitch wiggle on joystick before springs kick in
#define deadzone_upper_Pitch 13400 //11936  //Set to the same as the lower to disable
#define invert_Pitch -1  //Change the sign on the 1 to invert the Pitch axis

#define Roll_max_value 18450  //Set to the max value of Roll Axis    (subtraction because this joystick's wiring limits range)
#define Roll_min_value 10000  //Set to the min value of Roll Axis
#define deadzone_lower_Roll 12080 //12380  //Set these to the lower and upper limits of Roll wiggle on joystick before springs kick in
#define deadzone_upper_Roll 12780 //12480  //Set to the same as the lower to disable
#define invert_Roll -1  //Change the sign on the 1 to invert the Roll axis

#define Yaw_max_value 15450  //Set to the max value of Yaw Axis
#define Yaw_min_value 10600  //Set to the min value of Yaw Axis
#define deadzone_lower_Yaw 12300 //13150  //Set these to the lower and upper limits of Yaw wiggle on joystick before springs kick in
#define deadzone_upper_Yaw 12800 //13250  //Set to the same as the lower to disable
#define invert_Yaw -1  //Change the sign on the 1 to invert the Yaw axis

#define Throttle_max_value 24500  //Set to the max value of Throttle Axis
#define Throttle_min_value 0  //Set to the min value of Throttle Axis
#define deadzone_lower_Throttle 12000  //Set these to the lower and upper limits of Throttle wiggle on joystick before springs kick in
#define deadzone_upper_Throttle 12000  //Set to the same as the lower to disable
#define invert_Throttle 1  //Change the sign on the 1 to invert the Throttle axis

//          The Shift Register pins the HAT switch is connected to
#define hat_up 8
#define hat_down 10
#define hat_left 9
#define hat_right 16 //Other shift register

//          Colors for output wires on Right Joystick Handle V1
#define CLOCK_PIN2 10  //Green14
//#define CLOCK_ENABLE_PIN2 10  //White
#define SERIAL_IN_PIN2 5 //Red(Yellow)  ---Blue5
#define LOAD_DATA_PIN2 7  //Blue ---Black7
#define CLOCK_PIN 15  //Green(Black)
//#define CLOCK_ENABLE_PIN 4  //White(Black)
#define SERIAL_IN_PIN 8 //Blue(Black)
#define LOAD_DATA_PIN 6  //Red(Black)
//  New Pins: 4 White(Black), 5 Red(Yellow), 6 Red(Black), 7 Blue, 8 Blue[Black], 10 White, 14 Green, 15 Green[Black]

//#define SCL_PIN 3
//#define SDA_PIN 2

//          End of Configuration

#define deadzone_range_Pitch ((deadzone_lower_Pitch - deadzone_upper_Pitch) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Pitch_range ((Pitch_max_value - Pitch_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Pitch (Pitch_range - deadzone_range_Pitch)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Pitch_offset (Pitch_range + Pitch_min_value + offset_Pitch)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Pitch (Pitch_range  - deadzone_range_Pitch)  //Do not touch - calculate the software max value based on previous configuration
#define min_Pitch (-1 * max_Pitch)  //Do not touch - calculate the software min value based on previous configuration

#define deadzone_range_Roll ((deadzone_lower_Roll - deadzone_upper_Roll) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Roll_range ((Roll_max_value - Roll_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting 
#define offset_Roll (Roll_range - deadzone_range_Roll)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Roll_offset (Roll_range + Roll_min_value + offset_Roll)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Roll (Roll_range + deadzone_range_Roll)  //Do not touch - calculate the software max value based on previous configuration
#define min_Roll (-1 * max_Roll)  //Do not touch - calculate the software min value based on previous configuration

#define deadzone_range_Yaw ((deadzone_lower_Yaw - deadzone_upper_Yaw) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Yaw_range ((Yaw_max_value - Yaw_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Yaw (Yaw_range - deadzone_range_Yaw)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Yaw_offset (Yaw_range + Yaw_min_value + offset_Yaw)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Yaw (Yaw_range - deadzone_range_Yaw)  //Do not touch - calculate the software max value based on previous configuration
#define min_Yaw (-1 * max_Yaw)  //Do not touch - calculate the software min value based on previous configuration

#define deadzone_range_Throttle ((deadzone_lower_Throttle - deadzone_upper_Throttle) / 2)  //Do not touch - calculate half of the range of the deadzone
#define Throttle_range ((Throttle_max_value - Throttle_min_value) / 2)  //Do not touch - calculate half the range of possible input values - used to offset this axis around 0 to allow for inverting
#define offset_Throttle (Throttle_range - deadzone_range_Throttle)  //Do not touch - Calculate the difference between the deadzone middle and value range middle - used to align deadzone with data middle
#define Throttle_offset (Throttle_range + Throttle_min_value + offset_Throttle)  //Do not touch - calculate the offset from zero the center of the range of possible values is
#define max_Throttle (Throttle_range - deadzone_range_Throttle)  //Do not touch - calculate the software max value based on previous configuration
#define min_Throttle (-1 * max_Throttle)  //Do not touch - calculate the software min value based on previous configuration




#include <Joystick.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

Joystick_ Joystick(0x04,JOYSTICK_TYPE_JOYSTICK, //hid report ID, hid device type
  20, 1,                  // Button Count, Hat Switch Count
  true, true, true,     // X , Y, and Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, true,            // No rudder, yes throttle
  false, false, false);  // No accelerator, brake, or steering

int j;
int l;
int k;
int value;
int lastButtonState[5] = {2,2,2,2,2};  //Up, Right, Down, Left, Cleared --  Hat Button State
int lastClickState[20] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};  //The 20 non-HAT buttons



void setup() {
  pinMode(LOAD_DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  //pinMode(CLOCK_ENABLE_PIN, OUTPUT);
  pinMode(SERIAL_IN_PIN, INPUT);
  pinMode(LOAD_DATA_PIN2, OUTPUT);
  pinMode(CLOCK_PIN2, OUTPUT);
  //pinMode(CLOCK_ENABLE_PIN2, OUTPUT);
  pinMode(SERIAL_IN_PIN2, INPUT);

  ads.begin();
//  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV (default)
//  ads.setGain(GAIN_ONE);     // 1x gain   +/- 4.096V  1 bit = 2mV
//  ads.setGain(GAIN_TWO);     // 2x gain   +/- 2.048V  1 bit = 1mV
//  ads.setGain(GAIN_FOUR);    // 4x gain   +/- 1.024V  1 bit = 0.5mV
//  ads.setGain(GAIN_EIGHT);   // 8x gain   +/- 0.512V  1 bit = 0.25mV
//  ads.setGain(GAIN_SIXTEEN); // 16x gain  +/- 0.256V  1 bit = 0.125mV

// Initialize Joystick Library
  Joystick.begin(false); //false = dont send automatically. We will sendState() at the end of the loop
  Joystick.setYAxisRange(min_Pitch, max_Pitch); //Pitch
  Joystick.setXAxisRange(min_Roll, max_Roll); //Roll 10300 - 15350
  Joystick.setZAxisRange(min_Yaw, max_Yaw); //Yaw
  Joystick.setThrottleRange(min_Throttle, max_Throttle);
}

void loop() {
  value = -1;
  //Front Panel Shift Registers (2 daisy-chained)
  //digitalWrite(CLOCK_ENABLE_PIN, 0);  // enable the clock  -- technically not necessary and pin can just be tied to ground in hardware
  digitalWrite(LOAD_DATA_PIN, 0);  // Allow data to load on clock pulse
  digitalWrite(CLOCK_PIN, 0);  // load in data
  digitalWrite(CLOCK_PIN, 1);
  digitalWrite(LOAD_DATA_PIN, 1);  // Stop data updates on clock pulse

  //Handle Shift Register
  //digitalWrite(CLOCK_ENABLE_PIN2, 0);  // enable the clock  -- technically not necessary and pin can just be tied to ground in hardware
  digitalWrite(LOAD_DATA_PIN2, 0);  // Allow data to load on clock pulse
  digitalWrite(CLOCK_PIN2, 0);  // load in data
  digitalWrite(CLOCK_PIN2, 1);
  digitalWrite(LOAD_DATA_PIN2, 1);  // Stop data updates on clock pulse

for(k = 12; k < 20; k++) { // Handle Shift Register with offset to allow for the first two to take the first 13 inputs (3 go to HAT Switch)
  value = digitalRead(SERIAL_IN_PIN2);
  if (k != hat_right - 4) {  // not the HAT switch pin connected to this shift register
    if (lastClickState[k] != value) {  //  Button in new state
      Joystick.setButton(k, value); //pin HIGH means button PRESSED -- Update PC to recognize new state
      lastClickState[k] = value;  //  Update reference array to reflect new state
    }
  }
  else { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[1]) {  // if the value has changed since the last check
          if (value == 1) {Joystick.setHatSwitch(0, 90);}  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[1] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }


  digitalWrite(CLOCK_PIN2, LOW);  //  Toggle Clock Pin for another bit of data
  digitalWrite(CLOCK_PIN2, HIGH);
}

for(j = 0; j < 16; j++) {  //  Front Panel Shift Registers
  value = digitalRead(SERIAL_IN_PIN);
      if (j == hat_up) {  // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[0]) {  // if the value has changed since the last check
          if (value == 1) {Joystick.setHatSwitch(0, 0);}  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[0] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_down) { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[2]) {  // if the value has changed since the last check
          if (value == 1) {Joystick.setHatSwitch(0, 180);}  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[2] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_left) { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[3]) {  // if the value has changed since the last check
          if (value == 1) {Joystick.setHatSwitch(0, 270);}  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[3] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else {  // If not a hat switch pin, it must be a button pin
        l = j;
        if (j > hat_down) {l -= 3;}  //Missing hat switch pins numbering adjustment
        if (lastClickState[l] != value) {  //  if the state of the button has changed
          Joystick.setButton(l, value); //pin HIGH means button PRESSED  -- update the joystick button press state
          lastClickState[l] = value;  //  update reference array with new button state
        }
      }
      if ((lastButtonState[0] == 0)  // Resetting HAT switch if no other state is set and it has not already done so
        && (lastButtonState[1] == 0)
        && (lastButtonState[2] == 0)
        && (lastButtonState[3] == 0)
        && (lastButtonState[4] == 0)){
          Joystick.setHatSwitch(0, -1);
          lastButtonState[4] = 1;  //  Prevent this code from running again until the HAT switch is clicked first
      }

  
  digitalWrite(CLOCK_PIN, LOW);  //  Toggle Clock Pin for another bit of data
  digitalWrite(CLOCK_PIN, HIGH);
}

//Use the 16-bit ADC (ADS1115) connected via I2C to read the 4 encoders (3 hall sensors and 1 potentiometer) instead of using the built in 12-bit ADC
int16_t adc0; // 16 bits ADC read of input A0
adc0 = ads.readADC_SingleEnded(0);  // Yaw 10500 - 17680
int16_t adc1; // 16 bits ADC read of input A1
adc1 = ads.readADC_SingleEnded(1);  // Picth - ?? 11000 - 14500
int16_t adc2; // 16 bits ADC read of input A2
adc2 = ads.readADC_SingleEnded(2);  // Roll 15350 - 10300
int16_t adc3; // 16 bits ADC read of input A3
adc3 = ads.readADC_SingleEnded(3);  // Throttle 0 - 24880

//Prevent the values from exceding the defined limits
if (adc0 > Yaw_max_value - 1) {adc0 = Yaw_max_value - 1;}
if (adc0 < Yaw_min_value + 1) {adc0 = Yaw_min_value + 1;}
if (adc1 > Pitch_max_value - 1) {adc1 = Pitch_max_value - 1;}
if (adc1 < Pitch_min_value + 1) {adc1 = Pitch_min_value + 1;}
if (adc3 > Throttle_max_value - 1) {adc3 = Throttle_max_value - 1;}
if (adc3 < Throttle_min_value + 1) {adc3 = Throttle_min_value + 1;}
if (adc2 > Roll_max_value - 1) {adc2 = Roll_max_value - 1;}
if (adc2 < Roll_min_value + 1) {adc2 = Roll_min_value + 1;}

//Deadzone addition (not always literally though)
if (adc0 < deadzone_lower_Yaw) {
  adc0 += deadzone_range_Yaw + 950;
}
else if (adc0 > deadzone_upper_Yaw) {
  adc0 -= deadzone_range_Yaw + 50;
}
else {
  adc0 = ((0 + Yaw_offset - offset_Yaw));//deadzone_lower_Yaw + deadzone_range_Yaw + Yaw_trim;
}   
adc0 += offset_Yaw;

if (adc1 < deadzone_lower_Pitch) {
  adc1 += deadzone_range_Pitch + 100;
}
else if (adc1 > deadzone_upper_Pitch) {
  adc1 -= deadzone_range_Pitch + 900;
}
else {
  adc1 = ((0 + Pitch_offset - offset_Pitch));//deadzone_range_Pitch + deadzone_lower_Pitch + Pitch_trim;
} 
adc1 += offset_Pitch;  

if (adc3 < deadzone_lower_Throttle) {
  adc3 += deadzone_range_Throttle;
}
else if (adc3 > deadzone_upper_Throttle) {
  adc3 -= deadzone_range_Throttle;
}
else {
  adc3 = ((0 + Throttle_offset - offset_Throttle));//deadzone_lower_Throttle + deadzone_range_Throttle + Throttle_trim;
}  
adc3 += offset_Throttle; 

if (adc2 < deadzone_lower_Roll) {
  adc2 += deadzone_range_Roll + 2500;
}
else if (adc2 > deadzone_upper_Roll) {
  adc2 -= deadzone_range_Roll - 1100;
}
else {
  adc2 = ((0 + Roll_offset - offset_Roll));//deadzone_lower_Roll + deadzone_range_Roll + Roll_trim;
}   
adc2 += offset_Roll;

adc2 = ((adc2 - Roll_offset) * invert_Roll);
adc1 = ((adc1 - Pitch_offset) * invert_Pitch);
adc0 = ((adc0 - Yaw_offset) * invert_Yaw);
adc3 = ((adc3 - Throttle_offset) * invert_Throttle);

if (adc0 < 0) {adc0 = adc0 / 1.5;}
if (adc1 > 0) {adc1 = adc1 / 1.35;}
if (adc2 < 0) {adc2 = adc2 / 2.06;}
if (adc3 > 0) {adc3 = adc3 / 1.003;}

//set analog axes
Joystick.setXAxis(adc2);
Joystick.setYAxis(adc1);
Joystick.setZAxis(adc0);
Joystick.setThrottle(adc3);
  
Joystick.sendState();
delay(10);
}
