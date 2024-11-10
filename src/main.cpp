#include <Arduino.h>

void setup() {
  // Serial1.begin(9600);
  pinMode(19, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(19, LOW);
}

void loop() {
  // Serial1.println("Hello, world");
  digitalWrite(19, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);

  digitalWrite(19, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
