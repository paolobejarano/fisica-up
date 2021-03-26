// Declarar la variable led como integer y poner el valor en donde está conectado el pin
int led=13;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop(){

  // enciende
  digitalWrite(led,HIGH);
  
  //espera 1 segundo
  delay(1000);
  
  // apaga
  digitalWrite(led,LOW);
  
  //espera 1 segundo
  delay(1000);
}
