#define batas 10
//ph sensor
const int ph_pin = A0;
float Po = 0;
int nilai_analog_pH;
float PH_step;
double teganganPH;
//kalibrasi 
 float PH4 = 3.1;
 float PH7 = 2.6;
 float a;

#include <Servo.h>
#define  trig  6
#define  echo  7
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define buzzer 8 

Servo myservo; // create servo object to control a servo
int wadah;
long duration;
int distance;

void setup() {
  Serial.begin (9600);       // initialize serial port
  //ultrasonic
    pinMode (ph_pin, INPUT);
   pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
    myservo.attach(10);
  
}
void kirimdata(){
     int nilai_analog_pH = analogRead(ph_pin);
  // Serial.print("Nilai ADC pH :  ");
  // Serial.println(nilai_analog_pH);
  teganganPH = 5/ 1024.0 * nilai_analog_pH;
  // Serial.print("Tegangan PH :  ");
  // Serial.println(teganganPH, 3);
  PH_step = (PH4 - PH7)/ 3;
  Po = 7.00 + ((PH7 - teganganPH) / PH_step);
  a = Po;
  // Serial.println(a);
  digitalWrite(trig, LOW);   
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);      
  digitalWrite(trig, LOW);   
  duration = pulseIn(echo, HIGH);   
  distance = duration * SOUND_SPEED/2;   
  wadah = distance;
  // Serial.println(wadah);
    if (wadah < 30)  //Pada distance kurang dari 30 cm mengaktifkan LED level high
  {
      digitalWrite(buzzer,LOW);  
  } 
  
  if (wadah > 30) //Pada distance kurang dari 30 cm mengaktifkan buzzer dan relay
  { 
    digitalWrite(buzzer,HIGH);
   }
  //mengumpulkan data menjadi 1 varibel
  String data = String(a)+"#"+String(wadah);
  // baca seluruh data
  Serial.println(data);

}
void loop() {
  //membaca permintaan data
  String minta = "";
  //
  while (Serial.available()> 0)
  {
    minta += char(Serial.read());
  }

  //membuang spasi jika ada data yang masuk
  minta.trim();
  if (minta=="Ya"){
      //
      kirimdata();
  }
  //mengembalikan data ke nilai awal
  minta = "";
  delay (1000);
}