#define MOISTURE_PIN 34
#define PUMP_RELAY   25

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_RELAY, OUTPUT);
}

void loop() {
  int moisture = analogRead(MOISTURE_PIN);

  if (moisture < 2000) {
    digitalWrite(PUMP_RELAY, HIGH); // Pump ON
  } else {
    digitalWrite(PUMP_RELAY, LOW);  // Pump OFF
  }

  Serial.println(moisture);
  delay(1000);
}
