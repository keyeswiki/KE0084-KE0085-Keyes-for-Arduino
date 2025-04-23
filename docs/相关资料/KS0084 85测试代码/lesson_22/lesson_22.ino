#include <Keypad.h>
const byte ROWS = 4; //定义 4 行
const byte COLS = 4; //定义 4 列
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
//连接 4*4 按键的行位端口，相应控制板的数字 IO 口
byte rowPins[ROWS] = {9,8,7,6};
//连接 4*4 按键的列位端口，相应控制板的数字 IO 口
byte colPins[COLS] = {5,4,3,2};
//调用 Keypad 类库功能函数
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey();
if (key != NO_KEY){
Serial.println(key);
}
}
