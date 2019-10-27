//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define buzzer 3
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
long b;
float bps;
void setup() {
   Serial.begin(9600);
   delay(2500);
   pinMode (buzzer, OUTPUT);
}

void loop() {
   a= sr04.Distance();
   delay(1);
   b = sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   Serial.print(b);
   Serial.println("cm");
   float bps = (a*3.5 + b*3.5)/2;
   while (a <= 75 && a != 0){
   digitalWrite(buzzer, HIGH);
   delay(10);
   Serial.print("in if");
   digitalWrite(buzzer, LOW);
   delay(5);
    a= sr04.Distance();
   digitalWrite(buzzer, HIGH);
   delay(10);
   Serial.print("in if");
   digitalWrite(buzzer, LOW);
   delay(5);
    a= sr04.Distance();
   digitalWrite(buzzer, HIGH);
   delay(10);
   Serial.print("in if");
   digitalWrite(buzzer, LOW);
   delay(5);
    a= sr04.Distance();
   }
   digitalWrite(buzzer, HIGH);
   delay (25);
   
   a= sr04.Distance();
   delay(1);
   b = sr04.Distance();
   bps = (a*4 + b*4)/2;
   digitalWrite(buzzer, LOW);
   delay (bps/4);
   
   a= sr04.Distance();
   delay(1);
   b = sr04.Distance();
   bps = (a*4 + b*4)/2;
   delay (bps/4);

   
}
