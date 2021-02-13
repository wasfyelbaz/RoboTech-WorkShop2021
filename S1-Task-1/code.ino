int buzzerPin = 13;
int ledPin = 6;
int btnPin = 7;

void setup()
{
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(btnPin, INPUT);
}

void loop()
{
	int btnValue = digitalRead(btnPin);
  
  	if (btnValue == 1)
    {
		digitalWrite(buzzerPin, HIGH);
      	digitalWrite(ledPin, HIGH);
    }
  	else  
    {
      	digitalWrite(buzzerPin, LOW);
        digitalWrite(ledPin, LOW);
    }
  
}