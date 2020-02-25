/* ====================================
File name: exerc_4_5.c
Date: 2020-02-25
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [46713]
!====================================== */

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
  	DDRD = 0xFF; // To set all Port D bits as outbits
	  DDRB = 0x00; //Set all to inbits. You will only use bit 0
  	PORTD = B00000011;
}

void loop() {
  if(PINB != B00000001) {
    delay(1000);
    PORTD = PORTD << 1;
    if(PORTD == B00000010){
      PORTD = B00000011;
    }
    if(PORTD == B10000000){
      PORTD = B10000001;
    }
  }
}
