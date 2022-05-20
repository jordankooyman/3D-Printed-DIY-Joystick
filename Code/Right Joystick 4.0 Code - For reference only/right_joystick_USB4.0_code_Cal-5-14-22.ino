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

#define Deadzone_max_propotion 1 // 1 out of 'this number' is the largest portion the deadzone can be of the total input range - set to 1 to ignore
#define Output_delay 10 // How long to pause between read/update cycles
//#define Serial_Mode 1 // Comment out to use Joystick library, otherwise outputs data to Serial monitor at 9600 baud: 1 - Raw Data, 2 - Processed Data

//          Min/Max Values, Deadzone Min/Max Values, and Inversion Configuration
#define Pitch_max_value 14500    // Set to the max value of Pitch Axis
#define Pitch_min_value 12000    // Set to the min value of Pitch Axis
#define Pitch_max_deadzone 13500 // Set to the max value of the desired deadzone
#define Pitch_min_deadzone 12700 // Set to the min value of the desired deadzone
#define Pitch_ADC 1              // Set to the adc pin number this axis is connected to (between 0 and 3 inclusive)
#define invert_Pitch_axis -1     // Change the sign on the 1 to invert the Pitch axis

#define Roll_max_value 17650    // Set to the max value of Roll Axis
#define Roll_min_value 10800    // Set to the min value of Roll Axis
#define Roll_max_deadzone 14100 // Set to the max value of the desired deadzone
#define Roll_min_deadzone 12600 // Set to the min value of the desired deadzone
#define Roll_ADC 2              // Set to the adc pin number this axis is connected to (between 0 and 3 inclusive)
#define invert_Roll_axis -1     // Change the sign on the 1 to invert the Roll axis

#define Yaw_max_value 15000    // Set to the max value of Yaw Axis
#define Yaw_min_value 11200    // Set to the min value of Yaw Axis
#define Yaw_max_deadzone 13000 // Set to the max value of the desired deadzone
#define Yaw_min_deadzone 12300 // Set to the min value of the desired deadzone
#define Yaw_ADC 0              // Set to the adc pin number this axis is connected to (between 0 and 3 inclusive)
#define invert_Yaw_axis 1     // Change the sign on the 1 to invert the Yaw axis

#define Throttle_max_value 24500    // Set to the max value of Throttle Axis
#define Throttle_min_value 0    // Set to the min value of Throttle Axis
#define Throttle_max_deadzone 12105 // Set to the max value of the desired deadzone
#define Throttle_min_deadzone 12103 // Set to the min value of the desired deadzone
#define Throttle_ADC 3              // Set to the adc pin number this axis is connected to (between 0 and 3 inclusive)
#define invert_Throttle_axis 1     // Change the sign on the 1 to invert the Throttle axis


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


//          Axis value calculations - Do not modify

#if Deadzone_max_propotion < 1 // Ensure some deadzone range checking is performed
#error Deadzone_max_propotion must be at least 1
#endif

// Pitch calculations
#define Pitch_deadzone_Range ((Pitch_max_deadzone - Pitch_min_deadzone) / 2) // Calculate based on input min and max values
#define Pitch_center_location (Pitch_min_deadzone + Pitch_deadzone_Range) // Calculate based on deadzone values

#define Pitch_range_up (Pitch_max_value - Pitch_center_location)
#define Pitch_range_down (Pitch_center_location - Pitch_min_value)

// Use the smaller range-of-motion axis to determine input range
#if Pitch_range_up > Pitch_range_down // Pitch min is limiting axis
#define Pitch_range (Pitch_range_down)
#define Pitch_max_offset_factor (Pitch_range_up / Pitch_range_down) // Used to scale max values to within range (larger / smaller)
#else // Pitch max is limiting axis
#define Pitch_range (Pitch_range_up)
#define Pitch_min_offset_factor (Pitch_range_down / Pitch_range_up) // Used to scale min values to within range (larger / smaller)
#endif

// Pitch deadzone range checking
#if ((Pitch_center_location + Pitch_range) < (Pitch_max_deadzone * Deadzone_max_propotion))
#error Pitch max deadzone is too large.
#endif
#if ((Pitch_center_location - Pitch_range) > (Pitch_min_deadzone / Deadzone_max_propotion))
#error Pitch min deadzone is too small.
#endif
#if (Pitch_max_deadzone <= Pitch_min_deadzone)
#error Pitch deadzone range too small (or negative)
#endif

