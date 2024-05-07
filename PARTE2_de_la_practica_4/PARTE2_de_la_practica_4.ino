/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: El auto 
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 04 de Mayo
*/

int SW1 = 0;
int SW2 = 0;
# define Switch2 = 2;
# define Switch3 = 3;
# define miled4 = 4;
# define miled5 = 5;
# define miled6 = 6;
# define miled7 = 7;
# define miled8 = 8;
# define miled9 = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop()
{
 SW1 = digitalRead(2);
 SW2 = digitalRead(3);
 
  if(SW1 == HIGH){
   Serial.println("Secuencia velociadad 1");
   digitalWrite(4,HIGH);
   delay(500);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
   delay(500);
   digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
   delay(500);
   digitalWrite(6,LOW);
   digitalWrite(7,HIGH);
   delay(500);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   delay(500);
   digitalWrite(8,LOW);
   digitalWrite(9,HIGH);
   delay(500);
   digitalWrite(9,LOW);
   //De regreso
   digitalWrite(9,HIGH);
   delay(500);
   digitalWrite(9,LOW);
   digitalWrite(8,HIGH);
   delay(500);
   digitalWrite(8,LOW);
   digitalWrite(7,HIGH);
   delay(500);
   digitalWrite(7,LOW);
   digitalWrite(6,HIGH);
   delay(500);
   digitalWrite(6,LOW);
   digitalWrite(5,HIGH);
   delay(500);
   digitalWrite(5,LOW);
   digitalWrite(4,HIGH);
   delay(500);
   digitalWrite(4,LOW);
   delay(500);
   //Primer parpadeo
   digitalWrite(4,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(9,HIGH);
   delay(500);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
   delay(500);
    //Segundo parpadeo
   digitalWrite(4,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(9,HIGH);
   delay(500);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
   delay(500);
 }
   
  if(SW2 == HIGH){
   Serial.println("Secuencia velociadad 2");
   digitalWrite(4,HIGH);
   delay(1000);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
   delay(1000);
   digitalWrite(5,LOW);
   digitalWrite(6,HIGH);
   delay(1000);
   digitalWrite(6,LOW);
   digitalWrite(7,HIGH);
   delay(1000);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   delay(1000);
   digitalWrite(8,LOW);
   digitalWrite(9,HIGH);
   delay(1000);
   digitalWrite(9,LOW);
   //De regreso
   digitalWrite(9,HIGH);
   delay(1000);
   digitalWrite(9,LOW);
   digitalWrite(8,HIGH);
   delay(1000);
   digitalWrite(8,LOW);
   digitalWrite(7,HIGH);
   delay(1000);
   digitalWrite(7,LOW);
   digitalWrite(6,HIGH);
   delay(1000);
   digitalWrite(6,LOW);
   digitalWrite(5,HIGH);
   delay(1000);
   digitalWrite(5,LOW);
   digitalWrite(4,HIGH);
   delay(1000);
   digitalWrite(4,LOW);
    delay(100);
   //Primer parpadeo
   digitalWrite(4,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(9,HIGH);
   delay(1000);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
   delay(1000);
    //Segundo parpadeo
   digitalWrite(4,HIGH);
   digitalWrite(5,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(7,HIGH);
   digitalWrite(8,HIGH);
   digitalWrite(9,HIGH);
   delay(1000);
   digitalWrite(4,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
   delay(1000);
     }
    }
