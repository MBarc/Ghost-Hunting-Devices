int buzzerPin = 4;

void setup() {
  pinMode(buzzerPin, OUTPUT);

  tone(buzzerPin, 1000, 2000);
}

void loop() {
  tone(buzzerPin, 440); // A4
  delay(200);
  tone(buzzerPin, 587); // D4
  delay(200);
  tone(buzzerPin, 784); // G4
  delay(200);
  noTone(buzzerPin);
  delay(200);
}
