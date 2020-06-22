#include <MsTimer2.h>

int tick =0;
volatile int pinInterrupt =2;

void onTimer()
{
  if(tick>9)
  {
     tick=0;
  }

  display(tick++);
}

void display(int income)
{
  digitalWrite(4,income&0x1);
  digitalWrite(5,(income>>1)&0x1);
  digitalWrite(6,(income>>2)&0x1);
  digitalWrite(7,(income>>3)&0x1);
}

void onChange()
{
  tick=0;
}
  
void setup()
{
  pinMode(2, INPUT);
  for(int i=4;i<=10;i++)
  {
    pinMode(i,OUTPUT);
  }
  
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  
  Serial.begin(9600);
  
  MsTimer2::set(1000,onTimer);
  MsTimer2::start();
  
  attachInterrupt(digitalPinToInterrupt(pinInterrupt),onChange,FALLING);
}

void loop()
{
  
}