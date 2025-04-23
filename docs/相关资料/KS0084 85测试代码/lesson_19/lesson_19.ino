#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
lcd.setCursor(0,0);
  lcd.print("The distance is:");
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 lcd.setCursor(0,1);
 lcd.print("-1     ");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 if(distance<10)
{
 lcd.setCursor(0,1);
 lcd.print(distance);
 lcd.setCursor(1,1);
 lcd.print("  ");
}
if((distance >=10)&&(distance<100))
{
 lcd.setCursor(0,1);
 lcd.print(distance);
 lcd.setCursor(2,1);
 lcd.print("  ");
}
 if(distance>100)
{
 lcd.setCursor(0,1);
 lcd.print(distance);
}
 digitalWrite(LEDPin, LOW); 
 }
 
 //Delay 50ms before next reading.
 delay(50);
}
