  //koneksi wifi

#include <WiFi.h>
#include <WiFiClient.h>


void wifi(){
  WiFi.begin("la", "11111111");
  //uji koneksi
   while(WiFi.status() !=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("wifi konek");
  }