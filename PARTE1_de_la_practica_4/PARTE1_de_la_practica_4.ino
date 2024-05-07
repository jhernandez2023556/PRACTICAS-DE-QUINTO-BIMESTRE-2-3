/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:Contador del 0 al 9 con tres velocidades 
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 03 de Mayo
*/

// Jose Filiberto Hernandez De Paz
int switch1= 2;
int switch2= 3;
int switch3= 4;

//Definir los pines de 4511
#define Input1= 5;
#define Input2= 6;
#define Input3= 7;
#define Input4= 8;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  if(digitalRead(2)==HIGH)
  if(digitalRead(3)==LOW)
  if(digitalRead(4)==LOW){
    
   //0 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(1000);
   //1 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(1000);
   //2 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(1000);
   //3 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(1000);
   //4 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(1000);
   //5 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(1000);
   //6 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(1000);
   //7 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(1000);
   //8 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(1000);
   // 9 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(1000);
    }
  if(digitalRead(2)==LOW)
  if(digitalRead(3)==HIGH)
  if(digitalRead(4)==LOW){
    //0 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(2000);
   //1 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(2000);
   //2 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(2000);
   //3 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(2000);
   //4 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(2000);
   //5 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(2000);
   //6 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(2000);
   //7 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(2000);
   //8 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(2000);
   // 9 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(2000);
    }
  if(digitalRead(2)==LOW)
  if(digitalRead(3)==LOW)
  if(digitalRead(4)==HIGH){
    //0 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(3000);
   //1 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(3000);
   //2 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(3000);
   //3 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(3000);
   //4 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(3000);
   //5 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(3000);
   //6 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(3000);
   //7 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(3000);
   //8 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(3000);
   // 9 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW);  digitalWrite(8,HIGH);
    delay(3000);
    }
  if(digitalRead(2)==HIGH)
  if(digitalRead(3)==HIGH)
  if(digitalRead(4)==HIGH){
    //0 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //1 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW);  digitalWrite(8,LOW);
    delay(500);
   //2 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //3 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,LOW);  digitalWrite(8,LOW);
    delay(500);
   //4 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //5 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //6 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //7 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //8 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(500);
   // 9 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW);  digitalWrite(8,HIGH);
    delay(500);
    }
  if(digitalRead(2)==LOW)
  if(digitalRead(3)==LOW)
  if(digitalRead(4)==LOW){
   //0 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //1 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //2 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //3 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,LOW); digitalWrite(8,LOW);
    delay(500);
   //4 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //5 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //6 de display
    digitalWrite(5,LOW); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //7 de display
    digitalWrite(5,HIGH); digitalWrite(6,HIGH);
    digitalWrite(7,HIGH); digitalWrite(8,LOW);
    delay(500);
   //8 de display
    digitalWrite(5,LOW); digitalWrite(6,LOW);
    digitalWrite(7,LOW); digitalWrite(8,HIGH);
    delay(500);
   // 9 de display
    digitalWrite(5,HIGH); digitalWrite(6,LOW);
    digitalWrite(7,LOW);  digitalWrite(8,HIGH);
    delay(500);
    }
  }
