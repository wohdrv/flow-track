#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define WIFI_SSID "ALHN-0895"
#define WIFI_PASSWORD "3797255625"
#define BOT_TOKEN "7681869452:AAGgitL7jTsZf_OgmZG-apAtKTKEMJrgg8w"
#define CHAT_ID "5173361522"

WiFiClientSecure secured_client;
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

SoftwareSerial s(D6, D5);

const int sensorPin = A0;
bool isFlooded = false;

void setup() {
  Serial.begin(9600);
  s.begin(9600);

  configTime(0, 0, "pool.ntp.org");
  secured_client.setTrustAnchors(&cert);

  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nWiFi connected.");
  
  bot.sendMessage(CHAT_ID, "Flow track activated.", "");
}

void loop() {
  int waterLevel = analogRead(sensorPin);
  if (waterLevel > 400 && !isFlooded) {
    Serial.println("Leak detected!");
    bot.sendMessage(CHAT_ID, "Water detected!!!", "");
    s.write('1'); 
    delay(5000); 
    bot.sendMessage(CHAT_ID, "Tap is closed.", "");
    isFlooded = true; 
  }
}
