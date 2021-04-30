//incluimos libreria para el LCD:
#include <LiquidCrystal.h>

// declarar pantalla LCD y asignar
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  // iniciar pantalla indicando # de columnas y filas
  lcd.begin(16, 2);
  //Escribimos en la posicion 0,0
  lcd.setCursor(0,0);
  lcd.print("!Bienvenido!");
}
void loop() {
  // Esperamos 0.5 segundos
  delay(500);
  // Limpiamos la pantalla
  lcd.clear();
  //Escribimos en la posicion 0,1
  lcd.setCursor(0, 1); 
  // Imprimimos en la pantalla
  lcd.print("Hola amigo :)");
  delay(500);
  // Limpiamos la pantalla
  lcd.clear();
  delay(500);
}
