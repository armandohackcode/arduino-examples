#include <SoftwareSerial.h>

String datos;
String datoPreliminar;
String  motor;
int pasos;
int posicion;
SoftwareSerial BT(10,9);
void setup() {
  BT.begin(9600);
  Serial.begin(9600);

}

void loop() {
  if(BT.available()){
    datos = BT.readString();
    posicion = datos.indexOf(',');
    motor = datos.substring(0,posicion);
    Serial.print("motor ");
    Serial.println(motor);
    datoPreliminar = datos.substring(posicion+1,datos.length());
    pasos = datoPreliminar.toInt();
    Serial.print("pasos");
    Serial.println(pasos);
    
    if(motor.equals("A")){
              Serial.println("Enseciendo motor A");
    }else if(motor.equals("B")){
              Serial.println("Enseciendo motor B");
    }else if(motor.equals("C")){
              Serial.println("Enseciendo motor C");
    }else if(motor.equals("D")){
              Serial.println("Enseciendo Servo D");
              Serial.println(datos);
              Serial.println(pasos);
    }else{
      Serial.println("Datos no reconocido");
    }
  }
}
