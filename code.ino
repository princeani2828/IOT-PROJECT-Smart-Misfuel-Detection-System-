
// Define color sensor pins
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define magneticSensor 3 // Magnetic door sensor connected to pin 2
#define tcs3200PowerPin 9 // Pin to control TCS3200 sensor power

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

int doorState; // 0 - closed, 1 - open

void setup() {
  
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Pulse Width scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Magnetic sensor setup
  pinMode(magneticSensor, INPUT_PULLUP);
  
  // TCS3200 sensor power control setup
  pinMode(tcs3200PowerPin, OUTPUT);
  
  // Turn off TCS3200 sensor initially
  digitalWrite(tcs3200PowerPin, LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  
  // Read the magnetic sensor state
  doorState = digitalRead(magneticSensor);
  
  // If the door is open, turn on the color sensor
  if (doorState == HIGH) {
    digitalWrite(tcs3200PowerPin, HIGH);
    
    // Read Red, Green, and Blue Pulse Widths
    redPW = getRedPW();
    delay(100); // Short delay for stability
    greenPW = getGreenPW();
    delay(100); // Short delay for stability
    bluePW = getBluePW();
    delay(100); // Short delay for stability
    
    // Print current readings
    Serial.print("Red PW = ");
    Serial.print(redPW);
    Serial.print(", Green PW = ");
    Serial.print(greenPW);
    Serial.print(", Blue PW = ");
    Serial.println(bluePW);
    
    // Determine whether the object is Petrol (blue) or Diesel (black)
    detectFuelType(redPW, greenPW, bluePW);
  }
  else {
    // If the door is closed, turn off the color sensor
    digitalWrite(tcs3200PowerPin, LOW);
    Serial.println("Color sensor is off (door closed).");
  }
  
  // Add a short delay before the next reading
  delay(500);
}

// Function to read Red Pulse Widths
int getRedPW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int PW = pulseIn(sensorOut, LOW);
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int PW = pulseIn(sensorOut, LOW);
  return PW;
}

// Function to read Blue Pulse Widths
int getBluePW() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int PW = pulseIn(sensorOut, LOW);
  return PW;
}

// Function to detect whether the object is Petrol (blue) or Diesel (black)
void detectFuelType(int redPW, int greenPW, int bluePW) {
  
  // Thresholds for detection based on your sensor's readings
  int petrolThresholdRed = 320;   // Adjusted based on your blue color (petrol) readings
  int petrolThresholdGreen = 130; // Adjusted based on your blue color (petrol) readings
  int petrolThresholdBlue = 90;  // Adjusted based on your blue color (petrol) readings

  int dieselThresholdRed = 320;   // Adjusted based on your black color (diesel) readings
  int dieselThresholdGreen = 100; // Adjusted based on your black color (diesel) readings
  int dieselThresholdBlue = 90;  // Adjusted based on your black color (diesel) readings
  
  // Check for Diesel (based on your black detection values)
  if (redPW < dieselThresholdRed && greenPW > dieselThresholdGreen && bluePW < dieselThresholdBlue) {
    Serial.println("Detected Fuel: Diesel");
  }
  // Check for Petrol (based on your blue detection values)
  else if (redPW < petrolThresholdRed && greenPW < petrolThresholdGreen && bluePW > petrolThresholdBlue) {
    Serial.println("Detected Fuel: Petrol");
  }
  else {
    Serial.println("Detected Fuel: Other");
  }
}


