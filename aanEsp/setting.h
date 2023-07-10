#include <Servo.h>


Servo myservo;
//mengatikan delay supaya ketika dijalankan program lain tidak ikut berbent
unsigned long previousMillis =0;
const long interval = 3000;
//aray untuk data pharsing
String arrData[2];



