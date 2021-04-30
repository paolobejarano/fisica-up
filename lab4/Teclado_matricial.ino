#include <Keypad.h>  // importar la librería

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
byte pinesFilas[filas] = {12,11,10,9}; //pines de las filas
byte pinesColumnas[columnas]= {8,7,6,5}; //pines de las columnas

//Se define el Teclado con los parametros defines anteriormente (pines, filas y columnas)
Keypad Teclado= Keypad(makeKeymap(keymap), pinesFilas, pinesColumnas, filas, columnas);

char Tecla; //almacena la tecla presionada

void setup()
{
  Serial.begin(9600); //inicializa el monitor serial
}


void loop()
{
  Tecla = Teclado.getKey(); //Se almacena el valor de la tecla oprimida
  delay(100); // delay de 100 milisegundos
  if (Tecla){
    Serial.println(Tecla); // Si la tecla es oprimida se imprime
  }
}
