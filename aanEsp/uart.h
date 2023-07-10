

void dataUart(){
    unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    //update previousMillis
    previousMillis = currentMillis;
    //memprioritaskan data dari arduino uno
    // membaca data serial
    String data = "";
    while(dataSerial.available()>0){
      data += char(dataSerial.read());
    }
    data.trim();

    if (data != "")
    {
      //pharsing data menjadi array
      int  index = 0;
      for(int i =0;i<=data.length();i++){
        char pemisah = '@';
        if(data[i] !=pemisah)
        arrData[index] += data[i];
        else
        index++;//var index bertambah 1
      }

      //memastikan data yang dikirim legkap
      if (index ==1){
        //tampilkan nilai sensor ke serial;
        Serial.println(arrData[0]);
        Serial.println(arrData[1]);
      }
      // mengembalikan data ke nilai awal
      arrData[0] = "";
      arrData[1] = "";

    }
    //minta data ke arduino
    dataSerial.println("Ya");
  }
}