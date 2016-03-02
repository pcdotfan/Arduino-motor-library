#include <Motor.h>
Motor MyMotor(14,15,9);		//设置直流电机驱动板的接口
void setup() {
  MyMotor.setBrake(1);			//设置有刹车
}

void loop() {
  MyMotor.setSpeed(20);		//速度值为20
  delay(1000);
  MyMotor.setSpeed(0);
  delay(300);
  MyMotor.setSpeed(-20);
  delay(1000);
  MyMotor.setSpeed(0);
  delay(300);  
}
