//incluimos librerias
#include <LiquidCrystal.h>
#include <Keypad.h>  

// declarar pantalla LCD y asignar
LiquidCrystal lcd(13,12,11,10,9,8);
int piezo=3;  
const byte filas= 4; //numero de filas
const byte columnas= 4; //numero de columnas

// define la ubicación de las teclas según su fila y columna
char keymap[filas][columnas]= 
{
{'1', '2', '3', 'A'}, // se asigna 'A' para resetear el código
{'4', '5', '6', '+'}, // se asigna 'B' para la suma
{'7', '8', '9', '-'}, // se asigna 'C' para la resta
{'*', '0', '=', '/'}  // se asigna 'D' para la división y # para el signo '='
};

// se declaran los pines donde se conectan las filas y columnas
byte pinesFilas[filas] = {A0,A1,A2,A3}; //pines de las filas
byte pinesColumnas[columnas]= {7,6,5,4}; //pines de las columnas

//Se define el Teclado con los parametros defines anteriormente (pines, filas y columnas)
Keypad Teclado= Keypad(makeKeymap(keymap), pinesFilas, pinesColumnas, filas, columnas);


String leeCadena1,leeCadena2; // variable temporal para almacenar los números que se operarán
int cuenta=0; // contabiliza la cantidad de números a operar
char a; // almacena las teclas que son operaciones
long dato1,dato2,rpt1; // almacena números enteros para las operaciones: +,*,-
double dato3,dato4,rpt2; // almacena números decimales para la divisón

char key; // se almacena la variable de la tecla

void setup(){
  lcd.begin(16,2); //LCD (16 COLUMNAS Y 2 FILAS)
  pinMode(piezo,OUTPUT);
}

void loop(){
  key = Teclado.getKey();
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
    
      if(cuenta==0){
        lcd.print(key);
        leeCadena1+=key; // para ir agregando los digitos al numero       
        dato1=leeCadena1.toInt();  // toInt() Nueva función (PONER EJEMPLITO)
      }
      
      else if(cuenta==1){
        lcd.print(key);
        leeCadena2+=key; // para ir agregando los digitos al numero
        dato2=leeCadena2.toInt();
      }
    
   
  }

  if(key=='A'){ // sirve para resetear todo de nuevo
    digitalWrite(piezo,LOW);
    leeCadena2="";
    leeCadena1="";
    dato1=0;
    dato2=0;
    dato3=0;
    dato4=0;
    cuenta=0;
    rpt1=0;
    rpt2=0;
    lcd.clear();
  }
  
  else if(key=='='&&a=='+'){ // Srive para poder realizar la suma
    cuenta++; //
    lcd.setCursor(0,2);
    rpt1=dato1+dato2;
    lcd.print("RPT=");
    lcd.print(rpt1);
  }

  else if(key=='='&&a=='-'){ // Sirve para poder realizar la resta
    cuenta++;
    lcd.setCursor(0,2);
    rpt1=dato1-dato2;
    lcd.print("RPT=");
    lcd.print(rpt1);
  }
  else if(key=='='&&a=='*'){ // Sirve para poder realizar la multiplicación
    cuenta++;
    lcd.setCursor(0,2);
    rpt1=dato1*dato2;
    lcd.print("RPT=");
    lcd.print(rpt1);
  }
  else if(key=='='&&a=='/'){ // Sirve para poder realizar la división
    cuenta++;
    lcd.setCursor(0,2);
    dato3=dato1;  // el 
    dato4=dato2;
    lcd.print("RPT=");
    rpt2=(dato3/dato4);
    lcd.print(rpt2);
  }

  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&& cuenta==0){ // sirve para almacenar el operador matemático
    cuenta++;
    a=key;
    lcd.print(a);
  }
  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&& cuenta==1){ // si se desea agregar un número más, suena el buzzer
    digitalWrite(piezo,HIGH);
  }
}
