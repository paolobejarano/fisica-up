#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int piezo=10;
int led=11;
int LDRpin=A0;
int IN1=12;
int IN2=13;
int LDRval;
int estado=0; //estado=0 (cortina cerrada), estado=1 (cortina abierta)
int u_hora; //unidades de hora
int d_hora; //decenas de hora
int u_minuto; // unidades de minuto
int d_minuto; //decenas de minuto
int u_segundo; //unidads de segundo
int d_segundo; //decenas de segundo
long timer1=0; // variable temporal que almacena los segundos
long timer2=0; // variable temporal que almacen los segundos


void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(LDRpin,INPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (piezo, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  un_seg();
  contador();
  escribe_hora();
  LDRval=analogRead(LDRpin);
  if ((LDRval >= 500)&&(estado==0)){ //si hay luz, se abre la cortina
    tono_titanic(); // suena una melodía mientras se abre la cortina
    horario(IN1,IN2);
    digitalWrite(led,HIGH);
    Serial.println("Cortinas se suben");
    escribe_hora_serial();
    delay(1000); // para hacer referencia al tiempo que le demora abrir la cortina
    parar(IN1,IN2);
    digitalWrite(piezo, LOW);
    estado=1;
    delay(1000);// para hacer referencia al tiempo que le demora abrir la cortina
  }
  if ((LDRval <= 500)&&(estado==1)){ //si no hay luz, y esta abierta la persiana, se cierra
    antihorario(IN1,IN2);
    digitalWrite(led,LOW);
    Serial.println("Cortinas se bajan");
    escribe_hora_serial();
    delay(1000); // para hacer referencia al tiempo que le demora cerrar la cortina
    parar(IN1,IN2);
    estado=0;
    delay(1000); // para hacer referencia al tiempo que le demora cerrar la cortina
  }
  delay(1000);
}

int horario (int m,int n){
  digitalWrite(m,HIGH);
  digitalWrite(n,LOW);
}

int antihorario(int m, int n){
  digitalWrite(m,LOW);
  digitalWrite(n,HIGH);
}

int parar(int m,int n){
  digitalWrite(m,LOW);
  digitalWrite(n,LOW);
}

//Código de las funciones del reloj
void un_seg(){    //Rutina para cada segundo  
timer2=(millis()/1000);    //millis() es una funcion que lee los milisegundos desde que empieza a correr el programa
if ( timer1 != timer2 ) {
 timer1=timer2;
 u_segundo++;    // unidades de segundo
  //se incrementa cada segundo       
 }     
}
 
void contador(){ // Rutina para el reloj
if ( u_segundo == 10 ) {// cuando llega a 10, se suma una decena
u_segundo =0;
d_segundo++;} 
if ( ( d_segundo == 6 ) && ( u_segundo == 0 ) ){ // cuando llega a 60 segundos, se suma un minuto
d_segundo =0;
u_minuto++;} 
// Rutina de minutos
if ( u_minuto == 10 ) {// cuando llega a 10, se suma una decena
u_minuto =0;
d_minuto++; } 
if ( ( d_minuto == 6 ) && ( u_minuto == 0 ) ){ // cuando llega a 60 minutos, se suma una hora
d_minuto =0;     
u_hora++;} 
// Rutina de horas
if ( u_hora == 10 ) { // cuando llega a 10, se suma una decena
u_hora =0;
d_hora++; } 
 
if ( (d_hora == 2) &&  (u_hora == 4) ) { // cuando llega a 24 horas, se empieza de nuevo con 0
u_hora =0; 
d_hora =0; } 
}
   
void escribe_hora(){ //Rutina para escribir la hora en el LCD

  lcd.setCursor(1,0);  //Situa el cursor en la segunda posición de la primera línea
  lcd.print("Reloj Arduino"); //Escribe el texto entre comillas
  lcd.setCursor(3, 1);  //Situa el cursor en la cuarta posición de la segunda línea
  lcd.print(d_hora);    //Escribe la cantidad almacenada en la variable d_hora
  lcd.print(u_hora);    //Escribe la cantidad almacenada en la variable u_hora
  lcd.print(":");        //Escribe el texto entre comillas
  lcd.print(d_minuto);  //Escribe la cantidad almacenada en la variable d_minuto
  lcd.print(u_minuto);  //Escribe la cantidad almacenada en la variable u_minuto
  lcd.print(":");        //Escribe el texto entre comillas
  lcd.print(d_segundo);  //Escribe la cantidad almacenada en la variable d_segundo
  lcd.print(u_segundo);  //Escribe la cantidad almacenada en la variable u_segundo

}

void escribe_hora_serial(){// escribe la hora con mismo formato en el serial
  Serial.print(d_hora);
  Serial.print(u_hora);
  Serial.print(":");
  Serial.print(d_minuto);
  Serial.print(u_minuto);
  Serial.print(":");
  Serial.print(d_segundo);
  Serial.println(u_segundo);
}

void tono_titanic(){  // tono (piezo,frecuencia, duración)
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,349,250); 
  delay(250);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,330,500); 
  delay(500);
  tone(piezo,349,1000); 
  delay(1000);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,330,500); 
  delay(500);
  tone(piezo,349,1000); 
  delay(1000);
  tone(piezo,392,500); 
  delay(500);
  tone(piezo,440,1000); 
  delay(1000);
  tone(piezo,392,1000); 
  delay(1000);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,349,250); 
  delay(250);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,330,500); 
  delay(500);
  tone(piezo,349,500); 
  delay(500);
  tone(piezo,392,1000); 
  delay(1000);
  tone(piezo,262,2000); 
  delay(2000);
}
