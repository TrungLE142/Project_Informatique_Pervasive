#include "WiFiEsp.h"
#include <PubSubClient.h>
#include "SoftwareSerial.h"


SoftwareSerial Serial1(2, 3); // RX, TX
char ssid[] = "proto";     // your network SSID (name)
char pwd[] = "azertyuio";  // your network password
IPAddress server(192, 168, 1, 132);
WiFiEspClient wifiClient;
PubSubClient client(wifiClient);
IPAddress ip;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("J'ai reçu un message");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("client_name")) { //Name of the client
      client.setCallback(callback);
      Serial.println("connected");
    } else {
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);
  client.setServer(server, 1883);
  WiFi.init(&Serial1);
  WiFi.begin(ssid, pwd);
  ip = WiFi.localIP();
}

void loop(){ 
  client.loop();
  if(!client.connected()){
    reconnect();
  }
}
