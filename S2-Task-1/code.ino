int led = 11;
int buzzer = 10;
int pushBtn = 12;

void setup()
{
  pinMode(13, led);
  pinMode(13, buzzer);
  pinMode(13, pushBtn);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char input_char = Serial.read();
    
    if (input_char == 'l')
    {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
    }
    else if (input_char == 'b')
    {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
  }
    int btnValue = digitalRead(pushBtn);
  
  	if (btnValue == 1)
    {
		Serial.println("push button is pressed");
    }
}