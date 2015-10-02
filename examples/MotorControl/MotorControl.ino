#include <Motor.h>
Motor MyMotor(14,15,9);		//设置直流电机驱动板的接口
void setup() {
  MyMotor.brake(1);			//设置有刹车
}

void loop() {
  MyMotor.speed(20);		//速度值为20
  delay(1000);
  MyMotor.speed(0);
  delay(300);
  MyMotor.speed(-20);
  delay(1000);
  MyMotor.speed(0);
  delay(300);  
}
