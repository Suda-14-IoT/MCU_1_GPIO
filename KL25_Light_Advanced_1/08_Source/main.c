//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//======================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量
	uint_32 mRuncount;		//主循环计数器
	uint_8 cycle;			//周期数标志
	//2. 关总中断
	DISABLE_INTERRUPTS;

	//3. 初始化外设模块
	light_init(LIGHT_RED, LIGHT_OFF);      //红灯初始化
	light_init(LIGHT_GREEN, LIGHT_OFF);    //绿灯初始化

	//4. 给有关变量赋初值
	mRuncount = 0;
	cycle = 0;
	//5. 使能模块中断

	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for (;;)
	{
		mRuncount++;					   //主循环次数计数器+1
		if (mRuncount >= RUN_COUNTER_MAX)  //主循环次数计数器大于设定的宏常数
		{
			mRuncount = 0;
			//这里根据周期数标志对灯进行控制，0-13时为绿灯，14-19时为闪烁绿灯，
			//20-25时为黄灯，26-45时为红灯
			if (cycle >= 0 && cycle <= 13)
			{
				//绿灯
				light_control(LIGHT_GREEN, LIGHT_ON);
				light_control(LIGHT_RED, LIGHT_OFF);
			}
			else if (cycle >= 14 && cycle <= 19)
			{
				if ((cycle & 0x1) == 0)	//周期数为偶数时
				{
					//绿灯
					light_control(LIGHT_GREEN, LIGHT_ON);
					light_control(LIGHT_RED, LIGHT_OFF);
				}
				else	//周期数为奇数时
				{
					//无灯
					light_control(LIGHT_GREEN, LIGHT_OFF);
					light_control(LIGHT_RED, LIGHT_OFF);
				}
			}
			else if (cycle >= 20 && cycle <= 25)
			{
				//黄灯
				light_control(LIGHT_GREEN, LIGHT_ON);
				light_control(LIGHT_RED, LIGHT_ON);
			}
			else
			{
				//红灯
				light_control(LIGHT_GREEN, LIGHT_OFF);
				light_control(LIGHT_RED, LIGHT_ON);
			}
			//周期数加1，若加1后大于等于46，则置0
			if (++cycle >= 46)
			{
				cycle = 0;
			}
		}
		//以下加入用户程序--------------------------------------------------------
	} //主循环end_for
	  //主循环结束==================================================================
}

