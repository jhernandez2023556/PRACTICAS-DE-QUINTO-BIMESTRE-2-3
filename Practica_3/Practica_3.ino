/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Maquina expendedora
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 19 de abril
*/
// Definición de la estructura, con nombre y los tipos de datos que puede contener
struct expendedora_de_dulces
{
  char nombres_producto[100]; //Variable tipo char donde almacenare los nombres de los dulces
  long precios_de_producto; //Variable tipo long donde almacenare el número de duces.
};

//Creo los datos de los dulces que voy a registrar. 
expendedora_de_dulces producto1 = {"Culebritas",50};
expendedora_de_dulces producto2 = {"Gomitas Ricolino Panditas Sabores",123};
expendedora_de_dulces producto3 = {"Gomitas Vidal Sabor Fresa ",100};
expendedora_de_dulces producto4 = {"Snikers",40};

// Definimos los botones
int botonAvansar = 2;
int botonRetroceso = 3;

// Variable para llevar la cuenta del producto seleccionado
byte contador = 0;

void setup() {
  // Iniciamos el monitor serial
  Serial.begin(9600);

  // Configuramos los botones como entrada
  pinMode(botonAvansar, INPUT);
  pinMode(botonRetroceso, INPUT);
  
  // Mostramos el primer producto
  Serial.println("MAQUINA EXPENDEDORA DE DULCES");
  Serial.println("Bienvenidos");
  Serial.println("Producto seleccionado:");
  Serial.println("Nombre: " + String(producto1.nombres_producto));
  Serial.println("Cantidad: " + String(producto1.precios_de_producto));
  Serial.println("");
}

void loop() {
  // Si se presiona el botón de avance
  if (digitalRead(botonAvansar) == HIGH) {
    delay(350);
    contador = (contador + 1) % 4; // Avanza al siguiente producto

    // Imprime la información del producto seleccionado
    if(contador == 0){
      Serial.println("Primer Producto");
      Serial.println(producto1.nombres_producto);
      Serial.println(producto1.precios_de_producto);
      Serial.println("");
    }
    else if(contador == 1){
      Serial.println("Segundo Producto");
      Serial.println(producto2.nombres_producto);
      Serial.println(producto2.precios_de_producto);
      Serial.println("");
    }
    else if(contador == 2){
      Serial.println("Tercer Producto");
      Serial.println(producto3.nombres_producto);
      Serial.println(producto3.precios_de_producto);
      Serial.println("");
    }
    else{
      Serial.println("Cuarto Producto");
      Serial.println(producto4.nombres_producto);
      Serial.println(producto4.precios_de_producto);
      Serial.println("Ultimo producto Final");
      Serial.println("");
    }
  }
  // Si se presiona el botón de retroceso
  else if (digitalRead(botonRetroceso) == HIGH) {
    delay(350);
    contador = (contador - 1 + 4) % 4; // Retrocede al producto anterior

    // Imprime la información del producto seleccionado
    if(contador == 0){
      Serial.println("Primer Producto");
      Serial.println(producto1.nombres_producto);
      Serial.println(producto1.precios_de_producto);
      Serial.println("");
    }
    else if(contador == 1){
      Serial.println("Segundo Producto");
      Serial.println(producto2.nombres_producto);
      Serial.println(producto2.precios_de_producto);
      Serial.println("");
    }
    else if(contador == 2){
      Serial.println("Tercer Producto");
      Serial.println(producto3.nombres_producto);
      Serial.println(producto3.precios_de_producto);
      Serial.println("");
    }
    else{
      Serial.println("Cuarto Producto");
      Serial.println(producto4.nombres_producto);
      Serial.println(producto4.precios_de_producto);
      Serial.println("Ultimo producto Final");
      Serial.println("");
      }
    }
  }
