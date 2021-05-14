int IN1=4;
int IN2=5;
int IN3=8;
int IN4=9;

void setup (){
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

int horario (int m, int n){
  digitalWrite(m,HIGH);
  digitalWrite(n,LOW);
}

int antihorario (int m, int n){
  digitalWrite(m,LOW);
  digitalWrite(n,HIGH); 
}

void loop (){
  horario(IN1,IN2); //movimiento en sentido horario del motor 1
  horario(IN3,IN4); //movimiento en sentido horario del motor 2
  delay(1000);
  antihorario(IN1,IN2); //movimiento en sentido antihorario del motor 1
  antihorario(IN3,IN4); //movimiento en sentido antihorario del motor 2
  delay(1000);
}
