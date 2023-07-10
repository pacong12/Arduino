//servo
// #include <ESP32Servo.h> 
// Servo servo; 
// int pos = 0;  


//ultrasonic
const int trigPin = 5;
const int echoPin = 18;
#define batas 10
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;

//ph sensor
const int ph_pin = 4;
float Po = 0;
int nilai_analog_pH;
float PH_step;
double teganganPH;

//kalibrasi 
 float PH4 = 3.1;
  float PH7 = 2.6;
void setup() {
  //ultrasonic
   Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // put your setup code here, to run once:
  pinMode (ph_pin, INPUT);
  Serial.begin(9600);
//servo
  // servo.attach(23);
  // servo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai_analog_pH = analogRead(ph_pin);
  // Serial.print("Nilai ADC pH :  ");
  // Serial.println(nilai_analog_pH);
  teganganPH = 3.3/ 4096.0 * nilai_analog_pH;
  // Serial.print("Tegangan PH :  ");
  // Serial.println(teganganPH, 3);

  PH_step = (PH4 - PH7)/ 3;
  Po = 7.00 + ((PH7 - teganganPH) / PH_step);
  Serial.print("Nilai PH cairan :  ");
  Serial.println(Po, 2);
  //ultrasonic
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  // distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm );


 if (distanceCm > batas){
    Serial.println("makan kurang"); 
    // servo.write(90); 
 }
  else{
    Serial.println("makan full");  
    // servo.write(0); 
  }
  // Serial.print("Distance (inch): ");
  // Serial.println(distanceInch);
  delay(3000);
} 
