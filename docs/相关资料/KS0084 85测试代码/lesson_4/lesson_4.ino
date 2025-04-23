int ledPin = 11;  //定义数字口11
int inputPin = 3; //定义数字口3
void setup() 
{
pinMode(ledPin, OUTPUT);   //将ledPin设置为输出 
pinMode(inputPin, INPUT); //将inputPin设置为输入 
}
void loop()
{
int val = digitalRead(inputPin);
//设置数字变量val，读取到数字口3的数值，并赋值给 val 
if (val == LOW) //当val为低电平时，LED变暗
{ 
digitalWrite(ledPin, LOW); // LED变暗
}
 else 
{
digitalWrite(ledPin, HIGH); // LED亮起
}
}
