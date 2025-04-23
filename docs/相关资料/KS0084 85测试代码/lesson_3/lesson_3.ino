int BASE = 2 ;  //第一个 LED 接的 I/O 口
int NUM = 5;   //LED 的总数
void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   //设定数字I/O口为输出
   }
}

void loop()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, HIGH);    //设定数字I/O口输出为"高"，即逐渐开灯
     delay(200);        //延迟
   }
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, LOW);    //设定数字I/O口输出为"低"，即逐渐关灯
     delay(200);        //延迟
   }  
}
