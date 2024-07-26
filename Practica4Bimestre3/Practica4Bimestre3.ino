/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: RFID
   Dev:Jose Filiberto Hernandez De Paz
   Fecha: 26 de Julio
*/
#include <SPI.h>
#include <MFRC522.h>

#define RST_pin 9
#define SDA_pin 10
#define LED_verde 4
#define LED_rojo 5
#define Buz_pin 2

MFRC522 ident (SDA_pin, RST_pin);
MFRC522::MIFARE_Key key;

byte tag1[4] = {0x91, 0x3E, 0x30, 0x1B};
byte tag2[4] = {0xF3, 0xF8, 0xFl, 0x9A};

byte tagAc[4];




void setup() {
  Serial.begin (9600);
  while (!Serial);
  SPI.begin();
  ident.PCD_Init();

  pinMode (LED_verde, OUTPUT);
  pinMode (LED_rojo, OUTPUT);
  pinMode (Buz_pin, OUTPUT);
}

void loop() {
  if (ident.PICC_IsNewCardPresent()){
    if (ident.PICC_ReadCardSerial()){
      //Serial.print(F("Card UID: "));
      dump_byte_array(ident.uid.uidByte, ident.uid.size);

      digitalWrite (LED_verde, LOW);
      digitalWrite (LED_rojo, LOW);
      noTone (Buz_pin);
    }
  }   
}

void dump_byte_array(byte *buffer, byte bufferSize){
  for (byte i = 0; i < bufferSize; i++){
    Serial.print (buffer [i] < 0x10 ? "0" : " ");
    Serial.println (buffer[i], HEX);
    tagAc[i] = buffer[i];
  }
  if (compararArray(tagAc, tag1)){
    Serial.println ("Acceso Permitido");
    digitalWrite (LED_verde, HIGH);
    tone (Buz_pin, 200);
    delay (4000);
  } 
  
  else {
    Serial.println ("Acceso Denegado");
    digitalWrite (LED_rojo, HIGH);
    tone (Buz_pin, 400);
    delay (2000);
  }
}

bool compararArray(byte Array1[], byte Array2[]){
  if (Array1[0] != Array2[0]) return(false);
  if (Array1[1] != Array2[1]) return(false);
  if (Array1[2] != Array2[2]) return(false);
  if (Array1[3] != Array2[3]) return(false);
  return (true);
}
