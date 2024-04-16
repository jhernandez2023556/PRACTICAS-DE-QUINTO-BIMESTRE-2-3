/*
Fundacion kinal
Centro Educativo Tecnico Laboral Kinal
Quinto Perito 
Quinto Electronica
Codigo Tecnico: EB5AV /EB5AM
Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
Proyecto: Como leer un pin digital
Dev: Profe. Alejandro Lopez Navas
Fecha: 12 de abril
*/

//Directas Del preprocesador
#define push_button 2 //Push button conectado al pin2
#define led 3

void setup(){
  pinMode(push_button, INPUT); //Pin2 como entrada
  pinMode(led, OUTPUT);
  Serial.begin(9600);                        //Inicio la comunicaion serial
  Serial.println("Lectura de un pulsador");  //Envio el texto entre comillas al puerto serie
}

void loop(){
  //Variable local, que se encarga de almacenar el valor (abierto o cerrado)
  //del pulsador conectado el pin2
  bool estado_boton = digitalRead(push_button);
  if (estado_boton == HIGH) //¿He presionado el interruptor?
  {
    //Si lo he presionado
    digitalWrite(led, LOW); //apago el led
  } else {
    //si no lo he presionado
    digitalWrite(led, HIGH); //mantego encendido el led
  }
}
