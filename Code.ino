// Pin Definitions
const int smokePin = 2;         // Digital pin for smoke sensor
const int flamePin = 3;         // Digital pin for flame sensor
const int fanIN1 = 5;           // Pin connected to L298N IN1 for fan
const int fanIN2 = 6;           // Pin connected to L298N IN2 for fan
const int pumpIN3 = 7;          // Pin connected to L298N IN3 for water pump
const int pumpIN4 = 8;          // Pin connected to L298N IN4 for water pump
const int buzzerPin = 9;        // Pin connected to buzzer

void setup() {
  pinMode(smokePin, INPUT);     // Smoke sensor input
  pinMode(flamePin, INPUT);     // Flame sensor input
  pinMode(fanIN1, OUTPUT);      // Fan IN1 pin
  pinMode(fanIN2, OUTPUT);      // Fan IN2 pin
  pinMode(pumpIN3, OUTPUT);     // Pump IN3 pin
  pinMode(pumpIN4, OUTPUT);     // Pump IN4 pin
  pinMode(buzzerPin, OUTPUT);   // Buzzer pin
  
  // Initially turn everything off
  deactivateFan();
  deactivatePump();
  deactivateBuzzer();

  Serial.begin(9600);           // Begin serial communication for debugging
}

void loop() {
  int smokeDetected = digitalRead(smokePin);   // Read smoke sensor
  int flameDetected = digitalRead(flamePin);   // Read flame sensor

  Serial.print("Flame Detected: ");
  Serial.println(flameDetected);  // Print flame detection state

  if (smokeDetected == HIGH && flameDetected == LOW) {
    // Both smoke and flame detected, run fan, pump, and buzzer
    Serial.println("Both smoke and flame detected, activating all systems.");
    activateFan();
    activatePump();
    activateBuzzer();
  } 
  else if (flameDetected == LOW) {
    // Flame detected, run water pump and sound buzzer
    Serial.println("Flame detected, activating water pump and buzzer.");
    activatePump();
    activateBuzzer();
    deactivateFan();
  } 
  else if (smokeDetected == HIGH) {
    // Smoke detected, run fan as exhaust
    Serial.println("Smoke detected, activating exhaust fan.");
    activateFan();
    deactivatePump();
    deactivateBuzzer();
  } 
  else {
    // No smoke or flame detected, turn everything off
    deactivateFan();
    deactivatePump();
    deactivateBuzzer();
  }
  
  delay(500);  // Delay to prevent sensor bouncing
}

// Function to activate fan using L298N motor driver
void activatePump() {
  digitalWrite(fanIN1, HIGH);  // Fan ON
  digitalWrite(fanIN2, LOW);   // Set direction (can be adjusted if needed)
}

// Function to deactivate fan
void deactivatePump() {
  digitalWrite(fanIN1, LOW);   // Fan OFF
  digitalWrite(fanIN2, LOW);
}

// Function to activate water pump using L298N motor driver
void activateFan() {
  digitalWrite(pumpIN3, HIGH);  // Pump ON
  digitalWrite(pumpIN4, LOW);   // Set direction (can be adjusted if needed)
}

// Function to deactivate water pump
void deactivateFan() {
  digitalWrite(pumpIN3, LOW);   // Pump OFF
  digitalWrite(pumpIN4, LOW);
}

// Function to activate buzzer directly through Arduino
void activateBuzzer() {
  digitalWrite(buzzerPin, HIGH);  // Buzzer ON
}

// Function to deactivate buzzer
void deactivateBuzzer() {
  digitalWrite(buzzerPin, LOW);   // Buzzer OFF
}

