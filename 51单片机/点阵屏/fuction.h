#include <intrins.h> 

sbit RCK=P3^5; //RCLK
sbit SCK=P3^6; //SRCLK
sbit SER=P3^4;  //SER

#define MARRIX_lED_PORT P0

void MatrixLED_Init(){
	SCK=0;
	RCK=0;

}
void 74HC595_writebyte(unsigned char byte){
	unsigned char i;
	for(i=0;i<8;i++){
	SER=byte&(0x80>>i);
	SCK=1;
	SCK=0;
	}
	RCK=1;
	RCK=0;

}
void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void MatrixLED_ShowColumn(char column,char byte){
	74HC595_writebyte(byte);
	MARRIX_lED_PORT=~(0x80>>column);
	Delay(1);
	P0=0xFF;

}