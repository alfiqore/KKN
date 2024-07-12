const int PH_PIN = A0;


void setup(){
  Serial.begin(9600);
}

void loop(){
  int analogValue = analogRead(PH_PIN);
  float voltage = analogValue * (5 / 4096);
  
  Serial.print("voltage: ");
  Serial.println(voltage);
  delay(3000);
}
