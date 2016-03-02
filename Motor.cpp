//Arduino Motor Library - Version 0.1

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Motor.h>

Motor::Motor(unsigned char IN1,unsigned char IN2,unsigned char ENA) 
{
	_IN1=IN1;
	_IN2=IN2;
	_ENA=ENA;
	pinMode(_IN1,OUTPUT);
	pinMode(_IN2,OUTPUT);
	pinMode(_ENA,OUTPUT);
	_brakeSign=0;   //默认无刹车
  	_direction=0;   //默认正向     
}

/*改变刹车设置*/
void Motor::setBrake(bool brake)
{
	_brakeSign=brake;
}

/*设置电机方向*/
void Motor::setDirection(bool direction)
{
    _direction=direction;
}

/*
------------------------------
IN1 IN2 ENA   OUT1、OUT2 输出        
0   0   ×     刹车      
1   1   ×     悬空 
1   0   1     全速正转  
0   1   1     全速反转  
1   0   PWM   正转调速    
0   1   PWM   反转调速    
------------------------------
*/
void Motor::setSpeed(int speedIn)
{
    _speed=constrain(speedIn,-255,255);
    if(_direction!=0){
        _speed=-_speed;
    }
    if(_speed>0){
        digitalWrite(_IN1,HIGH);
        digitalWrite(_IN2,LOW);
        analogWrite(_ENA,_speed);
    }
    else 
  	if(_speed<0){
        digitalWrite(_IN1,LOW);
        digitalWrite(_IN2,HIGH);
        analogWrite(_ENA,-_speed);
     }
     else {
        if(_brakeSign!=0){
            digitalWrite(_IN1,LOW);
            digitalWrite(_IN2,LOW);
        }
        else{
            digitalWrite(_IN1,HIGH);
            digitalWrite(_IN2,HIGH);
        }
    }  
}

bool Motor::getBrake(void)
{
    return _brakeSign;
}

int Motor::getSpeed(void)
{
	return _speed;
}

bool Motor::getDirection(void)
{
    return _direction;
}