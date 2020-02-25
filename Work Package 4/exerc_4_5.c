/* ====================================
File name: exerc_4_5.c
Date: 2020-02-18
Group nr 11
Members that contributed to the solutions
Martynas Lekeckas
Al-Amir Teniola Abidemi Adegbuji-Onikoyi
Sebastian Baszczynski
Member not present at demonstration time:
-
Demonstration code: [28349]
!====================================== */

#include <Keypad.h>
#include <Wire.h> 

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};

void setup()
{
  Serial.begin(9600);
  DDRD = 0x0;
  DDRB = B00001111;
}

void loop()
{
  bool found = false;
  
  if(!found){
    found = check(3);
    if(!found){
      found = check(2);
      if(!found){
  	    found = check(1);
        if(!found){
  	      check(0);
  	    }
  	  }
    }
  }
   
  delay(500);
}

bool check(int R) {
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
    
  if(PIND != B11110011){
    int binchar[8], rest, i=0, C;
    rest = PIND;
    while(rest!=0){
         binchar[i++]= rest % 2;
         rest = rest / 2;
    }
    if(binchar[4] == 0){
    C = 3;}
    if(binchar[5] == 0){
    C = 2;}
    if(binchar[6] == 0){
    C = 1;}
    if(binchar[7] == 0){
    C = 0;}
    printKey(R,C);
    return true;
  }
  return false;
}

void printKey(int R, int C){
	Serial.println(keys[R][C]);
}