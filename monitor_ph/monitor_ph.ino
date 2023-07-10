int pH_value;
float volt;
void setup() {
  
  Serial.begin(9600);

}

void loop() {

  pH_value = analogRead(A0);
  volt = pH_value * (5/1023.0);
  Serial.println(volt);
  delay(500);

}
