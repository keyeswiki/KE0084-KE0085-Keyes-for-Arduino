#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int led=9;
void setup()
{
  pinMode(led,OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ultra-Violet ");
  lcd.setCursor(0,1);
  lcd.print("Detection:");
}
void loop()
{ 
 int sensorValue = analogRead(A0);
  if(sensorValue<10)
  {
  lcd.setCursor(10,1);
  lcd.print(sensorValue);
  lcd.setCursor(11,1);
  lcd.print("     ");
  digitalWrite(led,LOW);
  }
  if((sensorValue>=10)&&(sensorValue<100))
  {
  lcd.setCursor(10,1);
  lcd.print(sensorValue);
  lcd.setCursor(12,1);
  lcd.print("    ");
  digitalWrite(led,HIGH);
  }
  if( sensorValue>=100)
  {
  lcd.setCursor(10,1);
  lcd.print(sensorValue);
  lcd.setCursor(13,1);
  lcd.print("   ");
  digitalWrite(led,HIGH);
  }
  delay(500);
}
