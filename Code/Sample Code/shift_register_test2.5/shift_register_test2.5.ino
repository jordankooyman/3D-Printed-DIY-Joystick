#define CLOCK_PIN2 14  //Green
#define CLOCK_ENABLE_PIN2 10  //White
#define SERIAL_IN_PIN2 5 //Red(Yellow)  ---Blue
#define LOAD_DATA_PIN2 7  //Blue ---Black
#define CLOCK_PIN 15  //Green(Black)
#define CLOCK_ENABLE_PIN 4  //White(Black)
#define SERIAL_IN_PIN 8 //Blue(Black)
#define LOAD_DATA_PIN 6  //Red(Black)

int j;
int k;
int value;
int value2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LOAD_DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(CLOCK_ENABLE_PIN, OUTPUT);
  pinMode(SERIAL_IN_PIN, INPUT);
  pinMode(LOAD_DATA_PIN2, OUTPUT);
  pinMode(CLOCK_PIN2, OUTPUT);
  pinMode(CLOCK_ENABLE_PIN2, OUTPUT);
  pinMode(SERIAL_IN_PIN2, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t dataIn = 0;
  byte dataIn2 = 0;
  digitalWrite(CLOCK_ENABLE_PIN, 0);
  digitalWrite(LOAD_DATA_PIN, 0);
  digitalWrite(CLOCK_PIN, 0);
  digitalWrite(CLOCK_PIN, 1);
  digitalWrite(LOAD_DATA_PIN, 1);

  digitalWrite(CLOCK_ENABLE_PIN2, 0);
  digitalWrite(LOAD_DATA_PIN2, 0);
  digitalWrite(CLOCK_PIN2, 0);
  digitalWrite(CLOCK_PIN2, 1);
  digitalWrite(LOAD_DATA_PIN2, 1);

for(j = 0; j < 16; j++) {
  value = digitalRead(SERIAL_IN_PIN);
  if (value == 1) {
  Serial.print("Button Position: ");
  Serial.println(j);
  Serial.print("Button Value: ");
  Serial.println(value);
  }
  if (value) {
    int a = (1 << j);
    
    dataIn = dataIn | a;
    
  }

  digitalWrite(CLOCK_PIN, LOW);
  digitalWrite(CLOCK_PIN, HIGH);
}

for(k = 0; k < 8; k++) {
  value2 = digitalRead(SERIAL_IN_PIN2);
  if (value2 == 1) {
  Serial.print("Button2 Position: ");
  Serial.println(k + 16);
  Serial.print("Button Value2: ");
  Serial.println(value2);
  }
  if (value2) {
    int a = (1 << k) + 16;
    
    dataIn = dataIn | a;
    
  }

  digitalWrite(CLOCK_PIN2, LOW);
  digitalWrite(CLOCK_PIN2, HIGH);
}
delay(100);
}
