int ledPin = 3; // 定义数字口3
void setup()
{
pinMode(ledPin, OUTPUT);// 将ledPin设置为输出
}
void loop()
{
for (int a=0; a<=255;a++)// 设置使LED逐渐变亮
{
analogWrite(ledPin,a); // 开启led,调节亮度，范围是0-255，在255时led最亮
delay(10); // 延迟0.01S
}
for (int a=255; a>=0;a--) // 设置使LED逐渐变暗
{
analogWrite(ledPin,a); // 开启led,调节亮度，范围是0-255，在255时led最亮
delay(10); // 延迟0.01S
}
delay(1000);// 延迟1S
}
