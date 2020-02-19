#include <avr/io.h>
#include <util/delay.h>
/* Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D*/

unsigned char  input;
	

void setup() {
	Serial.begin(9600);
//  If use of Serial monitor and in that case needed Port D bit 1,0 to be set as out/in
//  If use of Serial monitor Sets pin 2-7 as output-bits and Pin 1 and 0 as 10.
	DDRD = 0xFF; // To set all Port D bits as outbits
	DDRB = 0; 	 //....... ( Set all to inbits. You will only use bit 0.}
}

void loop() {
   delay(500);
}