#define max_Pitch (Pitch_range + 1)  // Maximum possible value to be output
#define min_Pitch (-1 * max_Pitch)  // Minimum possible value to be output



// Roll calculations
#define Roll_deadzone_Range ((Roll_max_deadzone - Roll_min_deadzone) / 2) // Calculate based on input min and max values
#define Roll_center_location (Roll_min_deadzone + Roll_deadzone_Range) // Calculate based on deadzone values

#define Roll_range_up (Roll_max_value - Roll_center_location)
#define Roll_range_down (Roll_center_location - Roll_min_value)

// Use the smaller range-of-motion axis to determine input range
#if Roll_range_up > Roll_range_down // Roll min is limiting axis
#define Roll_range (Roll_range_down)
#define Roll_max_offset_factor (Roll_range_up / Roll_range_down) // Used to scale max values to within range (larger / smaller)
#else // Roll max is limiting axis
#define Roll_range (Roll_range_up)
#define Roll_min_offset_factor (Roll_range_down / Roll_range_up) // Used to scale min values to within range (larger / smaller)
#endif

// Roll deadzone range checking
#if ((Roll_center_location + Roll_range) < (Roll_max_deadzone * Deadzone_max_propotion))
#error Roll max deadzone is too large.
#endif
#if ((Roll_center_location - Roll_range) > (Roll_min_deadzone / Deadzone_max_propotion))
#error Roll min deadzone is too small.
#endif
#if (Roll_max_deadzone <= Roll_min_deadzone)
#error Roll deadzone range too small (or negative)
#endif

#define max_Roll (Roll_range + 1)  // Maximum possible value to be output
#define min_Roll (-1 * max_Roll)  // Minimum possible value to be output



// Yaw calculations
#define Yaw_deadzone_Range ((Yaw_max_deadzone - Yaw_min_deadzone) / 2) // Calculate based on input min and max values
#define Yaw_center_location (Yaw_min_deadzone + Yaw_deadzone_Range) // Calculate based on deadzone values

#define Yaw_range_up (Yaw_max_value - Yaw_center_location)
#define Yaw_range_down (Yaw_center_location - Yaw_min_value)

// Use the smaller range-of-motion axis to determine input range
#if Yaw_range_up > Yaw_range_down // Yaw min is limiting axis
#define Yaw_range (Yaw_range_down)
#define Yaw_max_offset_factor (Yaw_range_up / Yaw_range_down) // Used to scale max values to within range (larger / smaller)
#else // Yaw max is limiting axis
#define Yaw_range (Yaw_range_up)
#define Yaw_min_offset_factor (Yaw_range_down / Yaw_range_up) // Used to scale min values to within range (larger / smaller)
#endif

// Yaw deadzone range checking
#if ((Yaw_center_location + Yaw_range) < (Yaw_max_deadzone * Deadzone_max_propotion))
#error Yaw max deadzone is too large.
#endif
#if ((Yaw_center_location - Yaw_range) > (Yaw_min_deadzone / Deadzone_max_propotion))
#error Yaw min deadzone is too small.
#endif
#if (Yaw_max_deadzone <= Yaw_min_deadzone)
#error Yaw deadzone range too small (or negative)
#endif

#define max_Yaw (Yaw_range + 1)  // Maximum possible value to be output
#define min_Yaw (-1 * max_Yaw)  // Minimum possible value to be output



// Throttle calculations
#define Throttle_deadzone_Range ((Throttle_max_deadzone - Throttle_min_deadzone) / 2) // Calculate based on input min and max values
#define Throttle_center_location (Throttle_min_deadzone + Throttle_deadzone_Range) // Calculate based on deadzone values

#define Throttle_range_up (Throttle_max_value - Throttle_center_location)
#define Throttle_range_down (Throttle_center_location - Throttle_min_value)

