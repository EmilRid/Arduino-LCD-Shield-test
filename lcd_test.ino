
#include <LiquidCrystal.h>

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
int cursorX = 0, cursorY = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.cursor();
  lcd.createChar(1, smileBin);
}

void buttonStatus(){
  lcd.setCursor(cursorX, cursorY);
  int x = analogRead (0);
  if (x < 90) {
    button = "r";
    cursorX++;
    if(cursorX == 16){
      cursorX = 0;
      cursorY = 1;
    }}else if (x < 200) {
    button = "u";
    if(cursorY != 0) {
      cursorY--;
    }}else if (x < 400){
    button = "d";
    cursorY++;
  }else if (x < 600){
    button = "l";
    cursorX--;
    if(cursorX == -1) {
      cursorX = 15;
      cursorY = 0;
    }}else if (x < 800){
    button = "s";
  }
  delay(100);
}

void doodle(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("override me");
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("by emil ridulfo");
  while(true){
  buttonStatus();
  if(button == "s") {
    lcd.write(1);
    }
  }
}

void randomNumber(){
  lcd.setCursor(0,1);
  lcd.print("This is 'random'");
  lcd.write(1);
  while(true){
  lcd.setCursor(0, 0);
  lcd.print(random());
  delay(500);
  }
}

void menu(){
  lcd.setCursor(0, 0);
  lcd.print("1. Doodle");
  lcd.setCursor(0, 1);
  lcd.print("2. Random Number");
  while(true) {
    buttonStatus();
    if(button == "s"){
      delay(100);
      if(cursorY == 0){
      doodle();
      }
      else if(cursorY == 1){
      randomNumber();
      }
    }
  }
}

void loop() {
  menu();
}
