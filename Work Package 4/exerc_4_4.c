#include <avr/io.h>
#include <util/delay.h>
/* Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D*/

unsigned char input;

void setup() {
  Serial.begin(9600);
	DDRD = 0xFF; // To set all Port D bits as outbits
	DDRB = 0x00; //Set all to inbits. You will only use bit 0
  	PORTD = B00000011;
  	PINB = B00000001;
  	PORTB = B00000001;
  	PINB = PB0;
}

void loop() {
  Serial.println(PORTD, BIN);
  if(PINB != B00000001) {

    delay(1000);
    PORTD = PORTD << 1;

    if(PORTD == B11000000){
      PORTD = B00000011;
    }
  }
}
