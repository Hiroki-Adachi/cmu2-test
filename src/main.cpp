#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

constexpr uint8_t kGpioOutput = 18;

constexpr uint16_t kLedBlinkCycleMsec = 1000;
constexpr uint16_t kGpioOutputCycleMsec = 5000;

void TaskBlink(void *pvParameters) {
  (void)pvParameters;
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(kLedBlinkCycleMsec / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(kLedBlinkCycleMsec / portTICK_PERIOD_MS);
  }
}

void TaskGpioOutput(void *pvParameters) {
  (void)pvParameters;
  pinMode(kGpioOutput, OUTPUT);

  for (;;) {
    digitalWrite(kGpioOutput, HIGH);
    vTaskDelay(kGpioOutputCycleMsec / portTICK_PERIOD_MS);
    digitalWrite(kGpioOutput, LOW);
    vTaskDelay(kGpioOutputCycleMsec / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);

  while (!Serial) {
  }

  xTaskCreate(
      TaskBlink,
      "Blink",
      128,
      NULL,
      2,
      NULL);

  xTaskCreate(
      TaskGpioOutput,
      "Gpio Output",
      128,
      NULL,
      1,
      NULL);
}

void loop() {
}