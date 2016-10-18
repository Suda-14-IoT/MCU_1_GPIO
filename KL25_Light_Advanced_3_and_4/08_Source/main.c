//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//======================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量
	uint_32 mRuncount;		//主循环计数器

	//2. 关总中断
	DISABLE_INTERRUPTS;

	//3. 初始化外设模块
	light_init(LIGHT_BLUE, LIGHT_OFF);		//蓝灯初始化
	light_init(LIGHT_RED, LIGHT_OFF);		//红灯初始化
	key_init(KEY_0);	//开关0初始化，KEY_0在key.h中定义，为PTD|0

	//4. 给有关变量赋初值

	//5. 使能模块中断

	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for (;;)
	{
		if (mRuncount++ >= RUN_COUNTER_MAX)	//主循环次数计数器大于设定的宏常数
		{
			mRuncount = 0;
			light_change(LIGHT_RED);	//切换红灯亮暗
		}

		//不断地获取开关状态
		if (key_get(KEY_0) == KEY_ON)	//当开关开启时
		{
			//点亮蓝灯
			light_control(LIGHT_BLUE, LIGHT_ON);
		}
		else	//当开关关闭时
		{
			//关闭蓝灯
			light_control(LIGHT_BLUE, LIGHT_OFF);
		}
		//以下加入用户程序--------------------------------------------------------
	}	//主循环end_for
		//主循环结束==================================================================
}

