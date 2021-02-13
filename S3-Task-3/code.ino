#include <LiquidCrystal.h>

LiquidCrystal lcd{13, 12, 2, 3, 4, 5};
int TMPPin = A0;
int trigPin = 6, echoPin = 7;

float tmp(int pin)
{
  int TMPValue = analogRead(pin);
  float mv = TMPValue / 1023.0;
  mv *= 5;
  mv -= .5;
  mv *= 1000;
  float cl = mv / 10;
  return cl;
}

float getDistance(int trigPin, int echoPin)
{
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 29 / 2;
  return distance;
}

void setup()
{
  lcd.begin(16, 2);
  pinMode(TMPPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop()
{
  lcd.print("DIST: ");
  lcd.print(getDistance(trigPin, echoPin));
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("TEMP: ");
  lcd.print(tmp(TMPPin));
  lcd.print("C");
  delay(1000);
  lcd.clear();
}