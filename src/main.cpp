#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void TaskBlink(void *pvParameters) {
  (void)pvParameters;
  pinMode(LED_BUILTIN, OUTPUT);

  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskDigitalWrite(void *pvParameters) {
  (void)pvParameters;
  pinMode(18, OUTPUT);

  while (1) {
    digitalWrite(18, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(18, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskAnalogRead(void *pvParameters) {
  (void)pvParameters;

  while (1) {
    vTaskDelay(1);
  }
}

void setup() {
  Serial.begin(9600);

  xTaskCreate(
      TaskBlink,
      "Blink",
      128,
      NULL,
      2,
      NULL);

  xTaskCreate(
      TaskDigitalWrite,
      "DigitalWrite",
      128,
      NULL,
      3,
      NULL);

  xTaskCreate(
      TaskAnalogRead,
      "AnalogRead",
      128,
      NULL,
      1,
      NULL);
}

void loop() {
  vTaskDelay(1);
}