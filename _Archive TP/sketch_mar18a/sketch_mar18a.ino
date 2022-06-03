
 
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 // long R0=100000;
//  int B=4275;
  // 
  //float R = 1023 / ( a - 1 ) * R0;  
  // int v = 1.0 / ( log(R / R0) / (B + 1) / 298.15 ) - 273.15;
 


int a =  analogRead(A0);
long  R0=100000;
int B=4275;
float R1 = 1023.0 / a - 1.0; 
float R = R0 * R1;

float  temp = 1.0 / ( log(R / R0) / B + 1 / 298.15 ) - 273.15;
int temp1 = (int) temp;


int b  = analogRead(A1);
int c  = analogRead(A2);
int d  = analogRead(A3);

 
  analogRead(A2);

 
  if(d < 300) 
  { 
    Serial.println("peu humide" ); 
     analogWrite(9,0);
  }
    if(d > 300) 
  { 
    Serial.println(" humide" ); 
   analogWrite(9,100);
  }
Serial.println(temp1);
Serial.println(b); 
Serial.println(c);
Serial.println(d);
delay(1000);
}
