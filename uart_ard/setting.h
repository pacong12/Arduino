#define batas 10
//ph sensor
const int ph_pin = A0;
float Po = 0;
int nilai_analog_pH;
float PH_step;
double teganganPH;
//kalibrasi 
 float PH4 = 7;
 float PH7 = 3;
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
