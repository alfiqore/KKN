const int ph_pin = A0;
float Po = 0;
float PH_step;
float TeganganpH;

float PH42 = 12.90;
float PH68  = 10.33;


void setup(){
  pinMode (ph_pin, INPUT);
  Serial.begin(115200);
}

void loop(){  
  int nilai_analog_pH = analogRead(ph_pin);
  Serial.print("Nilai ADC pH: ");
  Serial.println(nilai_analog_pH);
  TeganganpH = nilai_analog_pH * (3.3 / 1023.0);
  Serial.print("Tegangan pH: ");
  Serial.println(TeganganpH);

  PH_step = (PH42 - PH68) / 2.6;
  Po = 6.80 + ((PH68 - TeganganpH) / PH_step);

  Serial.print("Nilai pH: ");
  Serial.println(Po, 2);
  delay(1000);
}
