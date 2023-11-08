#ifndef __FUCTION_H__
#define __FUCTION_H__

#include <REGX52.H>
#include <intrins.h>
#include "constant.h"
#include "LCD1602.h"
void Timer0_Init(){
	/*
	FUCTION:配置TIMER0寄存器
	生成配置：
	void Timer0Init(void)		//1微秒@11.0592MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
	*/
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}
void Timer0_begin(){
	TR0=1;
}
void Timer0_end(){
	TR0=0;
}
void Timer0_Routine() interrupt 1
{
	TH0=64536/256;
	TL0=64536%256;
	T0count++;
	if(T0count>=100){
		time--;
		T0count=0;
	}
	
  LCD_ShowString(1,1,"time:");
	LCD_ShowNum(1,6,time,3);
	if(time<=0){
		LCD_Init();
	  LCD_ShowString(1,1,"end");
		Timer0_end();
	}
}
void Delay20ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 1;
	j = 216;
	k = 35;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

#endif