#include <stdio.h>
#include <string.h>
#include <DS1302.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
/* Set the appropriate digital I/O pin connections */
uint8_t CE_PIN   = 10;    // RST
uint8_t IO_PIN   = 9;   // DAT 
uint8_t SCLK_PIN = 8;  // CLK 
/* Create buffers */
char buf[50];
char bf[50];
char bu[50];
char uf[50];
char day[10];
/* Create a DS1302 object */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);
void print_time()
{
  /* Get the current time and date from the chip */
  Time t = rtc.time();

  /* Name the day of the week */
  memset(day, 0, sizeof(day));  /* clear day buffer */
  switch (t.day) {
    case 1:
      strcpy(day, "Sunday   ");
      break;
    case 2:
      strcpy(day, "Monday   ");
      break;
    case 3:
      strcpy(day, "Tuesday  ");
      break;
    case 4:
      strcpy(day, "Wednesday");
      break;
    case 5:
      strcpy(day, "Thursday ");
      break;
    case 6:
      strcpy(day, "Friday   ");
      break;
    case 7:
      strcpy(day, "Saturday ");
      break;
  }

  /* Format the time and date and insert into the temporary buffer */
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           day,
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);
           Serial.println(buf);
  snprintf(bf, sizeof(bf), "%s  %04d",
          day, t.yr);
  lcd.setCursor(0,0);
  lcd.print(bf);
  snprintf(bu, sizeof(bu),"%02d:%02d:%02d",
           t.hr, t.min, t.sec);
  /* Print the formatted string to serial so we can see the time */
  lcd.setCursor(0,1);
  lcd.print(bu);
  snprintf(uf, sizeof(uf), "%02d-%02d",
         t.mon, t.date);
  lcd.setCursor(11,1);
  lcd.print(uf);
}
void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  /* Initialize a new chip by turning off write protection and clearing the
     clock halt flag. These methods needn't always be called. See the DS1302
     datasheet for details. */
  rtc.write_protect(false);
  rtc.halt(false);

  /* Make a new time object to set the date and time */
  /*   Tuesday, May 19, 2009 at 21:16:37.            */
  Time t(2017,10,24,10,11,22,3);

  /* Set the time and date on the chip */
  rtc.time(t);
}


/* Loop and print the time every second */
void loop()
{
  print_time();
  delay(1000);
}
