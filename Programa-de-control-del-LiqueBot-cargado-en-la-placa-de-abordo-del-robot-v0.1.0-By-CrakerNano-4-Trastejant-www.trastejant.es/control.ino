/*
################################################################################################################################################################################
                                                              Programa de control del LiqueBot
                                                          cargado en la placa de abordo del robot
################################################################################################################################################################################                                   
#####################################################################     v0.1.0      ##########################################################################################
################################################################################################################################################################################
#################################################################  By CrakerNano 4 Trastejant  #################################################################################
################################################################################################################################################################################
                                                                    www.trastejant.es
*/

#include <Servo.h> //Llamada a la libreria Servo
#include "DHT.h"   //Llamada a la libreria DHT(Sensor de humedad)  

//Configuracion del sensor de humedad
#define DHTPIN 6   //Declaramos que el sensor esta en el pin 6      
#define DHTTYPE DHT11 //Definimos el modelo del sensor        
DHT dht(DHTPIN, DHTTYPE); //Definimos la variable que utilizaremos para comunicarnos con el sensor    

//Declaracion de objetos tipo servo
Servo servoL;
Servo servoR;
Servo direccion;

void setup(){

  dht.begin(); //Inicializamos el sensor de Humedad
  
  //Declaracion de pines de los servos
  servoR.attach(9);
  servoL.attach(10);
  direccion.attach(11);
  
  //Posiciones iniciales de los servos
  direccion.write(90);
  servoL.write(90);
  servoR.write(90);
  delay(1000);
  

}

void loop(){

}

void Stop(){
  servoL.write(90);
  delay(10);
  servoR.write(90);
  delay(10);
}

void avanza(){
  servoL.write(0);
  delay(10);
  servoR.write(180);
  delay(10);
}

void retrocede(){
  servoL.write(180);
  delay(10);
  servoR.write(0);
  delay(10);
}

void derecha(){
  direccion.write(0);
  delay(10);
}

void izquierda(){
  direccion.write(180);
  delay(10);
}

void centrar(){
  direccion.write(90);
  delay(10);
}

float leerTemperatura(){
return dht.readTemperature();     
}

float leerHumedad(){
return dht.readHumidity();   
}

float leerMonoxido(int sensor){
return analogRead(sensor);
}

float leerDioxido(int sensor){
return analogRead(sensor);
}