// Use the smaller range-of-motion axis to determine input range
#if Throttle_range_up > Throttle_range_down // Throttle min is limiting axis
#define Throttle_range (Throttle_range_down)
#define Throttle_max_offset_factor (Throttle_range_up / Throttle_range_down) // Used to scale max values to within range (larger / smaller)
#else // Throttle max is limiting axis
#define Throttle_range (Throttle_range_up)
#define Throttle_min_offset_factor (Throttle_range_down / Throttle_range_up) // Used to scale min values to within range (larger / smaller)
#endif

// Throttle deadzone range checking
#if ((Throttle_center_location + Throttle_range) < (Throttle_max_deadzone * Deadzone_max_propotion))
#error Throttle max deadzone is too large.
#endif
#if ((Throttle_center_location - Throttle_range) > (Throttle_min_deadzone / Deadzone_max_propotion))
#error Throttle min deadzone is too small.
#endif
#if (Throttle_max_deadzone <= Throttle_min_deadzone)
#error Throttle deadzone range too small (or negative)
#endif

#define max_Throttle (Throttle_range + 1)  // Maximum possible value to be output
#define min_Throttle (-1 * max_Throttle)  // Minimum possible value to be output


//        End of Axis Value Calculations

#ifndef Serial_Mode
#include <Joystick.h>
#endif
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

#ifndef Serial_Mode
Joystick_ Joystick(0x04,JOYSTICK_TYPE_JOYSTICK, //hid report ID, hid device type
  20, 1,                  // Button Count, Hat Switch Count
  true, true, true,     // X , Y, and Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, true,            // No rudder, yes throttle
  false, false, false);  // No accelerator, brake, or steering
#endif

int j;
int l;
int k;
int value;
int lastButtonState[5] = {2,2,2,2,2};  //Up, Right, Down, Left, Cleared --  Hat Button State
int lastClickState[20] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};  //The 20 non-HAT buttons
#ifdef Serial_Mode
int Axis_min[4] = {30000,30000,30000,30000}; //X, Y, Z, Throttle
int Axis_max[4] = {0,0,0,0}; //X, Y, Z, Throttle
#endif



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
  #ifndef Serial_Mode
  Joystick.begin(false); //false = dont send automatically. We will sendState() at the end of the loop
  Joystick.setYAxisRange(min_Pitch, max_Pitch); // Pitch
  Joystick.setXAxisRange(min_Roll, max_Roll);   // Roll
  Joystick.setZAxisRange(min_Yaw, max_Yaw);     // Yaw
  Joystick.setThrottleRange(min_Throttle, max_Throttle);
  #else
  Serial.begin(9600);
  #endif
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
      #ifdef Serial_Mode
      Serial.print("Joystick.setButton("); //pin HIGH means button PRESSED
      Serial.print(k);
      Serial.print(", ");
      Serial.print(value);
      Serial.println(")");
      #else
      Joystick.setButton(k, value); //pin HIGH means button PRESSED -- Update the joystick button press state
      #endif
      lastClickState[k] = value;  //  Update reference array to reflect new state
    }
  }
  else { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[1]) {  // if the value has changed since the last check
          if (value == 1) 
          {
            #ifdef Serial_Mode
            Serial.println("Joystick.setHatSwitch(0, 90)");
            #else
            Joystick.setHatSwitch(0, 90);
            #endif
          }  //  if the value is not release (because there is seperate code to release later on)
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
          if (value == 1)
          {
            #ifdef Serial_Mode
            Serial.println("Joystick.setHatSwitch(0, 0)");
            #else
            Joystick.setHatSwitch(0, 0);
            #endif
          }  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[0] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_down) { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[2]) {  // if the value has changed since the last check
          if (value == 1) 
          {
            #ifdef Serial_Mode
            Serial.println("Joystick.setHatSwitch(0, 180)");
            #else
            Joystick.setHatSwitch(0, 180);
            #endif
          }  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[2] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else if (j == hat_left) { // if hat switch pin (on shift register, not arduino)
        if (value != lastButtonState[3]) {  // if the value has changed since the last check
          if (value == 1) 
          {
            #ifdef Serial_Mode
            Serial.println("Joystick.setHatSwitch(0, 270)");
            #else
            Joystick.setHatSwitch(0, 270);
            #endif
          }  //  if the value is not release (because there is seperate code to release later on)
          lastButtonState[3] = value;  //  update reference array with new position state
          lastButtonState[4] = 0;  //  Allow the releasing code to run when all other HAT switch inputs are released
        }
      }
      else {  // If not a hat switch pin, it must be a button pin
        l = j;
        if (j > hat_down) {l -= 3;}  //Missing hat switch pins numbering adjustment
        if (lastClickState[l] != value) {  //  if the state of the button has changed
          #ifdef Serial_Mode
          Serial.print("Joystick.setButton("); //pin HIGH means button PRESSED
          Serial.print(l + 1);
          Serial.print(", ");
          Serial.print(value);
          Serial.println(")");
          #else
          Joystick.setButton(l, value); //pin HIGH means button PRESSED  -- update the joystick button press state
          #endif
          lastClickState[l] = value;  //  update reference array with new button state
        }
      }
      if ((lastButtonState[0] == 0)  // Resetting HAT switch if no other state is set and it has not already done so
        && (lastButtonState[1] == 0)
        && (lastButtonState[2] == 0)
        && (lastButtonState[3] == 0)
        && (lastButtonState[4] == 0)){
          #ifdef Serial_Mode
          Serial.println("Joystick.setHatSwitch(0, -1)");
          #else
          Joystick.setHatSwitch(0, -1);
          #endif
          lastButtonState[4] = 1;  //  Prevent this code from running again until the HAT switch is clicked first
      }

  
  digitalWrite(CLOCK_PIN, LOW);  //  Toggle Clock Pin for another bit of data
  digitalWrite(CLOCK_PIN, HIGH);
}


