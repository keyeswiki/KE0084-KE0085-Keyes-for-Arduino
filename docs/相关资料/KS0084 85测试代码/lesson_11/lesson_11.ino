void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop() {
 int vol = analogRead(A0) * (5.0 / 1023.0*100);  
 Serial.print("Tep:");
 Serial.print(vol);
 Serial.println("C");
if (vol<28)                   
{
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
else if (vol>=28 && vol<=30)                            
 {
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}
else if (vol>30)                              
{
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
}
 }
