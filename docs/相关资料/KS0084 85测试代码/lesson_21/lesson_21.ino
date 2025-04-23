// include the library code:
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte sensorPin = 6;//定义数字口6
byte indicator = 10;//定义数字口10
void setup()
{
  pinMode(sensorPin,INPUT);//设置数字口6位输入
  pinMode(indicator,OUTPUT);//设置数字口10为输出
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
}
void loop()
{
  byte state = digitalRead(sensorPin);//读取到数字口6的数值赋值给state
  digitalWrite(indicator,state);//控制数字口10的状态
  if(state == 1)//当数值口6位高电平时，串口监视器输出对应字符，并自动换行
 {
  lcd.setCursor(0,0);
  lcd.print("Somebody is");
  lcd.setCursor(0,1);
  lcd.print("in this area!");
  }
  else if(state == 0) //当数值口6位低电平时，串口监视器输出对应字符，并自动换行
  {
  lcd.setCursor(0,0);
  lcd.print("No one!      ");
  lcd.setCursor(0,1);
  lcd.print("No one!      ");
  }
  delay(500);//延迟0.5S
}
