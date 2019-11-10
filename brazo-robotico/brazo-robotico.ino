#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Servo.h>
Servo servo;
Stepper motor3(2048,10,12,11,13);
Stepper motor2(2048,6,8,7,9);
Stepper motor1(2048,2,4,3,5);
//SoftwareSerial BT(15,14);
String datos;
String datoPreliminar;
String  motor;
int pasos;
int posicion;
void setup() {
  servo.attach(22);
  servo.write(3);
  motor1.setSpeed(3);
  motor2.setSpeed(3);
  motor3.setSpeed(3);
  Serial3.begin(9600);
  Serial.begin(9600);

}

void loop() {
  if(Serial3.available()>0){
    datos = Serial3.readString();
    posicion = datos.indexOf(',');
    motor = datos.substring(0,posicion);
    Serial.print("motor ");
    Serial.println(motor);
    datoPreliminar = datos.substring(posicion+1,datos.length());
    pasos = datoPreliminar.toInt();
    Serial.print("pasos");
    Serial.println(pasos);
    
    if(motor.equals("A")){
              motorA(pasos);
    }else if(motor.equals("B")){
              motorB(pasos);
    }else if(motor.equals("C")){
              motorC(pasos);
    }else if(motor.equals("D")){
              servo.write(pasos);
    }else{
      Serial.println("Datos no reconocido");
    }
  }
}

void motorA(int pasos){
    Serial.println(pasos);
    motor1.step(pasos);
    for(int i = 2; i <=5 ; i++){
      digitalWrite(i,LOW);  
    }
}
void motorB(int pasos){
    motor2.step(pasos);
    
    for(int i = 6; i <=9 ; i++){
      digitalWrite(i,LOW);  
    }
}
void motorC(int pasos){
    motor3.step(pasos);
    for(int i = 10; i <=13 ; i++){
      digitalWrite(i,LOW);  
    }
}
