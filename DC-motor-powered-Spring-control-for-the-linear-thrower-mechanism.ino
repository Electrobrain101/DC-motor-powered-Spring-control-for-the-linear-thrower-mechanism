// Define pin numbers
const int vibrationSensorPin = 2;   // Vibration sensor input pin (digital pin)
const int buttonPin = 3;            // Button input pin for auxiliary trigger
const int relayPin = 9;             // Relay output pin
const int resetButtonPin = 5;       // Reset button input pin

  // Define relay state
bool relayState = false;

unsigned long lastTriggerTime = 0;    // Time of the last trigger
unsigned long debounceDelay = 8000;    // Debounce delay for vibration sensor and button (in milliseconds)
unsigned long relayDuration = 900;   // Relay on duration in milliseconds (2 seconds)
unsigned long lastButtonPressTime = 0;  // Last time button was pressed
unsigned long triggerDelay = 8000;

void setup() {
  // Initialize pin modes
  pinMode(vibrationSensorPin, INPUT);  // Digital input for vibration sensor
  pinMode(buttonPin, INPUT_PULLUP);    // Digital input for button with internal pull-up
  pinMode(relayPin, OUTPUT);           // Digital output for relay
  pinMode(resetButtonPin, INPUT_PULLUP);  // Set reset button with internal pull-up
  
  // Start with relay off
  digitalWrite(relayPin, LOW);
  
  // Serial monitor for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Check for hardware reset button press
  if (digitalRead(resetButtonPin) == LOW) {
    resetArduino(); // Reset Arduino if the reset button is pressed
  }

  // Read vibration sensor (digital HIGH means vibration detected)
  if (digitalRead(vibrationSensorPin) == HIGH && millis() - lastTriggerTime > debounceDelay) {
    lastTriggerTime = millis();  // Update last trigger time
    //if (millis() - lastTriggerTime > triggerDelay){
    activateRelay();             // Activate the relay
    //}
  }


  // Check if the button is pressed (with debounce)
  if (digitalRead(buttonPin) == LOW && millis() - lastButtonPressTime > debounceDelay) {
    lastButtonPressTime = millis();  // Update the last button press time
    activateRelay();                 // Activate the relay
  }
}

// Function to activate the relay for 2 seconds
void activateRelay() {
  if (!relayState) {  // Only activate if the relay is not already on
    relayState = true;
    digitalWrite(relayPin, HIGH);  // Turn on relay
    Serial.println("Relay ON");    // Optional debug message
    delay(relayDuration);          // Relay stays on for 2 seconds
    digitalWrite(relayPin, LOW);   // Turn off relay
    relayState = false;
    Serial.println("Relay OFF");   // Optional debug message
  }
}

// Function to reset the Arduino via software
void resetArduino() {
  asm volatile ("  jmp 0");  // Jump to address 0, effectively resetting the Arduino
}
