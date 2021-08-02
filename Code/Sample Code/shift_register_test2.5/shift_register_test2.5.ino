//Written By: Jordan Kooyman
//	7/2021

#define Mode 0  // 0: 1 Shift Register, 1: 1 Pair of Shift Registers, 2: 2 Seperate Shift Registers, Anything Else: 1 Pair of Shift Registers and a Third Independent Shift Register

#define Delay 100  //  How many milliseconds are waited between each data output (larger is slower)

#define Button_Click_State 1 // Default: 1		The value read by the arduino when a connected button is pressed (i.e. 1 for active-high, 0 for active-low)

#define CLOCK_PIN 15
#define SERIAL_IN_PIN 8
#define LOAD_DATA_PIN 6
#define CLOCK_PIN2 14		// Only used if 2 sets of shift registers are connected
#define SERIAL_IN_PIN2 5	// Only used if 2 sets of shift registers are connected
#define LOAD_DATA_PIN2 7	// Only used if 2 sets of shift registers are connected

int j;
int k;
int value;
int value2;

void setup() {
  pinMode(LOAD_DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(SERIAL_IN_PIN, INPUT);
  pinMode(LOAD_DATA_PIN2, OUTPUT);
  pinMode(CLOCK_PIN2, OUTPUT);
  pinMode(SERIAL_IN_PIN2, INPUT);

Serial.begin(9600);
}

void loop() {
  digitalWrite(LOAD_DATA_PIN, 0);  // Load data into shift register 1
  digitalWrite(CLOCK_PIN, 0);
  digitalWrite(CLOCK_PIN, 1);
  digitalWrite(LOAD_DATA_PIN, 1);

  digitalWrite(LOAD_DATA_PIN2, 0);  // Load data into shift register 2
  digitalWrite(CLOCK_PIN2, 0);
  digitalWrite(CLOCK_PIN2, 1);
  digitalWrite(LOAD_DATA_PIN2, 1);
  
if (Mode == 0) {
	for(j = 0; j < 8; j++) {
	  value = digitalRead(SERIAL_IN_PIN);	// Read in value from shift register
	  if (value == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button Position: ");	// Print out button number and value
	  Serial.println(j);
	  Serial.print("Button Value: ");
	  Serial.println(value);
	  }

	  digitalWrite(CLOCK_PIN, LOW);  // Toggle Clock on Shift Register
	  digitalWrite(CLOCK_PIN, HIGH);
	}
}

else if (Mode == 1) {
	for(j = 0; j < 16; j++) {
	  value = digitalRead(SERIAL_IN_PIN);	// Read in value from shift register
	  if (value == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button Position: ");	// Print out button number and value
	  Serial.println(j);
	  Serial.print("Button Value: ");
	  Serial.println(value);
	  }

	  digitalWrite(CLOCK_PIN, LOW);  // Toggle Clock on Shift Register
	  digitalWrite(CLOCK_PIN, HIGH);
	}
}

else if (Mode == 2) {
	for(j = 0; j < 8; j++) {
	  value = digitalRead(SERIAL_IN_PIN);	// Read in value from shift register
	  if (value == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button Position: ");	// Print out button number and value
	  Serial.println(j);
	  Serial.print("Button Value: ");
	  Serial.println(value);
	  }

	  digitalWrite(CLOCK_PIN, LOW);  // Toggle Clock on Shift Register
	  digitalWrite(CLOCK_PIN, HIGH);
	}
	
	for(k = 0; k < 8; k++) {
	  value2 = digitalRead(SERIAL_IN_PIN2);	// Read in value from shift register
	  if (value2 == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button 2 Position: ");	// Print out button number and value
	  Serial.println(k + 16);
	  Serial.print("Button 2 Value: ");
	  Serial.println(value2);
	  }

	  digitalWrite(CLOCK_PIN2, LOW);  // Toggle Clock on Shift Register 2
	  digitalWrite(CLOCK_PIN2, HIGH);
	}
}

else {
	for(j = 0; j < 16; j++) {
	  value = digitalRead(SERIAL_IN_PIN);	// Read in value from shift register
	  if (value == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button Position: ");	// Print out button number and value
	  Serial.println(j);
	  Serial.print("Button Value: ");
	  Serial.println(value);
	  }

	  digitalWrite(CLOCK_PIN, LOW);  // Toggle Clock on Shift Register
	  digitalWrite(CLOCK_PIN, HIGH);
	}
	
	for(k = 0; k < 8; k++) {
	  value2 = digitalRead(SERIAL_IN_PIN2);	// Read in value from shift register
	  if (value2 == Button_Click_State) {	// If the value matches the click state  --  Comment out this line (and the bracket at the end to print out all button data 
	  Serial.print("Button 2 Position: ");	// Print out button number and value
	  Serial.println(k + 16);
	  Serial.print("Button 2 Value: ");
	  Serial.println(value2);
	  }

	  digitalWrite(CLOCK_PIN2, LOW);  // Toggle Clock on Shift Register 2
	  digitalWrite(CLOCK_PIN2, HIGH);
	}
}

delay(Delay);
}
