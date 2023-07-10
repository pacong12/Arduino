//aray untuk data pharsing
String arrData[1];
int data;
int ph;
#define RXp2 16
#define TXp2 17
String a;
 String b;

#define BLYNK_PRINT Serial
//konfigurasi blynk
#define BLYNK_TEMPLATE_ID "TMPL6E7U5Nf7L"
#define BLYNK_TEMPLATE_NAME "aan"
#define BLYNK_AUTH_TOKEN "AqQulAxFneQzAjvL9YE1dZK8Rpx_rpOh"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;


#include <Servo.h>
Servo myservo;
//mengatikan delay supaya ketika dijalankan program lain tidak ikut berbent
unsigned long previousMillis = 0;
const long interval = 3000;

int pakan;
void setup() {

  myservo.attach(19);
  myservo.write(0);
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  //koneksi wifi
  WiFi.begin("la", "11111111");
  //uji koneksi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("wifi konek");
  //jika tersambung
  Blynk.begin(BLYNK_AUTH_TOKEN, "la", "11111111");
  Serial.println("blynk konek");
}

void beriPakan() {
  for (int posisi = 0; posisi <= 180; posisi++) {
    myservo.write(posisi);
    delay(10);
  }
  for (int posisi = 180; posisi >= 0; posisi--) {
    myservo.write(posisi);
    delay(10);
  }
}

void loop() {
  //konigurasi ms
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    //update previousMillis
    previousMillis = currentMillis;
    //memprioritaskan data dari arduino uno
    // membaca data serial
    String data = "";
    while (Serial2.available() > 0) {
      data += char(Serial2.read());
    }
    data.trim();

    if (data != "") {
      //pharsing data menjadi array
      int index = 0;
      for (int i = 0; i <= data.length(); i++) {
        char pemisah = '#';
        if (data[i] != pemisah)
          arrData[index] += data[i];
        else
          index++;  //var index bertambah 1
      }

      //memastikan data yang dikirim legkap
      if (index == 1) {
        //tampilkan nilai sensor ke serial;
         b = arrData[1];
         a = arrData[0];
        Serial.println(a.toFloat());
        Serial.println(b.toInt());
      }
      // mengembalikan data ke nilai awal
      arrData[0] = "";
      arrData[1] = "";
      Blynk.virtualWrite(V2, a);
  Blynk.virtualWrite(V0, b);
    }
   
    //minta data ke arduino
    Serial2.println("Ya");
  }
  // data = Serial2.readString().toInt();
  // Serial.println(data);


  //tampil statuspakan serial monitor
  // Serial.println("status pakan : " + String(pakan));
  //jika 1 beri pakan
  if (pakan == 1) {
    //1siklus pakan
    //psisi awal
    beriPakan();
    //kembalikan e posisi 0
    Blynk.virtualWrite(V1, 0);
    pakan = 0;
    delay(2000);
  }
}
BLYNK_WRITE(V1) {
  //baca datastream kemudian tampung kedalam var status pakan
  pakan = param.asInt();
}