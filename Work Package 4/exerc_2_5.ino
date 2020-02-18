#include <Keypad.h>
#include <Wire.h> 

char scanKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'F','0','E','D'}
};
byte rowPins[ROWS] = {11,10,9,8}; //row pinouts
byte colPins[COLS] = {7,6,5,4}; //column pinouts

Keypad keyboard = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 


void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  scanKey = keyboard.getKey();
  switch (scanKey) {
    case '0' ... 'F':
    	Serial.println(scanKey);
    	break;
  }
//  delay(1000);
}