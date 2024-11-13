#include <Arduino.h>

void setup() {
  // Serial1.begin(9600);
  pinMode(18, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(18, LOW);
}

void loop() {
  // Serial1.println("Hello, world");
  digitalWrite(18, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);

  digitalWrite(18, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}
