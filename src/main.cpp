#include <Arduino.h>

constexpr uint8_t kGpio = 18;

void setup() {
  // Serial1.begin(9600);
  pinMode(kGpio, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(kGpio, LOW);
}

void loop() {
  // Serial1.println("Hello, world");
  digitalWrite(kGpio, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(5000);

  digitalWrite(kGpio, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}
