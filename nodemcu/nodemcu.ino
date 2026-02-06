#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>

#define WIFI_SSID "ALHN-0895"
#define WIFI_PASSWORD "3797255625"
WiFiClientSecure secured_client;

#define BOT_TOKEN "7681869452:AAGgitL7jTsZf_OgmZG-apAtKTKEMJrgg8w"
#define CHAT_ID "5173361522"
const unsigned long BOT_MTBS = 100;
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;

SoftwareSerial s(D6, D5); // RX, TX
int data;

void setup() {
  //отладка
  Serial.begin(9600); 

  //связь с ардуино
  s.begin(9600);

  configTime(0, 0, "pool.ntp.org");
  secured_client.setTrustAnchors(&cert);
  Serial.print("Connecting to WiFi SSID...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.print("\nWiFi connected. IP adress: ");
  Serial.print(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Hi! I'm online.", "");
}

void loop() {
  s.write("s");
  bot.sendMessage(CHAT_ID, "Sent: s", "");

  if (s.available() > 0) {
    data = s.read();
    if (data == 50) {
      bot.sendMessage(CHAT_ID, "Recieved: 50", "");
    }
  }

  delay(5000);
}
