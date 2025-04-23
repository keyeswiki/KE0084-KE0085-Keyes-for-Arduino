int led = 2;                     //定义数字口2
void setup()
{
  pinMode(led, OUTPUT);     //设置led为输出
}
void loop()
{
  digitalWrite(led, HIGH);   //开启led
   delay(2000); //延迟2S               
  digitalWrite(led, LOW);    //关闭led
  delay(2000);//延迟2S
}
