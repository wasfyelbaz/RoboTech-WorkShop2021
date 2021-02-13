#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd{13, 12, 11, 10, 9, 8};
String passwd = "1234";
String inputedPasswd = "";

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.begin(16, 2);
}
  
void loop(){
  char inputedChar = customKeypad.waitForKey();
  
  if (inputedChar){
    inputedPasswd += inputedChar;
    lcd.print(inputedChar);
  }
  if (inputedPasswd.length() == passwd.length() && inputedPasswd == passwd)
  {
    lcd.clear();
	lcd.print("Correct Password");
    delay(2000);
    lcd.clear();
    inputedPasswd = "";
  }
  else if (inputedPasswd.length() == passwd.length() && inputedPasswd != passwd)
  {
    lcd.clear();
	lcd.print("Wrong Password");
    delay(2000);
    lcd.clear();
    inputedPasswd = "";
  }
}