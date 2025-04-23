int buzzer=3;          //定义数字口3
void setup() 
{ 
pinMode(buzzer,OUTPUT);//将buzzer设置为输出
} 
void loop() 
{ 
unsigned char i,j;//定义变量i，j
while(1) 
{ 
for(i=0;i<80;i++)// 输出一个频率的声音
{ 
digitalWrite(buzzer,HIGH);
delay(1);//延迟1ms 
digitalWrite(buzzer,LOW);
delay(1);//延迟1ms 
} 
for(i=0;i<100;i++)//  输出另一个频率的声音
{ 
digitalWrite(buzzer,HIGH); 
delay(2);//延迟2ms 
digitalWrite(buzzer,LOW); 
delay(2);//延迟2ms 
}
} 
} 
