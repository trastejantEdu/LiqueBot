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

#include <Servo.h>
#include <SoftwareSerial.h> 

//Creamos  un objeto de la libreria SoftwareSerial para la comunicacion Bluetooth
SoftwareSerial BT(2, 3);

//Objetos de la libreria servo para controlar los servos del robot
Servo servoL;
Servo servoR;


void setup(){
  
  //Declaramos los pines en los que se encuentran los servos
  servoR.attach(9);
  servoL.attach(10);

  
  //Posiciones iniciales de los servos
  servoL.write(90);//parado
  servoR.write(90);//parado
  delay(1000);
  
  //Configuramos la conexion via Bluetooth

  BT.begin(9600);//Iniciamos la conexion y configuramos su velocidad
  BT.println("Conectado");//Cuando la conexion este activa, enviamos el mensaje "conectado"  
  
  //Si queremos debuggear con la consola serial via USB podemos activar tambien esa conexion, sino dejar comentado.   
  Serial.begin(9600);  
  Serial.println("Ready");
  Serial.flush();

  

}

void loop(){
// Esperamos ha recibir datos.
  if (Serial.available()){
    
    // Leemos lo que nos llega via serial
    int command = BT.read();
    Serial.flush();
    
    // Comprobamos el comando recibido y mostramos la acción que se debe hacer
    char orden = char(command);
    switch (command) {
      case 'A':
          Serial.println("ALL OK"); //Descomentar para debuggear
          break;
      case '0':
          Serial.println("Parar/OFF"); //Descomentar para debuggear
          para();
      case '4':
          Serial.println("Avanza"); //Descomentar para debuggear
          avanza();
          break;
      case '6':
          Serial.println("Gira a la Derecha"); //Descomentar para debuggear
          derecha();
          break;
      case '3':
          Serial.println("Retrocede"); //Descomentar para debuggear
          retrocede();
          break;
       case '9':
          Serial.println("Gira a la Izquierda"); //Descomentar para debuggear
          izquierda();
          break;
       default:
         Serial.print("Comando incorrecto"); //Descomentar para debuggear
         Serial.println(command); //Descomentar para debuggear
         break;
         

       
    }
    delay(10);
  }

}

void para(){
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
  servoL.write(180);
  delay(10);
  servoR.write(180);
  delay(10);
}

void izquierda(){
  servoL.write(0);
  delay(10);
  servoR.write(0);
  delay(10);
}

void centrar(){
  
}

