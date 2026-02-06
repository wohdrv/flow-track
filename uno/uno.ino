#include <SoftwareSerial.h>
SoftwareSerial s(5,6); //RX, TX

void setup() {
  // put your setup code here, to run once:
  s.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data=50;
  if(s.available()>0)
  {
    char c=s.read();
    if(c=='s')
    {
      s.write(data);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(200);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
