#ifndef __FUCTION_H__
#define	__FUCTION_H__
#include <REGX52.H>
#include <intrins.h>
#include "LCD1602.h"
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3	^5;
char Ds1302_time[]={0};
void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 3;
	j = 26;
	k = 223;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void DS1302_Init(){
	DS1302_CE=0;
	DS1302_SCLK=0;
}

void DS1302_WriteByte(unsigned char command,Data){
	int i;
	DS1302_CE=1;
	for(i=0;i<8;i++){
		DS1302_IO=command&(0x01<<i);
		DS1302_SCLK=1; //这个本来需要延时，但是单片机速率太低，不用延时
		
		DS1302_SCLK=0;
	}
	for(i=0;i<8;i++){
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1; //这个本来需要延时，但是单片机速率太低，不用延时

		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}
char DS1302_ReadByte(unsigned char command){
	int i;
	char Data=0x00;
	char Data1;
	DS1302_CE=1;
	for(i=0;i<8;i++){
		DS1302_IO=command&(0x01<<i);
		DS1302_SCLK=0; //这个本来需要延时，但是单片机速率太低，不用延时
		DS1302_SCLK=1;
	}
	DS1302_IO=0;	
	for(i=0;i<8;i++){
		DS1302_SCLK=1; //这个本来需要延时，但是单片机速率太低，不用延时
		DS1302_SCLK=0;
		Data1 = DS1302_IO;
		Data = (Data>>1) | (Data1<<7);
	}
	DS1302_CE=0;
	
	return Data;
}

void DS1302_unprotect(){
	DS1302_WriteByte(0x8E,0x00);
}
#endif