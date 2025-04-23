int flame=7;//定义火焰接口为数字7 接口
int Beep=9;//定义蜂鸣器接口为数字9 接口
void setup() 
{
 pinMode(Beep,OUTPUT);//定义Beep为输出接口
 pinMode(flame,INPUT);//定义flame为输入接口
 } 
void loop() 
{ 
  int val=digitalRead(flame);//读取火焰传感器 
  if(val==HIGH)//当数字口7为高电平时蜂鸣器鸣响
  {  
   digitalWrite(Beep,HIGH); 
   }else 
   {  
     digitalWrite(Beep,LOW); 
    }
   delay(500); 
}
