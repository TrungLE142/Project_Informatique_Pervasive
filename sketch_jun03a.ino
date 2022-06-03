const int buttonPin = 6;
const int ledPin = 8;
int ledState = HIGH;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


int buttonState = 0;
unsigned long tempsdepart=0;
unsigned long tempsfin=0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
  tempsdepart=millis();
  tempsfin=tempsdepart + 10000;
   
} 
   
void loop() {
    buttonState = digitalRead(7);
    
   if(buttonState == 1)
   {
     Serial.println("Pris de captation");
   if(millis()>tempsfin){
    tempsfin =millis() +10000;
    int somme = 0;
    for( int i = 0; i<=32; i++){
      somme = somme + analogRead(A1);
    }
    int sonore = somme >>5;
    Serial.println("Valeur du capteur sonore:");
    Serial.println(sonore);
   }
  }

  test_button();
}


// a supprimer  

bool test_button(){
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if(buttonState == HIGH){
        ledState = !ledState;
        digitalWrite(8, ledState);
      }
    }
  }
  lastButtonState = reading;
}


     



 
