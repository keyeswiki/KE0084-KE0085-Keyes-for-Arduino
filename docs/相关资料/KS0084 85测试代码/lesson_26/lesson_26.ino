int MIC=A0;//定义声音传感器为模拟0 接口
int LED=9;//定义LED接口为数字9 接口
int val=0;//定义数字变量
 void setup() 
{
  pinMode(LED,OUTPUT);//定义LED 为输出接口
 pinMode(MIC,INPUT);//定义声音传感器为输入接口
 Serial.begin(9600);//设定波特率为9600 
 } 
void loop() 
{ 
  val=analogRead(MIC);//读取声音传感器的模拟值 
  Serial.println(val);//输出模拟值，并将其打印出来
  if(val>=300)//当模拟值大于300 时LED亮起
  {  
   digitalWrite(LED,HIGH); 
   }else 
   {  
     digitalWrite(LED,LOW); 
    }
   delay(500); 
}
