


#define buzzer 23
//ultrasonic  

#define batas 10
#define  trig  5
#define  echo  18
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
int distance;




#include <Servo.h>

#define BLYNK_PRINT Serial
//konfigurasi blynk
#define BLYNK_TEMPLATE_ID "TMPL6dFdCUEs-"
#define BLYNK_TEMPLATE_NAME "SERVO"
#define BLYNK_AUTH_TOKEN "Chi0qbWtVRvWLp_Nf30hoChKaaB98isU"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;




Servo myservo;
 
//variabel data strim status pakan
int pakan;


void setup() {
    Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  pinMode(buzzer, OUTPUT);

   //ultrasonic
 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  
 timer.setInterval(1000L, sendSensor);
  // put your setup code here, to run once:
  myservo.attach(19);
  //servo awal
  myservo.write(0);

  Serial.begin(9600);

  //koneksi wifi
  WiFi.begin("la", "11111111");
  //uji koneksi
  while(WiFi.status() !=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("wifi konek");
  //jika tersambung
  Blynk.begin(BLYNK_AUTH_TOKEN,"la","11111111");
  Serial.println("blynk konek");
}
void sendSensor()

  {
  digitalWrite(trig, LOW);   
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);      
  digitalWrite(trig, LOW);   
  duration = pulseIn(echo, HIGH);   
  distance = duration * SOUND_SPEED/2; 

  Serial.print("Distance (cm)= ");        
  Serial.println(distance);
  Blynk.virtualWrite(V1, distance);
  delay(1000);  
}
void beriPakan()
{
      for(int posisi=0; posisi <=180; posisi++)
  {
    myservo.write(posisi);
    delay(10);
  }
  for(int posisi=180;posisi>=0;posisi--)
  {
    myservo.write(posisi);
    delay(10);
  }

}
void alarm(){                         //Prosedur alarm
  digitalWrite(buzzer, HIGH);         //Nyalakan buzzer
  delay(125);                         //Selama 500 ms
  digitalWrite(buzzer, LOW);          //Matikan buzzer
  delay(125);                         //Selama 500 ms
}
void loop() {
  timer.run();
  //jalankan ap likasi blynk
  Blynk.run();
  //tampil statuspakan serial monitor
  Serial.println("status oajan : "+ String(pakan));
  //jika 1 beri pakan
  if(pakan ==1)
  {
    //1siklus pakan
    //psisi awal
    beriPakan();
    //kembalikan e posisi 0
    Blynk.virtualWrite(V0, 0);
    pakan = 0;
    delay(2000);
  }
}

// baca datastrim status pakan
BLYNK_WRITE(V0)
{
  //baca datastream kemudian tampung kedalam var status pakan
  pakan = param.asInt();
}
