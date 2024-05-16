
#define Pin_Buzzer 6
#define RELE 7

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5; 
const int N = 4;
const int SEGMENTOS[N] = {A, B, C, D};

const int Digitos[10][N] = {
    {0, 0, 0, 0}, //0
    {1, 0, 0, 0}, //1
    {0, 1, 0, 0}, //2
    {1, 1, 0, 0}, //3
    {0, 0, 1, 0}, //4
    {1, 0, 1, 0}, //5
    {0, 1, 1, 0}, //6
    {1, 1, 1, 0}, //7
    {0, 0, 0, 1}, //8
    {1, 0, 0, 1}  //9
};

int Detener = false; // Esta variable controla la secuencia del bucle

void setup() {
    pinMode(Pin_Buzzer, OUTPUT);
    pinMode(RELE, OUTPUT);
    digitalWrite(RELE, HIGH);
    for (int i = 0; i < N; i++) {
        pinMode(SEGMENTOS[i], OUTPUT);
        digitalWrite(SEGMENTOS[i], HIGH);
    }
}

void print(int d) {
    for (int i = 0; i < N; i++) {
        digitalWrite(SEGMENTOS[i], Digitos[d][i]);
    }
}

void loop() {
    if (Detener == false) {
        for (int i = 9; i >= 0; i--) {
            print(i);
            delay(1000);
        }
        // Activar el buzzer y la LED al final de la secuencia
        tone(Pin_Buzzer, 250);
        digitalWrite(RELE, LOW);
        delay(500);
        noTone(Pin_Buzzer);
        Detener = true; // Señalamos que ya se ha ejecutado una vez
    }
}

