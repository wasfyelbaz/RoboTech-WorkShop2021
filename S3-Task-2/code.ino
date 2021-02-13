int ledValue, ledPin = A1;
int sensorValue, sensorPin = A0;
float value;
unsigned long res;

void autoLed(int sensorPin, int ledPin)
{
  sensorValue = analogRead(sensorPin);
  value = (sensorValue / 1023.0)*5.0;
  res = (1000 * value) / (5 - value);

  int ledValue = map(res, 506, 16950, 255, 0);
  analogWrite(ledPin, ledValue);
  Serial.println(ledValue);
}

void setup()
{
  Serial.begin(6900);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop()
{

  autoLed(sensorPin, ledPin);

  delay(100);
}