#include <Servo.h>
Servo myservo;//定义舵机变量名
void setup()
{
myservo.attach(9);//定义舵机接口（9、10 都可以，缺点只能控制2 个）
}
void loop()
{
myservo.write(90);//设置舵机旋转的角度
}
