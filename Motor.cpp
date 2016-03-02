//Arduino Motor Library - Version 0.1

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Motor.h>

Motor::Motor(unsigned char IN1,unsigned char IN2,unsigned char ENA) 
{
	In1=IN1;
	In2=IN2;
	Ena=ENA;
	pinMode(In1,OUTPUT);
	pinMode(In2,OUTPUT);
	pinMode(Ena,OUTPUT);
	brakeSign=0;   //默认无刹车
  direction=0;   //默认正向     
}

/*改变刹车设置*/
void Motor::Brake(bool Brake)
{
	brakeSign=Brake;
}

/*设置电机方向*/
void Motor::SetDirection(bool Direction)
{
  direction=Direction;
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
void Motor::Speed(int SpeedIn)
{
  speed=constrain(SpeedIn,-255,255);
  if(direction!=0){
    speed=-speed;
  }
  if(speed>0){
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    analogWrite(Ena,speed);
  }
  else 
  	if(speed<0){
      digitalWrite(In1,LOW);
      digitalWrite(In2,HIGH);
      analogWrite(Ena,-speed);
      }
      else {
        if(brakeSign!=0){
           digitalWrite(In1,LOW);
           digitalWrite(In2,LOW);
         }
         else {
           digitalWrite(In1,HIGH);
           digitalWrite(In2,HIGH);
         }
      }  
}

bool Motor::GetBrake(void)
{
	return brakeSign;
}

int Motor::GetSpeed(void)
{
	return speed;
}

bool Motor::GetDirection(void)
{
  return direction;
}