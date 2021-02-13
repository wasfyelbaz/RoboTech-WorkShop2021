int ledPins[5] = {2, 3, 4, 5, 6};

void setup()
{
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);
  pinMode(ledPins[4], OUTPUT);

}

void loop()
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
}