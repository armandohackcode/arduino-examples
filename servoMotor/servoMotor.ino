
#include <Servo.h>
 
Servo myservo;  // crea el objeto servo
 
int pos = 0;    // posicion del servo
 
void setup() {
   myservo.attach(9);  // vincula el servo al pin digital 9
   Serial.begin(9600);
}
 
void loop() {
  while(Serial.available()>0){
    int angulo = Serial.parseInt();
    Serial.println(angulo);
    myservo.write(angulo);  
  }
  //myservo.write(70);  
  
  
  
}
