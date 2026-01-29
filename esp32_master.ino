#include <WiFi.h>
#include <FirebaseESP32.h>

// WiFi Credentials
#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASSWORD "YOUR_PASSWORD"

// Firebase Credentials
#define FIREBASE_HOST "your-project.firebaseio.com"
#define FIREBASE_AUTH "YOUR_FIREBASE_SECRET"

// Relay Pins
#define LIGHT_RELAY 26
#define FAN_RELAY   27

FirebaseData fbdo;

void setup() {
  Serial.begin(9600);

  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {

  if (Firebase.getBool(fbdo, "/home/light")) {
    digitalWrite(LIGHT_RELAY, fbdo.boolData() ? HIGH : LOW);
  }

  if (Firebase.getBool(fbdo, "/home/fan")) {
    digitalWrite(FAN_RELAY, fbdo.boolData() ? HIGH : LOW);
  }

  delay(500);
}
