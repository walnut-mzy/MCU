#include <REGX52.H>
#include "LCD1602.h"
#include <stdio.h>
int i=0;
int keyvalue[16]={0};
int num;
char  catStr(char* str1, char* str2)
{
    while (*str1 != '\0')//指针后移
    {
        str1++;
    }
    while (*str2 != '\0')
    {
        *str1++ = *str2++;//此处先为*str1赋值，然后在指针后移，所以后面其实*str2='\0'时，str1已经又自增一次了，只是没将'\0'赋给*str1，所以可以直接使用*str1='\0'结尾补上
    }
    *str1 = '\0';
    return 0;
}
void Delay20ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 39;
	j = 230;
	do
	{
		while (--j);
	} while (--i);
}
int matrixkey_onekey(){
		/*
	fuction:检测矩阵键盘使用的是哪个键,这个只检测一个键
	*/
	P1=0xFF;
	P1_0=0;
	if(P1_4==0){Delay20ms();while(P1_4==0);Delay20ms();return 16;}
	if(P1_5==0){Delay20ms();while(P1_5==0);Delay20ms();return 12;}
	if(P1_6==0){Delay20ms();while(P1_6==0);Delay20ms();return 8;}
	if(P1_7==0){Delay20ms();while(P1_7==0);Delay20ms();return 4;}
	
	 P1_1=0;
	if(P1_4==0){Delay20ms();while(P1_4==0);Delay20ms();return 15;}
	if(P1_5==0){Delay20ms();while(P1_5==0);Delay20ms();return 11;}
	if(P1_6==0){Delay20ms();while(P1_6==0);Delay20ms();return 7;}
	if(P1_7==0){Delay20ms();while(P1_7==0);Delay20ms();return 3;}
	
	P1_2=0;
	if(P1_4==0){Delay20ms();while(P1_4==0);Delay20ms();return 14;}
	if(P1_5==0){Delay20ms();while(P1_5==0);Delay20ms();return 10;}
	if(P1_6==0){Delay20ms();while(P1_6==0);Delay20ms();return 6;}
	if(P1_7==0){Delay20ms();while(P1_7==0);Delay20ms();return 2;}
	
	P1_3=0;
	if(P1_4==0){Delay20ms();while(P1_4==0);Delay20ms();return 13;}
	if(P1_5==0){Delay20ms();while(P1_5==0);Delay20ms();return 9;}
	if(P1_6==0){Delay20ms();while(P1_6==0);Delay20ms();return 5;}
	if(P1_7==0){Delay20ms();while(P1_7==0);Delay20ms();return 1;}

}

void matrix_key_get(int *key){
	P1_0=0;
	
	if(P1_4==0){key[15]=1;LCD_ShowNum(1,1,keyvalue[15],1);}
	if(P1_5==0){key[12]=1;}
	if(P1_6==0){key[8]=1;}
	if(P1_7==0){key[4]=1;}
	
	P1_1=0;
	if(P1_4==0){key[15]=1;}
	if(P1_5==0){key[11]=1;}
	if(P1_6==0){key[7]=1;}
	if(P1_7==0){key[3]=1;}
	P1_2=0;
	if(P1_4==0){key[13]=1;}
	if(P1_5==0){key[9]=1;}
	if(P1_6==0){key[5]=1;}
	if(P1_7==0){key[1]=1;}
	P1_3=0;
	if(P1_4==0){key[12]=1;}
	if(P1_5==0){key[8]=1;}
	if(P1_6==0){key[4]=1;}
	if(P1_7==0){key[0]=1;}
}
void matrix_multiplekey(int *key){
		/*
	fuction:检测矩阵键盘使用的是哪个键(可以多个键)
	*/
	

	P1=0xFF;
	P1_0=0;
	if(P1_4==0){Delay20ms();while(P1_4==0){matrix_key_get(key);}Delay20ms();}
	if(P1_5==0){Delay20ms();while(P1_5==0){matrix_key_get(key);}Delay20ms();}
	if(P1_6==0){Delay20ms();while(P1_6==0){matrix_key_get(key);}Delay20ms();}
	if(P1_7==0){Delay20ms();while(P1_7==0){matrix_key_get(key);}Delay20ms();}
	P1_1=0;
	if(P1_4==0){Delay20ms();while(P1_4==0){matrix_key_get(key);}Delay20ms();}
	if(P1_5==0){Delay20ms();while(P1_5==0){matrix_key_get(key);}Delay20ms();}
	if(P1_6==0){Delay20ms();while(P1_6==0){matrix_key_get(key);}Delay20ms();}
	if(P1_7==0){Delay20ms();while(P1_7==0){matrix_key_get(key);}Delay20ms();}
	P1_2=0;
	if(P1_4==0){Delay20ms();while(P1_4==0){matrix_key_get(key);}Delay20ms();}
	if(P1_5==0){Delay20ms();while(P1_5==0){matrix_key_get(key);}Delay20ms();}
	if(P1_6==0){Delay20ms();while(P1_6==0){matrix_key_get(key);}Delay20ms();}
	if(P1_7==0){Delay20ms();while(P1_7==0){matrix_key_get(key);}Delay20ms();}
	P1_3=0;
	if(P1_4==0){Delay20ms();while(P1_4==0){matrix_key_get(key);}Delay20ms();}
	if(P1_5==0){Delay20ms();while(P1_5==0){matrix_key_get(key);}Delay20ms();}
	if(P1_6==0){Delay20ms();while(P1_6==0){matrix_key_get(key);}Delay20ms();}
	if(P1_7==0){Delay20ms();while(P1_7==0){matrix_key_get(key);}Delay20ms();}
}

void main(){
	
	LCD_Init();
	while(1){

	}
}