
#define BLYNK_PRINT Serial
//konfigurasi blynk
#define BLYNK_TEMPLATE_ID "TMPL6E7U5Nf7L"
#define BLYNK_TEMPLATE_NAME "aan"
#define BLYNK_AUTH_TOKEN "ei1SbKPj-J-PK1gRwNYEIWbb_mVGXd_s"

#include <BlynkSimpleEsp32.h>
BlynkTimer timer;

void blynk(){
  dataSerial.begin(9600, SERIAL_8N1, RXp2, TXp2);
  Blynk.begin(BLYNK_AUTH_TOKEN,"la","11111111");
  Serial.println("blynk konek");
}