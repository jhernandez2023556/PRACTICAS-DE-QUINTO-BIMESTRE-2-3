//Librerias
#include <Wire.h>                   //libreria para usar el protocolo i2c
#include <SparkFun_ADXL345.h>       //libreria para usar el acelerometro ADXL345
#include <SoftwareSerial.h>        //libreria para emular otro puerto serie
#include <DFRobotDFPlayerMini.h>    //libreria para usar el reproductor MP3
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7 


//Constructores
ADXL345 acc_sismo = ADXL345();          //constructor para usar el acelerometro
SoftwareSerial mp3_sismo(10,11);         //RX 6 y TX 7
DFRobotDFPlayerMini reproductor_MP3;    //constructor para el reproductor MP3
//Variables
/*
Declaro las 3 variables, donde guardo los valores de aceleracion de caada eje
*/
unsigned int acc_X;         //aceleracion en el eje x
unsigned int acc_Y;         //aceleracion en el eje y
unsigned int acc_Z;         //aceleracion en el eje z

//Variable donde guardo la magnitud del vector aceleracion
float magnitud_acc;

//Configuraciones
void setup() {
  Serial.begin(9600);             //Inicio la comunicacion serial del arduino hacia la computadora
  mp3_sismo.begin(9600);           //Inicio la comunicacion serial emulada para el mp3
  acc_sismo.powerOn();            //Enciendo el acelerometro
  acc_sismo.setRangeSetting(8);    //Configuro la sensibbilidad del acelerometro
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);



  //Compruebo si hay conexion con el modulo mp3
  if(!reproductor_MP3.begin(mp3_sismo))
  { 
    //Si no existe, me quedo aqui siempre. Ya no avanzo en el codigo
    Serial.println("No he podido comunicarme con el modulo MP3");

    while (1);
  }
  //Si la comunicacion ha sido exitosa, avanzo
  reproductor_MP3.volume(20);       //volumen al maximo
  Serial.println("Comunicacion exitosa con el reproductor MP3");
  Serial.println("Practica 2 - fily");
  Serial.println("reproduzco la primera cancion");
  
  delay(100);
}

void loop() {
  
  //Leo las variables medidas por el acelerometro
  acc_sismo.readAccel(&acc_X,&acc_Y,&acc_Z);
  /*
  //Imprimo las variables leidas, estas se mostraran en el monitor serial
  Serial.print("Aceleracion en X: ");
  Serial.println(acc_X);
  Serial.print("Aceleracion en Y: ");
  Serial.println(acc_Y);
  Serial.print("Aceleracion en Z: ");
  Serial.println(acc_Z);
  */
  //obtengo la magnitud del vector aceleracion
  magnitud_acc = sqrtf((acc_X*acc_X)+(acc_Y*acc_Y)+(acc_Z*acc_Z));
  
  //Serial.print("La magnitud del vector aceleracion es de: ");
  //Serial.println(magnitud_acc);
  int mapeo_intensidad = map(magnitud_acc,47, 75, 0, 10);

  /*
  Serial.print("El valor mapeo es de: ");
  Serial.println(mapeo_intensidad);*/

  if(mapeo_intensidad>=0 && mapeo_intensidad <2){
    Serial.println("Primeros dos niveles de la escala mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    }
  else if (mapeo_intensidad>=2 && mapeo_intensidad<4){
    Serial.println("Dos niveles mas de la escala de mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW); 
    }

  else if (mapeo_intensidad>=4 && mapeo_intensidad<6){
    Serial.println("Dos niveles mas de la escala de mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW); 
    }

  else if (mapeo_intensidad>=6 && mapeo_intensidad<8){
    Serial.println("Dos niveles mas de la escala de mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW); 
    }

  else if (mapeo_intensidad>=8 && mapeo_intensidad<10){
    Serial.println("Dos niveles mas de la escala de mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,LOW); 
    }
  
  else if (mapeo_intensidad>=10 && mapeo_intensidad<12){
    Serial.println("Dos niveles mas de la escala de mercalli");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
    digitalWrite(led6,HIGH); 
    reproductor_MP3.play(8);
    }
  else {
  Serial.println("Ay mi casa");
  }
  delay(1000);
}