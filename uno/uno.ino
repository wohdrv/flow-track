#include <SoftwareSerial.h>
#include <Stepper.h>

SoftwareSerial s(5, 6);

const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  s.begin(9600);

  myStepper.setSpeed(10); 
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (s.available() > 0) {
    char c = s.read();
    if (c == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      
      myStepper.step(stepsPerRevolution);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
