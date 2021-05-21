#include <Keypad.h>  // importar la librería

int ledrojo=6;
int ledverde=7;
int IN1=9;
int IN2=8;
int IN3=11;
int IN4=10;
int ECHO=12;
int TRIG=13;

const byte filas= 4; //numero de filas
const byte columnas= 4; //numero de columnas

// define la ubicación de las teclas según su fila y columna
char keymap[filas][columnas]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

// se declaran los pines donde se conectan las filas y columnas
byte pinesFilas[filas] = {5,4,3,2}; //pines de las filas
byte pinesColumnas[columnas]= {A0,A1,A2,A3}; //pines de las columnas

//Se define el Teclado con los parametros defines anteriormente (pines, filas y columnas)
Keypad Teclado= Keypad(makeKeymap(keymap), pinesFilas, pinesColumnas, filas, columnas);

char Tecla; //almacena la tecla presionada

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ledrojo,OUTPUT);
  pinMode(ledverde,OUTPUT);
  
}

void loop()
{
  Tecla = Teclado.getKey(); //Se almacena el valor de la tecla oprimida // delay de 100 milisegundos
  if (Tecla=='8'){
    Serial.println("Girar a la izquierda"); // Si la tecla es oprimida se imprime
    girarizquierda(IN1,IN2,IN3,IN4);
  }
  if (Tecla=='2'){
    Serial.println("Girar a la derecha"); // Si la tecla es oprimida se imprime
    girarderecha(IN1,IN2,IN3,IN4);
  }
  if (Tecla=='4'){
    Serial.println("Avanzar"); // Si la tecla es oprimida se imprime
    avanzar(IN1,IN2,IN3,IN4);
  }
  if (Tecla=='6'){
    Serial.println("Retroceder"); // Si la tecla es oprimida se imprime
    retroceder(IN1,IN2,IN3,IN4);
  }
  if (Tecla=='5'){
    Serial.println("Parar"); // Si la tecla es oprimida se imprime
    parar(IN1,IN2,IN3,IN4);
  }
  
}

int horario (int m, int n){
  digitalWrite(m,HIGH);
  digitalWrite(n,LOW);
}

int antihorario (int m, int n){
  digitalWrite(m,LOW);
  digitalWrite(n,HIGH); 
}

void avanzar (int in1, int in2, int in3, int in4){
  digitalWrite(ledrojo,LOW); // se apaga el ledrojo antes de prenderse el verde
  delay(100);
  horario(in1,in2);
  horario(in3,in4);
  digitalWrite(ledverde,HIGH);
}

void retroceder (int in1, int in2, int in3, int in4){
  digitalWrite(ledverde,LOW); // se apaga el ledverde antes de prenderse el rojo
  delay(100);
  antihorario(in1,in2);
  antihorario(in3,in4);
  digitalWrite(ledrojo,HIGH);
}

void parar (int in1, int in2, int in3, int in4){
  digitalWrite(ledverde,LOW);
  digitalWrite(ledrojo,LOW);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void girarderecha (int in1, int in2, int in3, int in4){
  horario(in1,in2);
  antihorario(in3,in4);
}

void girarizquierda (int in1, int in2, int in3, int in4){
  antihorario(in1,in2);
  horario(in3,in4);
}

int sensor_distancia(int x, int y){
  digitalWrite(y, LOW);
  delayMicroseconds(2);
  digitalWrite(y, HIGH);
  delayMicroseconds(10);  
  digitalWrite(y, LOW);
  float distancia;
  unsigned long tiempo;
  tiempo=pulseIn(x, HIGH);
  distancia= float(0.017*tiempo);
  return distancia;
  Serial.print("Distancia :");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(1000);
}
