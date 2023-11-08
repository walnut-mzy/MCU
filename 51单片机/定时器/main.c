#include <REGX52.H>
#include "constant.h"
#include "fuction.h"
#include "LCD1602.h"
void main(){
	
	Timer0_Init();
	LCD_Init();
while(1){
	
	/**
  * @brief  在LCD1602指定位置开始显示所给字符串
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串
  * @retval 无
  */
	if(flag_show==0){
		LCD_ShowString(1,1,"timeset:");
		LCD_ShowNum(1,9,time,3);
	}

	/**
  * @brief  在LCD1602指定位置开始显示所给数字
  * @param  Line 起始行位置，范围：1~2
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~65535
  * @param  Length 要显示数字的长度，范围：1~5
  * @retval 无
  */
	
	if(P3_0==0){
		Delay20ms();
		while(P3_0==0);
		Delay20ms();
		time++;
	}
	if(P3_1==0){
		Delay20ms();
		while(P3_1==0);
		Delay20ms();
		time=0;
	}
		if(P3_2==0){
			if(time==0){
				LCD_Init();
				LCD_ShowString(1,1,"The number cannot be zero");
			}
		Delay20ms();
		while(P3_2==0);
		Delay20ms();
		flag_show=1;
		LCD_Init();
		Timer0_begin();
	}
		if(P3_3==0){
		Delay20ms();
		while(P3_2==0);
		Delay20ms();
		flag_show=0;
		time=0;
		LCD_Init();
	}
}
}