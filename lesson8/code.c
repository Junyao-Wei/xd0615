const int ledPin =  LED_BUILTIN;	//板载LED引脚的编号 

int ledState = LOW;             

unsigned long previousMillis = 0;        // 储存上一个周期的时间
// constants won't change :
const long interval = 1000;           // 设置闪烁间隔

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  unsigned long currentMillis = millis();		//获取当前的时间

  if (currentMillis - previousMillis >= interval) {	 //如果当前的时间与上一个周期的时间差大于等于闪烁间隔

    previousMillis = currentMillis;	//将上一个周期的时间修改为当前时间

    if (ledState == LOW) {	//确定LED的状态
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);	//改变引脚的电平
  }
}