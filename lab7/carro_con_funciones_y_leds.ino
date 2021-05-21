int ledrojo=6;
int ledverde=7;
int IN1=9;
int IN2=8;
int IN3=11;
int IN4=10;
int ECHO=12;
int TRIG=13;

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
  if (sensor_distancia(ECHO,TRIG)<50){
    parar(IN1,IN2,IN3,IN4);
    delay(1000);
    retroceder(IN1,IN2,IN3,IN4);
    delay(1000);
    girar(IN1,IN2,IN3,IN4);
    avanzar(IN1,IN2,IN3,IN4);
  }
  else {
    avanzar(IN1,IN2,IN3,IN4);
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
  delay(1000);
  horario(in1,in2);
  horario(in3,in4);
  digitalWrite(ledverde,HIGH);
}

void retroceder (int in1, int in2, int in3, int in4){
  digitalWrite(ledverde,LOW); // se apaga el ledverde antes de prenderse el rojo
  delay(1000);
  antihorario(in1,in2);
  antihorario(in3,in4);
  digitalWrite(ledrojo,HIGH);
}

void parar (int in1, int in2, int in3, int in4){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void girar (int in1, int in2, int in3, int in4){
  horario(in1,in2);
  antihorario(in3,in4);
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
