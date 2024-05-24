 /*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6
   Dev: Jose Filiberto Hernandez De Paz 
   Fecha: 16 de mayo
   link de la simulacion: 
*/

// Librerías a utilizar
#include <Wire.h>               // Librerías para usar el protocolo I2C
#include <LiquidCrystal_I2C.h>  // Librería que controla la LCD por medio de I2C
#include <Servo.h>              // Librería que me permite usar el servomotor
#include <Keypad.h>             // Librería que me permite usar el teclado matricial

// Directivas de preprocesador para la LCD
#define direccion_lcd 0x27      // Dirección de la pantalla LCD (verificar la dirección I2C)
#define filas 2                 // Cantidad de filas que posee la pantalla LCD
#define columnas 16             // Cantidad de columnas que posee la pantalla LCD 

// Directivas de preprocesador para el teclado matricial
#define filas_teclado 4         // Cantidad de filas que posee el teclado matricial
#define columnas_teclado 4      // Cantidad de columnas que posee el teclado matricial
#define f1_teclado 9            // Pin 9 conectado a la fila 1
#define f2_teclado 8            // Pin 8 conectado a la fila 2
#define f3_teclado 7            // Pin 7 conectado a la fila 3
#define f4_teclado 6            // Pin 6 conectado a la fila 4
#define c1_teclado 5           // Pin 5 conectado a la columna 1
#define c2_teclado 4           // Pin 4 conectado a la columna 2
#define c3_teclado 3           // Pin 3 conectado a la columna 3
#define c4_teclado 2           // Pin 2 conectado a la columna 4

// Directivas de preprocesador para el servomotor, LEDs y buzzer
#define pin_servo A1            // Pin A1 conectado al servOomotor
#define pin_buzz A2             // Pin A2 conectado al buzzer
#define led_rojo 10              // Pin 10 conectado al LED rojo
#define led_amar 12             // Pin 12 conectado al LED amarillo
#define led_verd 11            // Pin 11 conectado al LED verde
#define ON(pin) digitalWrite(pin, HIGH)
#define OFF(pin) digitalWrite(pin, LOW)

// Variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};

// Variables para el uso del servomotor
const int lock_pos = 0;        // Posición de 0 grados para indicar que la puerta se encuentra cerrada
const int unlock_pos = 90;     // Posición de 90 grados para indicar que la puerta se encuentra abierta

// Variables donde almacenaré las contraseñas
String contrasenaCerradura = "20235565*";  // Contraseña definida por el sistema
String info_recibida = "";                 // Variable para guardar los caracteres ingresados

// Variables auxiliares
byte pos_lcd = 0;             // Posición del cursor

// Constructor
LiquidCrystal_I2C lcdCerradura(direccion_lcd, columnas, filas); // LCD con dirección 0x27 y tamaño 16x2
Servo ServoCerradura; // Servomotor controlado por PWM en el pin 9
Keypad tecladoCerradura = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado); // Teclado matricial 4x4

// Funciones
void config_outputs();
void config_HMI();
void check_password();

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial
  Serial.println("Practica 6"); // Envía mensaje al monitor serie
  config_outputs(); // Configura los pines de salida
  config_HMI(); // Configura e inicializa la pantalla LCD y el servomotor
  ON(led_amar); // Enciende el LED amarillo
  ON(led_rojo); // Enciende el LED rojo
  OFF(led_verd); // Apaga el LED verde
  ServoCerradura.write(lock_pos); // Cierra la cerradura
}

void loop() {
  // Obtiene el valor de la tecla presionada
  char key = tecladoCerradura.getKey();

  if (key) {
    info_recibida += key;
    Serial.println(key);
    lcdCerradura.setCursor(pos_lcd, 1);
    lcdCerradura.print("*");
    pos_lcd++;

    if (key == '*') {
      check_password();
    }
  }

  // Lectura desde el monitor serie
  if (Serial.available() > 0) {
    char serialKey = Serial.read();
    info_recibida += serialKey;
    Serial.println(serialKey);
    lcdCerradura.setCursor(pos_lcd, 1);
    lcdCerradura.print("*");
    pos_lcd++;

    if (serialKey == '*') {
      check_password();
    }
  }
}

void check_password() {
  lcdCerradura.setCursor(0, 1);
  lcdCerradura.print("                ");
  Serial.println(info_recibida);

  if (info_recibida == contrasenaCerradura) {
    lcdCerradura.setCursor(0, 1);
    lcdCerradura.print("Contraseña correcta");
    ServoCerradura.write(unlock_pos);
    delay(1000);
    ServoCerradura.write(lock_pos);
    lcdCerradura.setCursor(0, 1);
    lcdCerradura.print("Puerta-Abierta");
    ON(led_verd);
    OFF(led_rojo);
    Serial.println("Contraseña correcta");
    for (int i = 0; i < 2; i++) {
      tone(pin_buzz, 1000); // Emitir tono
      delay(500);
      noTone(pin_buzz); // Detener tono
      delay(1000);
    }
  } else {
    lcdCerradura.setCursor(0, 1);
    lcdCerradura.print("Contraseña incorrecta");
    delay(1000);
    lcdCerradura.setCursor(0, 1);
    lcdCerradura.print("Puerta-Cerrada");
    OFF(led_verd);
    ON(led_rojo);
    Serial.println("Contraseña incorrecta");
    ServoCerradura.write(lock_pos);
    for (int i = 0; i < 5; i++) {
    tone(pin_buzz, 1000);
    delay(500);
    noTone(pin_buzz);
    delay(1000);
    }
  }

  info_recibida = ""; // Limpia el string
  delay(1000);
  lcdCerradura.setCursor(0, 1);
  lcdCerradura.print("Puerta Cerrada");
  pos_lcd = 0;
  ON(led_rojo);
  OFF(led_verd);
  ServoCerradura.write(lock_pos);
}

void config_outputs() {
  pinMode(pin_servo, OUTPUT);
  pinMode(pin_buzz, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verd, OUTPUT);
}

void config_HMI() {
  ServoCerradura.attach(pin_servo);
  lcdCerradura.init();
  lcdCerradura.backlight();
  lcdCerradura.setCursor(2, 0);
  lcdCerradura.print("Bienvenidos");
  lcdCerradura.setCursor(0, 1);
  lcdCerradura.print("Puerta-Cerrada");
}
