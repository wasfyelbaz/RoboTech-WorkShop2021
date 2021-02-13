int m1Pin1 = 5;
int m1Pin2 = 4;

int TMP = A0;

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

void setup()
{
  //Serial.begin(9600);
  pinMode(m1Pin1, OUTPUT);
  pinMode(m1Pin2, OUTPUT);
  pinMode(TMP, INPUT);
}

void loop()
{
  int TMPValue = tmp(TMP);
  
  if (TMPValue > 50)
  {
  digitalWrite(m1Pin1, HIGH);
  digitalWrite(m1Pin2, LOW);
  }
  
  else
  {
  
  digitalWrite(m1Pin1, LOW);
  digitalWrite(m1Pin2, LOW);
  }

}