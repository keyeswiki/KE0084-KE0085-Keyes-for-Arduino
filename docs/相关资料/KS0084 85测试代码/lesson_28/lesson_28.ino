#include <dht11.h>
// include the library code:
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
dht11 DHT;
#define DHT11_PIN 10   
void setup(){
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Humidity (%):");
  lcd.setCursor(0,1);
  lcd.print("Temp (C):");
}  
void loop(){
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk){
    case DHTLIB_OK:  
                break;
case DHTLIB_ERROR_CHECKSUM: 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                break;
    default: 
                break;
  }
 // DISPLAT DATA
  lcd.setCursor(13,0);
  lcd.print(DHT.humidity);
  lcd.setCursor(9,1);
  lcd.print(DHT.temperature);
  delay(1000);
}
