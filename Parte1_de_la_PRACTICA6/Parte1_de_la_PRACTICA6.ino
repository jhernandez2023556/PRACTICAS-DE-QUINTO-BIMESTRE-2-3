/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6
   Dev:Jose Filiberto Hernandez De Paz 
   Fecha: 17 de mayo
   link de la simulacion: 
*/
#include <LiquidCrystal.h>
int seconds = 0;

LiquidCrystal lcd_JFHP1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_JFHP1.begin(16, 2);
  lcd_JFHP1.print("Jose Filiberto");
}

void loop()
{
  lcd_JFHP1.setCursor(0, 1);
  lcd_JFHP1.print("2023556");
  delay(1000); 
  seconds += 1;
}
