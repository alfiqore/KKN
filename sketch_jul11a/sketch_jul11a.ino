#include <WiFi.h>
#include <WiFiClient.h>


const char* ssid = "Alfi";
const char* password = "";

WiFiServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "ESP32-CAM Connected!");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
