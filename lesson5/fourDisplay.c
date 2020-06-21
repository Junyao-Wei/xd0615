#include <string.h>

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11


#define LT 6
#define BT 7

String str;

int income=0;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(LT, OUTPUT);
  pinMode(BT, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
    
   
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  digitalWrite(S4,LOW);
  
  
}



void loop()
{
  if(Serial.available()>0)
  {
  	str=Serial.readString();
    
    for(int i=8;i<=11;i++)
    {
      income=str[i-8]-48;
      
      income=income-'0';
      
      digitalWrite(i,LOW);
      digitalWrite(2,income&0x1);
      digitalWrite(3,(income>>1)&0x1);
      digitalWrite(4,(income>>2)&0x1);
      digitalWrite(5,(income>>3)&0x1);
      digitalWrite(i,HIGH);
      
  	  delay(100);
    }
    
  }
}