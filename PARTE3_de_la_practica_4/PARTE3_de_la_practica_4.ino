/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: 4 interruptores normalmente cerrados
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 03 de Mayo
*/

int switch1 = 2; int switch2 = 3;int switch3 = 4;int switch4 = 5;
int led_1 = 14;int led_2 = 15;int led_3 = 16; int led_4 = 17; 
int led_5 = 18; int led_6 = 19; 
int A = 6;
int B = 7;
int C = 8;
int D = 9;
int E = 10;
int F = 11;
int G = 12;
#define E(pin) digitalWrite(pin, HIGH)
#define A(pin) digitalWrite(pin, LOW)
#define t delay(500)
#define t2 delay(1000)
 
void setup (){
  Serial.begin(9600);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}
void loop(){
  if(digitalRead(switch1) == HIGH)
  if(digitalRead(switch3) == LOW)
  if(digitalRead(switch2) == LOW)
  if(digitalRead(switch4) == LOW){
  Serial.println("Practica No.4- [Jose Filiberto]");
    delay(5000);
     }
  if(digitalRead(switch2) == HIGH)
  if(digitalRead(switch1) == LOW)
  if(digitalRead(switch3) == LOW)
  if(digitalRead(switch4) == LOW){
   E(led_1);t;
 A(led_1);
 E(led_2);t; 
 A(led_2);
 E(led_3);t;
 A(led_3);
 E(led_4);t;
 A(led_4);
 E(led_5);t;
 A(led_5);
 E(led_6);t;
 A(led_6);
 E(led_6);t;
 A(led_6);
 E(led_5);t;
 A(led_5);
 E(led_4);t;
 A(led_4);
 E(led_3);t;
 A(led_3);
 E(led_2);t;
 A(led_2);
 E(led_1);t;
 A(led_1);
 E(led_1);
 E(led_2);
 E(led_3);
 E(led_4);
 E(led_5);
 E(led_6);t;
 A(led_1);
 A(led_2);
 A(led_3);
 A(led_4);
 A(led_5);
 A(led_6);t;
 E(led_1);
 E(led_2);
 E(led_3);
 E(led_4);
 E(led_5);
 E(led_6);t;
 A(led_1);
 A(led_2);
 A(led_3);
 A(led_4);
 A(led_5);
 A(led_6);t;
 }
  if(digitalRead(switch3) == HIGH)
  if(digitalRead(switch1) == LOW)
  if(digitalRead(switch2) == LOW)
  if(digitalRead(switch4) == LOW){
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, LOW);
          t2;
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, LOW);
          t2;
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          t2;
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          t2;
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, LOW);
          digitalWrite(E, HIGH);
          digitalWrite(F, LOW);
          digitalWrite(G, HIGH);
          t2;
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, LOW);
          digitalWrite(G, HIGH);
          t2;
    }
  if(digitalRead(switch1) == HIGH)
  if(digitalRead(switch2) == LOW)
  if(digitalRead(switch3) == HIGH)
  if(digitalRead(switch4) == LOW){
  Serial.println("Gracias por su atencion");
  delay(5000);
   }
 if(digitalRead(switch2) == HIGH)
 if(digitalRead(switch1) == LOW)
 if(digitalRead(switch4) == HIGH)
 if(digitalRead(switch3) == LOW){
 Serial.println("Gracias por su atencion");
 delay(5000);
  }
 }
