#ifndef _MOTOR_H_
#define _MOTOR_H_
// LIBRARY_VERSION	0.1

class Motor
{
	public:
		Motor(unsigned char,unsigned char,unsigned char);	//设置电机驱动板的接口IN1,IN2,ENA
		void brake(bool);									//设置有无刹车，1表示有，0表示无
		void speed(int);									//设置速度，-255~255，正数正转，负数反转
		bool GetBrake(void);								//获取刹车的设置，1表示有，0表示无
		int  GetSpeed(void);								//获取设置的速度
	private:
		unsigned char In1;
		unsigned char In2;
		unsigned char Ena;
		int Speed;
		bool BrakeSign;

};
#endif