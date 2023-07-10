phSensor(){
     int nilai_analog_pH = analogRead(ph_pin);
  // Serial.print("Nilai ADC pH :  ");
  // Serial.println(nilai_analog_pH);
  teganganPH = 5/ 1024.0 * nilai_analog_pH;
  // Serial.print("Tegangan PH :  ");
  // Serial.println(teganganPH, 3);
  PH_step = (PH4 - PH7)/ 3;
  Po = 7.00 + ((PH7 - teganganPH) / PH_step);
  a = Po,2;
}