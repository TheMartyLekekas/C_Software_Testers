/* ====================================
File name: exerc_5_2.c
Date: 2020-03-5
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [23203]
!====================================== */

#include <avr/io.h>
#include <util/delay.h>
#include <Keypad.h>
#include <Wire.h>

bool keyPressed = false;
int col, row;
char key;


char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};

void setRowLow(int R) {
  switch(R){
    case 3:
    	PORTB = B00001110;
          break;
    case 2:
    	PORTB = B00001101;
          break;
    case 1:
    	PORTB = B00001011;
          break;
    case 0:
    	PORTB = B00000111;
          break;
  }
}

int checkColumn(){
  if((PIND & (1 << PD7)) == 0){
    return 0;
  }
  else if((PIND & (1 << PD6)) == 0){
    return 1;
  }
  else if((PIND & (1 << PD5)) == 0){
    return 2;
  }
  else if((PIND & (1 << PD4)) == 0){
    return 3;
  }
  else{
    return -1;
  }
}


void keyboardirq(){
  //iterate over the rows
    for(int i=0; i < 4; i++) {
      row = i;
      setRowLow(i);
      col = checkColumn();

      if(col != -1){
        keyPressed = true;
        key = keys[row][col];
        break;
      }

    }

}

void setup()
{
  Serial.begin(9600);
  DDRD = 0x00;
  DDRB = 0b00001111;

  attachInterrupt(digitalPinToInterrupt(2), keyboardirq , FALLING);

}

void loop()
{
    col = 0;
    row = 0;
    PORTB = 0b00000000;
  if (keyPressed){
    Serial.println(key);

    int read = analogRead(A0);
    int voltage = read * 5;
    float temperature = (voltage - 500)/10;
    Serial.println(temperature);
  }
  keyPressed = false;

//delay(500);
}
