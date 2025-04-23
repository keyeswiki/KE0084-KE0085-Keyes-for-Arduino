int buzzer = 2;                     //定义数字口2
void setup()
{
  pinMode(buzzer, OUTPUT);     //设置led为输出
}
void loop()
{
  digitalWrite(buzzer, HIGH);   //开启buzzer
  delay(1000); //延迟1S               
  digitalWrite(buzzer, LOW);    //关闭buzzer
  delay(1000);//延迟1S
}
