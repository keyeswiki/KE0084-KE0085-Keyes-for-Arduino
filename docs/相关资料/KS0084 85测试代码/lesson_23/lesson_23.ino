#include <Stepper.h>
//这里设置步进电机旋转一圈是多少步
#define STEPS 100
//设置步进电机的步数和引脚
Stepper stepper(STEPS, 11, 10, 9, 8);
//定义变量用来存储历史读数
int previous = 0;
void setup()
{
 //设置电机每分钟的转速为90步
  stepper.setSpeed(90);
}
void loop()
{
 //获取传感器读数
 int val = analogRead(0);
 //移动步数为当前读数减去历史读数
 stepper.step(val - previous);
 //保存历史读数
 previous = val;
}
