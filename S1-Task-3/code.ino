int led1Pin = 3;
int led2Pin = 5;
int potPin = A0;

void setup()
{
  	pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
    pinMode(potPin, INPUT);
}

void loop()
{
	int potValue = analogRead(potPin);
  	int mapValue = map(potValue, 0, 1023, 0, 255);

   	analogWrite(led1Pin, mapValue);
   	analogWrite(led2Pin, 255 - mapValue);
}