int Relay = 3; //定义数字口3
void setup()
{
pinMode(Relay, OUTPUT); //将Relay设置为输出
}
void loop()
{
digitalWrite(Relay, HIGH); //打开继电器
delay(2000); //延时2S
digitalWrite(Relay, LOW); //关闭继电器
delay(2000); //延时2S
}
