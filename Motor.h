#ifndef _MOTOR_H_
#define _MOTOR_H_
// LIBRARY_VERSION	0.1

class Motor
{
	public:
		Motor(unsigned char,unsigned char,unsigned char);	//设置电机驱动板的接口IN1,IN2,ENA
		void setBrake(bool);									//设置有无刹车，1表示有，0表示无
		void setDirection(bool);							//设置电机方向，0表示正向，1表示反向
		void setSpeed(int);									//设置速度，-255~255，正数正转，负数反转
		bool getBrake(void);								//获取刹车的设置，1表示有，0表示无
		bool getDirection(void);							//获取电机方向，0表示正向，1表示反向
		int  getSpeed(void);								//获取设置的速度
	private:
		unsigned char _IN1;
		unsigned char _IN2;
		unsigned char _ENA;
		int _speed;
		bool _direction;
		bool _brakeSign;

};
#endif