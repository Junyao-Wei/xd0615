char ch=' ';

void ctrl(int a,int b,int c, int d)
{
  digitalWrite(6,a);
  digitalWrite(7,b);
  digitalWrite(8,c);
  digitalWrite(9,d);
}

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.println("Ready!");
}

void loop()
{
  if(Serial.available()>0)
  {
    ch=Serial.read();
    
    switch(ch)
    {
      case 'f':
    	ctrl(HIGH,LOW,HIGH,LOW);
    	break;
      case 'b':
    	ctrl(LOW,HIGH,LOW,HIGH);
    	break;
      case 'r':
    	ctrl(LOW,HIGH,HIGH,LOW);
    	break;
      case 'l':
    	ctrl(HIGH,LOW,LOW,HIGH);
    	break;
      case 'x':
    	ctrl(LOW,LOW,LOW,LOW);
    	break;
      default:
    	break;
    }
  }
}