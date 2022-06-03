//Temperature
// the setup function runs once when you press reset or power the board
long R0 = 100000;
int B= 4275;
float temp =0;

void setup() {
// initialize Serial port
  Serial.begin(9600);
}
void loop() {
  int a = analogRead(A0);
  // calculer la temperature
  Serial.println("Valeur du temp:");
  float R1 = 1023.0 / a - 1.0;
  float R = R0 * R1;
  temp = 1.0 / ( log(R / R0) / B + 1 / 298.15 ) - 273.15;
  int temp1 = (int)temp;
  Serial.println(temp1);
  delay(10000);
}


//Humidite
void setup() {
  // initialize Serial port
  Serial.begin(9600);
}
void loop() {
  // calculer l'humidité
  int a = analogRead(A3);
  Serial.println("Valeur de l'humidité:");

  if( 0<a<300){
    Serial.println("sec ou peu humide avec l'humidité: ");
    Serial.println(analogRead(A3));
  }
  if( 300<a<700){
    Serial.println("humide avec l'humidité: ");
    Serial.println(a);
  }
  if( a>700){
    Serial.println("trop humide avec l'humidité: ");
    Serial.println(a);
  }
  delay(10000);
}

//Sonore
void setup() {
Serial.begin(9600);
}

void loop() {
  int somme = 0;
  for( int i = 0; i<=32; i++){
  somme = somme + analogRead(A1);
  
  int sonore = somme >>5;

  Serial.println("Valeur du capteur sonore:");
  Serial.println(sonore);

  delay(10000);
}

//Lumiere
void setup() {
   Serial.begin(9600);
}
void loop() {
   int light = analogRead(A2);
   Serial.print("Light = ");
   Serial.println(light);
   delay(10000);
}
