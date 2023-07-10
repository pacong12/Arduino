void seting(){

   //ultrasonic
    pinMode (ph_pin, INPUT);
   pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
    myservo.attach(10);
  
}