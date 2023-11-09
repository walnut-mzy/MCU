#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__
#include <intrins.h>
#include <REGX52.H>

sbit OneWire_DQ=P3^7;
void Delay500us()		//@11.0592MHz 
{
	//500us
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
	//500us
}
void Delay70us()		//@11.0592MHz
{
	unsigned char i;
//70us
	_nop_();
	i = 29;
	while (--i);
	//70us
}
void Delay14us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 3;
	while (--i);
}
void Delay55us()		//@11.0592MHz
{
	unsigned char i;
	//55us
	_nop_();
	i = 22;
	while (--i);
	//55us
}
void Delay5us()		//@11.0592MHz
{
}
void Delay50us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 20;
	while (--i);
}

char OneWire_Init(){
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ=1;
	OneWire_DQ=0;
	//500us
	_nop_();
	i = 227;
	while (--i);
	//500us
	
	OneWire_DQ=1;
	
	//70us
	_nop_();
	i = 29;
	while (--i);
	
	//70us
	AckBit=OneWire_DQ;
	
	//500us
	_nop_();
	i = 227;
	while (--i);
	//500us
	return AckBit;
}

void OneWire_SendBit(char Bit){
	char i;
	OneWire_DQ=0;
	

	//14us
	_nop_();
	i = 3;
	while (--i);
	//14us
	OneWire_DQ=Bit;
	//55us
	_nop_();
	i = 22;
	while (--i);
	//55us
	OneWire_DQ=1;
}

char OneWire_ReceiveBit(){
	char Bit;
	OneWire_DQ=0;
	Delay5us();
	OneWire_DQ=1;
	Delay5us();
	Bit=OneWire_DQ;
	Delay50us();
	return Bit;
}

void OneWire_SendByte(char Byte){
	int i;
	for(i=0;i<8;i++){
	OneWire_SendBit(Byte&(0x01<<i));
	}
}

char OneWire_ReceiveByte(){
	int i;
	char Byte=0x00;
	for(i=0;i<8;i++){
	if(OneWire_ReceiveBit()){Byte|=(0x01<<i);}
	}
	return Byte;
}
#endif