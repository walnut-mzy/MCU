#include <REGX52.H>
#include <INTRINS.H>

int num_led_choice[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
char digit[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int num_led_left_right[2][4]={{0,1,2,3},{4,5,6,7}};
void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void show_num(int index,int num){
	/*
	this fuction was used to show num;
	index: it denote that choicing which led is used;
	num :the parameter denote the number that you want;
	*/
	P2_2=num_led_choice[index][2];
	P2_3=num_led_choice[index][1];
	P2_4=num_led_choice[index][0];
	P0=digit[num];
	Delay1ms();
	P0=0x00;

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




void main(){
	
	/*set  init value*/
	
	int left_num=0;
	int right_num=0;
	int end_data=0;
	int i;
	int i1;
	int i2;
	int left_index;
	int right_index;
	int end_data_index;
	int cal=0;      // cal denote plus when cal is equaled to zero else cal denote subtract;
	int flag_show_result=0;
	
	while(1){
		left_index=left_num;
		right_index=right_num;
		end_data_index=end_data;
		i=0;
		i1=4;
		i2=0;
		/*the model of show number*/
		if(flag_show_result==0){
		while(1){
			show_num(i,left_index%10);
			left_index=left_index/10;
			i=i+1;
			if(left_index==0){
				break;
			}
		}
		while(1){
			show_num(i1,right_index%10);
			right_index=right_index/10;
			i1=i1+1;
			if(right_index==0){
				break;
			}
		}}
		else{
			while(1){
			show_num(i2,end_data_index%10);
			end_data_index=end_data_index/10;
			i2=i2+1;
			if(end_data_index==0){
				break;
			}
		}
		
		}
		// P3_0 control the left numbers; p3_1 control the right numbers;
		if(P3_0==0){
			Delay20ms();
			while(P3_0==0);
			Delay20ms();
			left_num+=1;
		}
		if(P3_1==0){
			Delay20ms();
			while(P3_1==0);
			Delay20ms();
			right_num+=1;
		}
		// P2_0 denote plus, P2_1 denote subtract
		if(P3_2==0){
			Delay20ms();
			while(P3_2==0);
			Delay20ms();
			cal=~cal;
		}
		if(P3_3==0){
			Delay20ms();
			while(P3_2==0);
			Delay20ms();
			flag_show_result=~flag_show_result;
			if(!cal){
				end_data=left_num+right_num;
			}
			else{
				end_data=left_num-right_num;
			}
		}
	};
}