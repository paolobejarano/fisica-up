int motor1 = 3;    // pin del motor 1
int motor2 = 7;    // pin del motor 2

void setup()
{
  Serial.begin(9600);
  pinMode (motor1, OUTPUT); 
  pinMode (motor2, OUTPUT);
}

void loop()
{
  digitalWrite(motor1,HIGH); // encender el motor 1
  digitalWrite(motor2,HIGH); // encender el motor 2
  delay(100);
  digitalWrite(motor1,LOW); // apagar el motor 1
  digitalWrite(motor2,LOW); // apagar el motor 2
  delay(100);
}
