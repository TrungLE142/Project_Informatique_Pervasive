


long R0 = 100000;
int B= 4275;
float temp =0;

//Capteur sonore
void getSonore(){
  int somme = 0;
    for( int i = 0; i<=32; i++){
      somme = somme + analogRead(A1);
    }
    int sonore = somme >>5;
    Serial.println("Valeur du capteur sonore:");
    Serial.println(sonore);
}


//Capteur temperature
void getTemperature() {
  int a = analogRead(A0);
  // calculer la temperature
  Serial.println("Valeur du temp:");
  float R1 = 1023.0 / a - 1.0;
  float R = R0 * R1;
  temp = 1.0 / ( log(R / R0) / B + 1 / 298.15 ) - 273.15;
  int temp1 = (int)temp;
  Serial.println("Valeur du temperature: " + templ);
  Serial.println(temp1);
}

//capture humidite
void getHumidite() {
  // calculer l'humidité
  int a = analogRead(A3);
  Serial.println("Valeur de l'humidité: ");

  if( 0<a<300){
    Serial.println("sec ou peu humide avec l'humidité: "  );
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
}

//capture lumiere
void getluminosite() {
   int light = analogRead(A2);
   Serial.print("Light = ");
   Serial.println(light);
}



// constants won't change. They're used here to set pin numbers:
const int buttonPin = 6;    // the number of the pushbutton pin

// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
bool msg_status = true;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
unsigned long tempsdepart=0;
unsigned long tempsfin=0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  tempsdepart=millis();
  tempsfin=tempsdepart + 1000;
}


void loop() {
  if(millis()>tempsfin){
    tempsfin =millis() +10000;
    if (msg_status){
      getSonore();
      getTemperature();
      getHumidite();
      getluminosite(); 
    }
  }else{
      test_button();
  }
}
    
bool test_button(){
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if(buttonState == HIGH){
       Serial.println(msg_status);
       msg_status = !msg_status;  
      }
    }
  }
  lastButtonState = reading;
}
