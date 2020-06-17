void setup()
{
  int ledPin=0;
  for(ledPin=0;ledPin<=8;ledPin++)
  {
    pinMode(ledPin,OUTPUT);
  }
}

void loop()
{
  int i=0;
  for(i=0;i<=8;i++)
  {
    digitalWrite(i,HIGH);
    digitalWrite(i+1,HIGH);
    delay(100);
    digitalWrite(i,LOW);                             
  }
}