// Use the 16-bit ADC (ADS1115) connected via I2C to read the 4 encoders (3 hall sensors and 1 potentiometer (optionally)) instead of using the built in 12-bit ADC - stored in 32 bit int to allow for necessary integer math
int32_t YawValue; // 16 bits ADC read of input A0
YawValue = ads.readADC_SingleEnded(Yaw_ADC);
int32_t PitchValue; // 16 bits ADC read of input A1
PitchValue = ads.readADC_SingleEnded(Pitch_ADC);
int32_t RollValue; // 16 bits ADC read of input A2
RollValue = ads.readADC_SingleEnded(Roll_ADC);
int32_t ThrottleValue; // 16 bits ADC read of input A3
ThrottleValue = ads.readADC_SingleEnded(Throttle_ADC);

// Unprocessed data Serial Output
#ifdef Serial_Mode
#if Serial_Mode <= 1
// Update recorded min value
if (YawValue < Axis_min[0]) {
  Axis_min[0] = YawValue;
}
if (YawValue > Axis_max[0]) {
  Axis_max[0] = YawValue;
}
if (PitchValue < Axis_min[1]) {
  Axis_min[1] = PitchValue;
}
if (PitchValue > Axis_max[1]) {
  Axis_max[1] = PitchValue;
}
if (RollValue < Axis_min[2]) {
  Axis_min[2] = RollValue;
}
if (RollValue > Axis_max[2]) {
  Axis_max[2] = RollValue;
}
if (ThrottleValue < Axis_min[3]) {
  Axis_min[3] = ThrottleValue;
}
if (ThrottleValue > Axis_max[3]) {
  Axis_max[3] = ThrottleValue;
}
Serial.print("Yaw (raw adc"); Serial.print(Yaw_ADC); Serial.print("): "); Serial.print(YawValue);  Serial.print("     Max: ");  Serial.print(Axis_max[0]);  Serial.print("  Min: ");  Serial.println(Axis_min[0]);
Serial.print("Pitch (raw adc"); Serial.print(Pitch_ADC); Serial.print("): ");  Serial.print(PitchValue);  Serial.print("     Max: ");  Serial.print(Axis_max[1]);  Serial.print("  Min: ");  Serial.println(Axis_min[1]);
Serial.print("Roll (raw adc"); Serial.print(Roll_ADC); Serial.print("): ");  Serial.print(RollValue);  Serial.print("     Max: ");  Serial.print(Axis_max[2]);  Serial.print("  Min: ");  Serial.println(Axis_min[2]);
Serial.print("Throttle (raw adc"); Serial.print(Throttle_ADC); Serial.print("): ");  Serial.print(ThrottleValue);  Serial.print("     Max: ");  Serial.print(Axis_max[3]);  Serial.print("  Min: ");  Serial.println(Axis_min[3]);
#endif
#endif

