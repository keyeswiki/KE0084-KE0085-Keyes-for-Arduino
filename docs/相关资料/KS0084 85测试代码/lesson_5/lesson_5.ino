int redled=11;     
int greenled=10; 
int blueled=9;  
int redpin=5;    
int greenpin=4; 
int bluepin=3;   
int restpin=2;   
int red;
int green;
int blue;
void setup()
{
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
pinMode( blueled,OUTPUT);
pinMode(redpin,INPUT);
pinMode(greenpin,INPUT);
pinMode(bluepin,INPUT);
}
void loop() 
{
red=digitalRead(redpin);
green=digitalRead(greenpin);
blue=digitalRead(bluepin);
if(red==LOW)RED_YES();    
if(green==LOW)GREEN_YES();
if(blue==LOW)BLUE_YES();
}

void RED_YES() 
{
  while(digitalRead(restpin)==1)
  {
color(255, 0, 0); 
 }
  clear_led();
}
void GREEN_YES()
{
  while(digitalRead(restpin)==1)
  {
color(0, 255, 0); 
  }
  clear_led();
}
void BLUE_YES()
{
  while(digitalRead(restpin)==1)
  {
 color(0, 0, 255); 

  }
  clear_led();
}
void clear_led()
{
 color(0, 0, 0); 
}
void color (unsigned char red, unsigned char green, unsigned char blue)  //颜色控制函数 
{    
  analogWrite(redled, red);   
  analogWrite(greenled,green); 
  analogWrite(blueled, blue); 
} 
