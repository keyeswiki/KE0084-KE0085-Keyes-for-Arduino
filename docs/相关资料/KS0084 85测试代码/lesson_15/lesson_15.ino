int latchPin = 4;
int clockPin = 5;
int dataPin = 2; //这里定义了那三个脚
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //让三个脚都是输出状态
}
void loop()
{

  int a[10]={
    246,254,224,190,182,102,242,218,96,252};   //定义功能数组，数组依次为数码管得定义
  for(int x=9; x>-1 ;x-- )                        //倒数功能循环
  {
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,a[x]);     //显示数组a[x]
    digitalWrite(latchPin,HIGH);
    delay(1000);
  }
}
