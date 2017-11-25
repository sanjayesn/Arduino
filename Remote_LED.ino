#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define BUTTON_UP 0xFF18E7
#define BUTTON_DOWN 0xFF4AB5

int ledPin = 7;
int recvPin = 11;

IRrecv irrecv(recvPin);
decode_results results;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn();
  
}

//+=============================================================================
// Display IR code
//
void  ircode (decode_results *results)
{
  // Panasonic has an Address
  if (results->decode_type == PANASONIC) {
    Serial.print(results->address, HEX);
    Serial.print(":");
  }

  // Print Code
  Serial.print(results->value, HEX);
}

void loop() {
  if(irrecv.decode(&results)) {
    Serial.print("CODE: ");
    ircode(&results);
    Serial.println("");
    if(results.value == BUTTON_UP) {
      digitalWrite(ledPin, HIGH);
    }
    else if(results.value == BUTTON_DOWN) {
      digitalWrite(ledPin, LOW);
    } 
    irrecv.resume();
  }
}



