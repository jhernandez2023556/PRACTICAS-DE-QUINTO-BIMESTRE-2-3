/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Contador del 0 al 99 en incremento y decremento
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 03 de Mayo
*/

const int pinIncrement = 2; // Pin para el interruptor de incremento
const int pinDecrement = 3; // Pin para el interruptor de decremento
int contador = 0; // Variable para almacenar el valor del contador

void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial a 9600 baudios
  pinMode(pinIncrement, INPUT_PULLUP); // Configurar el pin del interruptor de incremento como entrada con pull-up
  pinMode(pinDecrement, INPUT_PULLUP); // Configurar el pin del interruptor de decremento como entrada con pull-up
}

void loop() {
  // Verificar el interruptor de incremento
  if (digitalRead(pinIncrement) == LOW) {
    delay(50); 
    if (digitalRead(pinIncrement) == LOW) {
      if (contador < 99) {
        contador++;
        Serial.print("Contador incrementado: ");
        Serial.println(contador);
      } else{
        Serial.println("El contador llego al valor maximo");
      }
      while (digitalRead(pinIncrement) == LOW) {} // Esperar a que el botón de incremento se suelte
    }
  }

  // Verificar el interruptor de decremento
  if (digitalRead(pinDecrement) == LOW) {
    delay(50); 
    if (digitalRead(pinDecrement) == LOW) {
      if (contador > 0) {
        contador--;
        Serial.print("Contador decrementado: ");
        Serial.println(contador);
      } else {
        Serial.println("El contador ya está en su valor mínimo.");
      }
      while (digitalRead(pinDecrement) == LOW) {} // Esperar a que el botón de decremento se suelte
    }
  }
}
