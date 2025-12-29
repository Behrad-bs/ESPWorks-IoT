//Command sender
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* mqttServer = "broker.hivemq.com";  // or your VPS IP
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

#define LED_PIN 2

void callback(char* topic, byte* payload, unsigned int length) {
  String command = "";

  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }

  if (command == "ON") {
    digitalWrite(LED_PIN, HIGH);
    client.publish("response/topic", "LED turned ON");
  }
  else if (command == "OFF") {
    digitalWrite(LED_PIN, LOW);
    client.publish("response/topic", "LED turned OFF");
  }
  else if (command == "STATUS") {
    client.publish("response/topic", "ESP is running");
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    client.connect("ESP_Receiver");
  }

  client.subscribe("command/topic");
}

void loop() {
  client.loop();
}


//Command Receiver
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* mqttServer = "broker.hivemq.com";  // or your VPS IP
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

#define LED_PIN 2

void callback(char* topic, byte* payload, unsigned int length) {
  String command = "";

  for (int i = 0; i < length; i++) {
    command += (char)payload[i];
  }

  if (command == "ON") {
    digitalWrite(LED_PIN, HIGH);
    client.publish("response/topic", "LED turned ON");
  }
  else if (command == "OFF") {
    digitalWrite(LED_PIN, LOW);
    client.publish("response/topic", "LED turned OFF");
  }
  else if (command == "STATUS") {
    client.publish("response/topic", "ESP is running");
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    client.connect("ESP_Receiver");
  }

  client.subscribe("command/topic");
}

void loop() {
  client.loop();
}
