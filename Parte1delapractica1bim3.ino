/* 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso del keypad 4x4
   Dev: José Filiberto Hernández De Paz
   Fecha: 07 de mayo
   link de la simulacion: 
*/
#include <Adafruit_NeoPixel.h>
 
#define TRIG_PIN 3
#define ECHO_PIN 2
#define NEOPIXEL_PIN 4
#define NUMPIXELS 12
 
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
 
int count = 0;
const int maxPeople = 9;
 
// Definición de los pines de los segmentos del visualizador de 7 segmentos
const int segmentPins[] = {5, 6, 7, 8, 9, 10, 11};
 
// Mapas de los segmentos para los dígitos 0-9
const int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}  // 9
};
 
void setup() {
  Serial.begin(9600);
 
  // Configuración de pines para el sensor ultrasónico
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
 
  // Configuración de pines para el visualizador de 7 segmentos
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
 
  // Inicializar el NeoPixel
  pixels.begin();
  pixels.show(); // Inicializar todos los pixeles apagados
 
  // Mostrar el conteo inicial
  displayDigit(count);
}
 
void loop() {
  float distance = measureDistance();
 
  if (distance >= 6.0 && distance <= 10.0) {
    if (count < maxPeople) {
      count++;
      displayDigit(count);
       for(int i =0; i<13; i++)
      pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // Verde
    } else {
      displayFull();
      for(int i =0; i<13; i++)
      pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Rojo
    }
    pixels.show();
    delay(500); // Esperar 2 segundos para evitar múltiples lecturas
  }
 
  delay(100); // Pequeño retraso para evitar lecturas rápidas
}
 
float measureDistance() {
  // Enviar pulso de activación
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 
  // Leer el pulso de eco
  long duration = pulseIn(ECHO_PIN, HIGH);
 
  // Calcular la distancia en centímetros
  float distance = (duration * 0.034) / 2;
 
  return distance;
}
 
void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[digit][i]);
  }
}
 
void displayFull() {
  for (int i = 0; i < 7; i++) {
    if (i == 6) { // Encender solo el segmento G
      digitalWrite(segmentPins[i], HIGH);
    } else {
      digitalWrite(segmentPins[i], LOW);
    }
  }
}