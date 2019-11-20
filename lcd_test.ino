
#include <LiquidCrystal.h>

byte slashBin[8] = {
  B00001,
  B00010,
  B00010,
  B00100,
  B00100,
  B01000,
  B01000,
  B10000,
};
byte smileBin[8] = {
  B00000,
  B00000,
  B01010,
  B01010,
  B00000,
  B11111,
  B01110,
  B00000,
};
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
String button = "";
int cursorX = 0;
int cursorY = 0;


void setup() {
  lcd.begin(16, 2);
  lcd.print("Override me");
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("By Emil Ridulfo");
  lcd.createChar(2, slashBin);
  lcd.createChar(1, smileBin);
}

void loop() {
  int x;
  x = analogRead (0);
  if (x < 90) {
    button = "r";
    cursorX++;
    if(cursorX == 16){
      cursorX = 0;
      cursorY = 1;
    }
  }
  else if (x < 200) {
    button = "u";
    if(cursorY != 0) {
      cursorY--;
    }
  }
  else if (x < 400){
    button = "d";
    cursorY++;
  }
  else if (x < 600){
    button = "l";
    cursorX--;
    if(cursorX == -1) {
      cursorX = 15;
      cursorY = 0;
    }
  }
  else if (x < 800){
    button = "s";
    lcd.print("a");
  }
  lcd.cursor();
  lcd.setCursor(cursorX,cursorY);
  delay(100);
}
/*

 */
 
