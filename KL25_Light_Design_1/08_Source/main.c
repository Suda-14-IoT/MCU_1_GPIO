//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//======================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量
	uint_32 mRuncount;		//主循环计数器
	uint_8 flag;			//灯控制标志
	//2. 关总中断
	DISABLE_INTERRUPTS;

	//3. 初始化外设模块
	light_init(LIGHT_RED, LIGHT_OFF);      //红灯初始化
	light_init(LIGHT_BLUE, LIGHT_OFF);     //蓝灯初始化
	light_init(LIGHT_GREEN, LIGHT_OFF);    //绿灯初始化

	//4. 给有关变量赋初值
	mRuncount = 0;            //主循环计数器
	flag = 0;
	//5. 使能模块中断

	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for (;;)
	{
		//运行指示灯（RUN_LIGHT）闪烁---------------------------------------------
		mRuncount++;					   //主循环次数计数器+1
		if (mRuncount >= RUN_COUNTER_MAX)  //主循环次数计数器大于设定的宏常数
		{
			mRuncount = 0;
			switch (flag)
			{
			case 0: //红灯
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 1: //蓝灯
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 2: //绿灯
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 3: //紫灯
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 4: //黄灯
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 5: //青灯
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 6: //白灯
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			}
			if (++flag >= 7)
			{
				flag = 0;
			}
		}
		//以下加入用户程序--------------------------------------------------------
	} //主循环end_for
	  //主循环结束==================================================================
}

