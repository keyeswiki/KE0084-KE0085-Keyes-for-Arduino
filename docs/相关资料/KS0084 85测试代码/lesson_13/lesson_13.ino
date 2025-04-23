#include <IRremote.h>
int RECV_PIN = 11; //定义数字口11
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
Serial.begin(9600);//设置波特率
irrecv.enableIRIn(); // 使能红外接收
}
void loop() {
if (irrecv.decode(&results)) 
{
Serial.println(results.value, HEX);//显示数据
irrecv.resume(); // 接收下个数据
}
}
