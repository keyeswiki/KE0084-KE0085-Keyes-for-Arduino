#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int gas_din=12;
int gas_ain=A0;
int led=9;
int ad_value;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(gas_din,INPUT);
  pinMode(gas_ain,INPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}
void loop()
{ 
  ad_value=analogRead(gas_ain);
  if(digitalRead(gas_din)==LOW)
  { 
    digitalWrite(led,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Gas leakage!    ");
    lcd.setCursor(0,1);
    lcd.print("Value:");
     if(ad_value<10)
  {
  lcd.setCursor(6,1);
  lcd.print(ad_value);
  lcd.setCursor(7,1);
  lcd.print("         ");
  }
  if((ad_value>=10)&&(ad_value<100))
  {
  lcd.setCursor(6,1);
  lcd.print(ad_value);
  lcd.setCursor(8,1);
  lcd.print("        ");
  }
  if( ad_value>=100)
  {
  lcd.setCursor(6,1);
  lcd.print(ad_value);
  lcd.setCursor(9,1);
  lcd.print("       ");
  }
  }
  else
  {
   digitalWrite(led,LOW);
   lcd.setCursor(0,0);
   lcd.print("Gas not leak!   ");
   lcd.setCursor(0,1);
   lcd.print("Gas not leak!  ");
  }
  delay(500);
}
