int ledpin=11;//定义数字接口11（PWM 输出）
void setup()
{
pinMode(ledpin,OUTPUT);//定义数字接口11 为输出
Serial.begin(9600);//设置波特率为9600
}
void loop()
{
int val=analogRead(0);//读取模拟口A0口的值
Serial.println(val);//显示val 变量
val = map(val, 0, 1023, 0, 255);//从0-1023映射到0-255
analogWrite(ledpin,val);// 打开LED 并设置亮度
delay(10);//延时0.01 秒
}
