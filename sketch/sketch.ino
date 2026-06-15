#include <Arduino_RouterBridge.h>

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200); // Connects to another Arduino

    Bridge.begin();
    Bridge.provide("set_led_state", set_led_state);
}

void loop() {
  if (Serial1.available()) {
    String input = Serial1.readStringUntil('\n');
    input.trim();
    Serial.println(input);
    if (input == "1") Bridge.call("toggle", 1);
    else if (input == "0") Bridge.call("toggle", 0);
  }
}

void set_led_state(bool state) {
    // LOW state means LED is ON
    Serial1.println(state ? "1" : "0");
}