// Pitch input processing
if (PitchValue >= Pitch_min_deadzone && PitchValue <= Pitch_max_deadzone) {
  PitchValue = Pitch_center_location;
}
else { // Not within deadzone
  // Shift values to have no deadzone in output
  if (PitchValue > Pitch_center_location)
    PitchValue -= Pitch_deadzone_Range;
  else
    PitchValue += Pitch_deadzone_Range;  // Shift values to have no deadzone in output
  
  #ifdef Pitch_max_offset_factor // If the upper range needs to be scaled
  if (PitchValue > Pitch_center_location) // If above center, apply scaling to difference only
    PitchValue = ((PitchValue - Pitch_center_location) * Pitch_range_down / Pitch_range_down) + Pitch_center_location;
  #else//Pitch_min_offset_factor // If the lower range needs to be scaled
  if (PitchValue < Pitch_center_location) // If below center, apply scaling to difference only
    PitchValue = ((PitchValue - Pitch_center_location) * Pitch_range_up / Pitch_range_down) + Pitch_center_location;
  #endif
} 


// Roll input processing
if (RollValue >= Roll_min_deadzone && RollValue <= Roll_max_deadzone) {
  RollValue = Roll_center_location;
}
else { // Not within deadzone
  // Shift values to have no deadzone in output
  if (RollValue > Roll_center_location)
    RollValue -= Roll_deadzone_Range;
  else
    RollValue += Roll_deadzone_Range;
  
  #ifdef Roll_max_offset_factor // If the upper range needs to be scaled
  if (RollValue > Roll_center_location) // If above center, apply scaling to difference only
    RollValue = ((RollValue - Roll_center_location) * Roll_range_down / Roll_range_up) + Roll_center_location;
  #else//Roll_min_offset_factor // If the lower range needs to be scaled
  if (RollValue < Roll_center_location) // If below center, apply scaling to difference only
    RollValue = ((RollValue - Roll_center_location) * Roll_range_up / Roll_range_down) + Roll_center_location;
  #endif
  
}


// Yaw input processing
if (YawValue >= Yaw_min_deadzone && YawValue <= Yaw_max_deadzone) {
  YawValue = Yaw_center_location;
}
else { // Not within deadzone
  // Shift values to have no deadzone in output
  if (YawValue > Yaw_center_location)
    YawValue -= Yaw_deadzone_Range;
  else
    YawValue += Yaw_deadzone_Range;
  
  #ifdef Yaw_max_offset_factor // If the upper range needs to be scaled
  if (YawValue > Yaw_center_location) // If above center, apply scaling to difference only
    YawValue = ((YawValue - Yaw_center_location) * Yaw_range_down / Yaw_range_up) + Yaw_center_location;
  #else//Yaw_min_offset_factor // If the lower range needs to be scaled
  if (YawValue < Yaw_center_location) // If below center, apply scaling to difference only
    YawValue = ((YawValue - Yaw_center_location) * Yaw_range_up / Yaw_range_down) + Yaw_center_location;
  #endif
}


// Throttle input processing
if (ThrottleValue >= Throttle_min_deadzone && ThrottleValue <= Throttle_max_deadzone) {
  ThrottleValue = Throttle_center_location;
}
else { // Not within deadzone
  // Shift values to have no deadzone in output
  if (ThrottleValue > Throttle_center_location)
    ThrottleValue -= Throttle_deadzone_Range;
  else
    ThrottleValue += Throttle_deadzone_Range;
    
  #ifdef Throttle_max_offset_factor // If the upper range needs to be scaled
  if (ThrottleValue > Throttle_center_location) // If above center, apply scaling to difference only
    ThrottleValue = ((ThrottleValue - Throttle_center_location) * Throttle_range_down / Throttle_range_up) + Throttle_center_location;
  #else//Throttle_min_offset_factor // If the lower range needs to be scaled
  if (ThrottleValue < Throttle_center_location)
    ThrottleValue = ((ThrottleValue - Throttle_center_location) * Throttle_range_up / Throttle_range_down) + Throttle_center_location;
  #endif
}

