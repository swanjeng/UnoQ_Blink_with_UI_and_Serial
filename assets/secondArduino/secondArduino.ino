void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial1.available()) {
    String input = Serial1.readStringUntil('\n');
    input.trim();
    Serial.print("Uno Q: ");
    Serial.println(input);
    if (input == "1") {
      Serial.println("Uno R4: LED on");
      Serial1.println("Uno R4: LED on");
      digitalWrite(13, HIGH);
    } else if (input == "0") {
      Serial.println("Uno R4: LED off");
      Serial1.println("Uno R4: LED off");
      digitalWrite(13, LOW);
    }
  }
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    Serial.print("Uno R4: ");
    Serial.println(input);
    if (input == "1") {
      Serial1.println("1");
    } else if (input == "0") {
      Serial1.println("0");
    }
  }
}
