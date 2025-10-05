#include <Servo.h>

const int pirPin = 2;
const int buttonPin = 7;
const int potPin = A0;

const int buzzerPins[] = {3, 10, 11, 12};
const int numBuzzers = 4;

const int ledPin = 8;  // LED pin

Servo deterrentServo;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  
  for (int i = 0; i < numBuzzers; i++) {
    pinMode(buzzerPins[i], OUTPUT);
    digitalWrite(buzzerPins[i], LOW);
  }

  deterrentServo.attach(9);
  deterrentServo.write(90); // Centered initially

  Serial.begin(9600);
}

void loop() {
  bool pirDetected = digitalRead(pirPin);
  bool buttonPressed = digitalRead(buttonPin);

  if (pirDetected || buttonPressed) {
    int potValue = analogRead(potPin);  // 0–1023
    int angle;

    // Map potentiometer to direction angle (left to right)
    if (potValue < 341) {
      angle = 45;  // Left
    } else if (potValue < 682) {
      angle = 90;  // Center
    } else {
      angle = 135; // Right
    }

    deterrentServo.write(angle);

    // Activate all buzzers
    for (int i = 0; i < numBuzzers; i++) {
      digitalWrite(buzzerPins[i], HIGH);
    }

    digitalWrite(ledPin, HIGH);  // Turn LED on
    Serial.println("Bird detected! Activating deterrence.");
    delay(500);  // Brief delay to simulate deterrence time
  } else {
    // No detection: center servo, silence buzzers, turn off LED
    deterrentServo.write(90);

    for (int i = 0; i < numBuzzers; i++) {
      digitalWrite(buzzerPins[i], LOW);
    }

    digitalWrite(ledPin, LOW);  // Turn LED off
  }

  delay(100);  // Small debounce loop delay
}
