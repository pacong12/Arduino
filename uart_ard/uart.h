void kirimdata(){
  phSensor();
  // Serial.println(a);
  ultraSensor();
  // Serial.println(wadah);
    if (wadah < 30)  //Pada distance kurang dari 30 cm mengaktifkan LED level high
  {
      digitalWrite(buzzer,LOW);  
  } 
  
  if (wadah > 30) //Pada distance kurang dari 30 cm mengaktifkan buzzer dan relay
  { 
    digitalWrite(buzzer,HIGH);
   }
  gabungData();

}
void uart(){
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
}
void gabungData(){
    //mengumpulkan data menjadi 1 varibel
  String data = String(a)+ "@"+ String(wadah);
  // baca seluruh data
  Serial.println(data);
}