#include <Button.h>

int state = LOW;
int ledPin = 7;
Button ledButton = Button(8, PULLDOWN);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(ledButton.uniquePress()) {
    state = (state ==  HIGH) ? LOW : HIGH;
  }
  
  digitalWrite(ledPin, state);
}

  
