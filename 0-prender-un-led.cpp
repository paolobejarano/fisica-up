// Declarar la variable led como integer y asignar valor
int led = 13;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  // Prender led
  digitalWrite(led, HIGH);
  
  // Esperar 1 segundo
  delay(1000);
  
  // Apagar led
  digitalWrite(led, LOW);
  
  // Esperar 1 segundo
  delay(1000);
}
