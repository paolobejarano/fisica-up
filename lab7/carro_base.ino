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
}

void loop()
{
  horario(IN1,IN2);
  antihorario(IN1,IN2);
  sensor_distancia(ECHO,TRIG);
  horario(IN3,IN4);
  antihorario(IN3,IN4);
}

int horario (int m, int n){
  digitalWrite(m,HIGH);
  digitalWrite(n,LOW);
}

int antihorario (int m, int n){
  digitalWrite(m,LOW);
  digitalWrite(n,HIGH); 
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
  Serial.print("Distancia :");
  Serial.print(distancia);
  Serial.println(" cm");
  return distancia;
  delay(1000);
}
