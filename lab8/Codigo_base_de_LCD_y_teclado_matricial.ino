//incluimos librerias
#include <LiquidCrystal.h>
#include <Keypad.h>  

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
byte pinesFilas[filas] = {A0,A1,A2,A3}; //pines de las filas
byte pinesColumnas[columnas]= {7,6,5,4}; //pines de las columnas

//Se define el Teclado con los parametros defines anteriormente (pines, filas y columnas)
Keypad Teclado= Keypad(makeKeymap(keymap), pinesFilas, pinesColumnas, filas, columnas);

char key; //almacena la tecla presionada


// declarar pantalla LCD y asignar
LiquidCrystal lcd(13,12,11,10,9,8);
void setup() {
  // iniciar pantalla indicando # de columnas y filas
  lcd.begin(16, 2);
  //Escribimos en la posicion 0,0
  lcd.setCursor(0,0);
  lcd.print("!Bienvenido!");
  delay(1000);
  lcd.clear();
}
void loop() {
  key = Teclado.getKey(); //Se almacena el valor de la tecla oprimida
  delay(100); // delay de 100 milisegundos
  lcd.setCursor(0, 0); 
  if (key){ 
    lcd.print(key); // Si la tecla es oprimida se imprime
    delay(1000);
    lcd.clear();
  }
}
