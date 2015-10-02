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
	BrakeSign=0;                   //默认无刹车
}

void Motor::brake(bool Brake)
{
	BrakeSign=Brake;
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
void Motor::speed(int SpeedIn)
{
  Speed=constrain(SpeedIn,-255,255);
  if(Speed>0){
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    analogWrite(Ena,Speed);
  }
  else 
  	if(Speed<0){
      digitalWrite(In1,LOW);
      digitalWrite(In2,HIGH);
      analogWrite(Ena,-Speed);
      }
      else {
        if(BrakeSign!=0){
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
	return BrakeSign;
}

int Motor::GetSpeed(void)
{
	return Speed;
}