#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int redpin = 11; //select the pin for the red LED
int greenpin =10;// select the pin for the green LED
int bluepin =9; // select the pin for the blue LED
int Z =8;
int val;
int value1;
int value2;
int value3;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
pinMode(Z, INPUT);
  lcd.init();  // initialize the lcd 
  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("R;");
  lcd.setCursor(8,0);
  lcd.print("G;");
  lcd.setCursor(0,1);
  lcd.print("B;");
}

void loop() 
{
val=digitalRead(Z);
if(val==HIGH)
{
analogWrite(redpin, 255);
  lcd.setCursor(2,0);
  lcd.print("255");
analogWrite(greenpin, 255);
  lcd.setCursor(10,0);
  lcd.print("255");
analogWrite(bluepin, 255);
  lcd.setCursor(2,1);
  lcd.print("255");
}
else
{
value1=map( analogRead(0),0,1023,0,255);
value2=map( analogRead(1),0,1023,0,255);
value3=map( analogRead(2),0,1023,0,255);
analogWrite(redpin, value1);
if(value1<10)
{
  lcd.setCursor(2,0);
  lcd.print(value1);
  lcd.setCursor(3,0);
  lcd.print("   ");
}
if((value1>=10)&&(value1<100))
{
  lcd.setCursor(2,0);
  lcd.print(value1);
  lcd.setCursor(4,0);
  lcd.print("  ");
}
if(value1>=100)
{
  lcd.setCursor(2,0);
  lcd.print(value1);
}
delay(100); 
analogWrite(greenpin, value2);
if(value2<10)
{
  lcd.setCursor(10,0);
  lcd.print(value2);
  lcd.setCursor(11,0);
  lcd.print("   ");
}
if((value2>=10)&&(value2<100))
{
  lcd.setCursor(10,0);
  lcd.print(value2);
  lcd.setCursor(12,0);
  lcd.print("  ");
}
if(value2>=100)
{
  lcd.setCursor(10,0);
  lcd.print(value2);
}
delay(100); 
analogWrite(bluepin, value3);
if(value3<10)
{
  lcd.setCursor(2,1);
  lcd.print(value3);
  lcd.setCursor(3,1);
  lcd.print("   ");
}
if((value3>=10)&&(value3<100))
{
  lcd.setCursor(2,1);
  lcd.print(value3);
  lcd.setCursor(4,1);
  lcd.print("  ");
}
if(value3>=100)
{
  lcd.setCursor(2,1);
  lcd.print(value3);
}
delay(100); 
}
}
