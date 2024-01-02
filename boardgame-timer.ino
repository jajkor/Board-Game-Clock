#include <LiquidCrystal.h>

const uint8_t selectA = 2;
const uint8_t selectB = 3;

const uint8_t redButton = 4;
const uint8_t yellowButton = 5;
const uint8_t blueButton = 6;
const uint8_t whiteButton = 7;

uint8_t index = 0b00;

LiquidCrystal lcd(13, 14, 9, 10, 11, 12);

void setup() {  
  lcd.begin(16, 2);
  lcd.print("Game Start!");

  pinMode(selectA, OUTPUT);
  pinMode(selectB, OUTPUT);
  pinMode(redButton, INPUT);
  pinMode(yellowButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(whiteButton, INPUT);
}

void buttonWait(int buttonPin){
  int buttonState = 0;
  while(1) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      lcd.clear();
      increment(&index);
      return;
    }
  }
}

void increment(uint8_t *index) {
  *index = (*index + 0b01) & 0b11;
  if (*index > 0b11) {
    *index = 0b00;
  } 
}

char* prettyprint(unsigned long milliseconds) {
  char* time = (char*)malloc(20 * sizeof(char));
  sprintf(time, "%2lu:%2lu:%2lu:%2lu", milliseconds / 360000, milliseconds / 60000, milliseconds / 1000, milliseconds % 60);
  return time;
}

void loop() {
  unsigned long startTime = millis();
  
  switch (index) {
    case 0b00:
        digitalWrite(selectA, LOW);
        digitalWrite(selectB, LOW);
        buttonWait(redButton);
        break;
    case 0b01:
        digitalWrite(selectB, HIGH);
        buttonWait(yellowButton);
        break;
    case 0b10:
        digitalWrite(selectA, HIGH);
        digitalWrite(selectB, LOW);
        buttonWait(blueButton);
        break;
    case 0b11:
        digitalWrite(selectB, HIGH);
        buttonWait(whiteButton);
        break;
  }
  lcd.print("hh:mm:ss:ms");
  lcd.setCursor(0, 2);
  
  char* time = prettyprint(millis() - startTime);
  lcd.print(time);
  free(time);
}
