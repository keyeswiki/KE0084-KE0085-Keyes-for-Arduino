int LedPinA = 5; //定义数字口5
int LedPinB = 6; //定义数字口6
int ButtonPinA = 7;//定义数字口7
int ButtonPinB = 4;//定义数字口4
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);//设置波特率
pinMode(LedPinA, OUTPUT);//数字口5设置为输出
pinMode(LedPinB, OUTPUT);//数字口6设置为输出
pinMode(ButtonPinA, INPUT);//数字口7设置为输入
pinMode(ButtonPinB, INPUT);//数字口4设置为输入
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);//读取数字口7的数值赋值给buttonStateA
if (buttonStateA == HIGH && brightnessA != 255)
//当buttonStateA为高电平且brightnessA不为255
{
brightnessA ++;//brightnessA加1
delay(10);//延迟0.01S
}
if (buttonStateA == LOW && brightnessA != 0)
//当buttonStateA为低电平且brightnessA不为0
{
brightnessA --;//brightnessA减1
delay(10);//延迟0.01S
}
analogWrite(LedPinB, brightnessA);//将brightnessA赋值为给PWM口6
Serial.print(brightnessA);//显示brightnessA数值
Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);//读取数字口4的数值赋值给buttonStateB
if (buttonStateB == HIGH && brightnessB != 0)
//当buttonStateB为高电平且brightnessA不为0
{
brightnessB --;//brightnessB减1
delay(10);//延迟0.01S
}
if (buttonStateB == LOW && brightnessB != 255)
//当buttonStateB为低电平且brightnessA不为255
{
brightnessB++;//brightnessB加1
delay(10);//延迟0.01S
}
analogWrite(LedPinA, brightnessB); //将brightnessB赋值为给PWM口5
Serial.println(brightnessB);//显示brightnessB数值，并自动换行
delay(5);
}
