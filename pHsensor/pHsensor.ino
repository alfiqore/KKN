const int pHSensorPin = A0;
float voltage, pHValue;

void setup() {
  Serial.begin(115200); // Komunikasi serial dengan ESP32-CAM
}

void loop() {
  int sensorValue = analogRead(pHSensorPin);
  voltage = sensorValue * (5.0 / 1023.0);
  pHValue = 3.5 * voltage; // Gantilah dengan kalibrasi pH yang benar

  // Kirim data pH ke ESP32-CAM
  Serial.print("pH:");
  Serial.println(voltage);

  delay(1000); // Tunggu 1 detik sebelum membaca lagi
}
