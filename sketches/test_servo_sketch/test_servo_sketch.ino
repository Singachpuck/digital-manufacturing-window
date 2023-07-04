
void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  int mode = (millis() / 1000) % 4;
  if (mode == 0) {
    digitalWrite(D0, HIGH);
    digitalWrite(D1, LOW);
  } else if (mode == 2) {
    digitalWrite(D0, LOW);
    digitalWrite(D1, HIGH);
  } else {
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
  }
}
