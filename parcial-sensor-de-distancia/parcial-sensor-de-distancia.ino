#include <Ultrasonic.h>
#include <SoftwareSerial.h>
#include <NewPing.h>
#define pin_trigger 3
#define pin_echo 4
#define max_distancia 100

SoftwareSerial BT(10,9);
Ultrasonic distancia(3,4);
int pulsador = 11;
float valor;
int posicion;
String aux;
int max_;
int min_;
String datos;
NewPing lectura(pin_trigger,pin_echo,max_distancia);
void setup() {
  pinMode(pulsador,OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);

}

void loop() {
    if(BT.available()>0){
    datos = BT.readString();
    posicion = datos.indexOf(',');
    aux = datos.substring(0,posicion);
    max_ = aux.toInt();
    aux = datos.substring(posicion+1,datos.length());
    min_ = aux.toInt();
    Serial.println(datos);
    Serial.print("max :");
    Serial.println(max_);
    Serial.print("min :");
    Serial.println(min_);
  }
  if(digitalRead(pulsador) == 1 && max_ <= 100 ){
    
    valor = lectura.ping_median();
    valor = valor/US_ROUNDTRIP_CM;  
    if(valor >= min_ && valor<=max_){
      Serial.print("La distancia es de: ");
      Serial.print(valor);
      Serial.println(" cm.");
    }else{
    Serial.println("distancia fuera de rango");
  }
    
  }
  
  
}