// Center the range of values on zero and optionally invert (for input inversion)
RollValue = ((RollValue - Roll_center_location) * invert_Roll_axis);
PitchValue = ((PitchValue - Pitch_center_location) * invert_Pitch_axis);
YawValue = ((YawValue - Yaw_center_location) * invert_Yaw_axis);
ThrottleValue = ((ThrottleValue - Throttle_center_location) * invert_Throttle_axis);


//Prevent the values from exceding the defined limits
if (YawValue >= max_Yaw) YawValue = max_Yaw - 1;
if (YawValue <= min_Yaw) YawValue = min_Yaw + 1;
if (PitchValue >= max_Pitch) PitchValue = max_Pitch - 1;
if (PitchValue <= min_Pitch) PitchValue = min_Pitch + 1;
if (ThrottleValue >= max_Throttle) ThrottleValue = max_Throttle - 1;
if (ThrottleValue <= min_Throttle) ThrottleValue = min_Throttle + 1;
if (RollValue >= max_Roll) RollValue = max_Roll - 1;
if (RollValue <= min_Roll) RollValue = min_Roll + 1;

// Processed Data Output (either Serial or Joystick)
#ifdef Serial_Mode
#if Serial_Mode > 1
// Update recorded min value
if (YawValue < Axis_min[0]) {
  Axis_min[0] = YawValue;
}
if (YawValue > Axis_max[0]) {
  Axis_max[0] = YawValue;
}
if (PitchValue < Axis_min[1]) {
  Axis_min[1] = PitchValue;
}
if (PitchValue > Axis_max[1]) {
  Axis_max[1] = PitchValue;
}
if (RollValue < Axis_min[2]) {
  Axis_min[2] = RollValue;
}
if (RollValue > Axis_max[2]) {
  Axis_max[2] = RollValue;
}
if (ThrottleValue < Axis_min[3]) {
  Axis_min[3] = ThrottleValue;
}
if (ThrottleValue > Axis_max[3]) {
  Axis_max[3] = ThrottleValue;
}
/*
Serial.print("Yaw Range:");Serial.println(Yaw_range);
Serial.print("Max Yaw:");Serial.println(max_Yaw);
Serial.print("Min Yaw:");Serial.println(min_Yaw);
Serial.print("Pitch Range:");Serial.println(Pitch_range);
Serial.print("Max Pitch:");Serial.println(max_Pitch);
Serial.print("Min Pitch:");Serial.println(min_Pitch);
Serial.print("Throttle Range:");Serial.println(Throttle_range);
Serial.print("Max Throttle:");Serial.println(max_Throttle);
Serial.print("Min Throttle:");Serial.println(min_Throttle);
Serial.print("Roll Range:");Serial.println(Roll_range);
Serial.print("Max Roll:");Serial.println(max_Roll);
Serial.print("Min Roll:");Serial.println(min_Roll);
*/
Serial.print("Yaw (adc"); Serial.print(Yaw_ADC); Serial.print("): "); Serial.print(YawValue);  Serial.print("     Max: ");  Serial.print(Axis_max[0]);  Serial.print("  Min: ");  Serial.println(Axis_min[0]);
Serial.print("Pitch (adc"); Serial.print(Pitch_ADC); Serial.print("): ");  Serial.print(PitchValue);  Serial.print("     Max: ");  Serial.print(Axis_max[1]);  Serial.print("  Min: ");  Serial.println(Axis_min[1]);
Serial.print("Roll (adc"); Serial.print(Roll_ADC); Serial.print("): ");  Serial.print(RollValue);  Serial.print("     Max: ");  Serial.print(Axis_max[2]);  Serial.print("  Min: ");  Serial.println(Axis_min[2]);
Serial.print("Throttle (adc"); Serial.print(Throttle_ADC); Serial.print("): ");  Serial.print(ThrottleValue);  Serial.print("     Max: ");  Serial.print(Axis_max[3]);  Serial.print("  Min: ");  Serial.println(Axis_min[3]);
#endif
Serial.println(); // Blank line between iterations
#else
//set analog axes
Joystick.setXAxis(RollValue);
Joystick.setYAxis(PitchValue);
Joystick.setZAxis(YawValue);
Joystick.setThrottle(ThrottleValue);

//send new data packet to PC
Joystick.sendState();
#endif


//slow down processing to a reasonable speed
delay(Output_delay);
}
