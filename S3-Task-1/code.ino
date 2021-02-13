int buzzerPin = 12;
int diodePin = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(diodePin, INPUT);
}

void loop()
{
  int diodeValue = digitalRead(diodePin);
  if (diodeValue == 1)
  {
  	digitalWrite(buzzerPin, LOW);
  }
  else
  {
    digitalWrite(buzzerPin,HIGH);
  }
  Serial.println(diodeValue);
}