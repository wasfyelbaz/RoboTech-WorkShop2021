#include <Servo.h>
#include <Keypad.h>

Servo motor;
int motorPin = 11;
String inputedAngel = "";

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  motor.attach(motorPin);
  motor.write(0);
}
  
void loop(){
  
  char inputedChar = customKeypad.waitForKey();
  
  if (inputedChar){
    if (inputedChar == '*') // if "*" key is clicked -> reset 
    {
      inputedAngel = "";
      motor.write(0);
      Serial.println("Reseting ..");
    }
    else
    {
    inputedAngel += inputedChar;
    
    int intInputedAngel = inputedAngel.toInt();
    while (intInputedAngel > 360)
    {
      intInputedAngel -= 360;
    }
    
    Serial.println("Moving to angel: " + inputedAngel);
    motor.write(intInputedAngel);
    delay(100);
    }
    
  }
  
}