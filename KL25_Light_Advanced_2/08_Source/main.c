//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//======================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量
	uint_8 flag;		//开关状态组成的标志
	uint_16 lights[8];	//下标与相应灯的映射数组，如0代表LIGHT_0
	//2. 关总中断
	DISABLE_INTERRUPTS;

	//3. 初始化外设模块
	//LIGHT与KEY的引脚宏定义均在相应的.h文件中
	//初始化各灯（更改过light.h中LIGHT_ON与LIGHT_OFF所对应的逻辑）
	light_init(LIGHT_0, LIGHT_OFF);
	light_init(LIGHT_1, LIGHT_OFF);
	light_init(LIGHT_2, LIGHT_OFF);
	light_init(LIGHT_3, LIGHT_OFF);
	light_init(LIGHT_4, LIGHT_OFF);
	light_init(LIGHT_5, LIGHT_OFF);
	light_init(LIGHT_6, LIGHT_OFF);
	light_init(LIGHT_7, LIGHT_OFF);
	//初始化各开关，KEY_0-KEY-2所组成的3位二进制数用来指示哪盏灯亮
	//KEY_3状态为KEY_ON时表示逻辑反转，即仅有指示的那盏灯灭
	key_init(KEY_0);
	key_init(KEY_1);
	key_init(KEY_2);
	key_init(KEY_3);

	//4. 给有关变量赋初值
	//建立下标与相应灯的映射
	lights[0] = LIGHT_0;
	lights[1] = LIGHT_1;
	lights[2] = LIGHT_2;
	lights[3] = LIGHT_3;
	lights[4] = LIGHT_4;
	lights[5] = LIGHT_5;
	lights[6] = LIGHT_6;
	lights[7] = LIGHT_7;

	//5. 使能模块中断

	//6. 开总中断
	ENABLE_INTERRUPTS;

	//进入主循环
	//主循环开始==================================================================
	for (;;)
	{
		//flag置0
		flag = 0;
		//获取3个开关的状态量，并赋给flag
		flag |= (key_get(KEY_0) << 0);
		flag |= (key_get(KEY_1) << 1);
		flag |= (key_get(KEY_2) << 2);

		//获取KEY_3开关状态
		if (key_get(KEY_3) == KEY_OFF)	//当开关关闭时，为正逻辑
		{
			//关闭所有灯
			light_control(LIGHT_0, LIGHT_OFF);
			light_control(LIGHT_1, LIGHT_OFF);
			light_control(LIGHT_2, LIGHT_OFF);
			light_control(LIGHT_3, LIGHT_OFF);
			light_control(LIGHT_4, LIGHT_OFF);
			light_control(LIGHT_5, LIGHT_OFF);
			light_control(LIGHT_6, LIGHT_OFF);
			light_control(LIGHT_7, LIGHT_OFF);
			//flag所指示的那盏灯被点亮
			light_control(lights[flag & 0x7], LIGHT_ON);
		}
		else	//当开关开启时，为负逻辑
		{
			//点亮所有灯
			light_control(LIGHT_0, LIGHT_ON);
			light_control(LIGHT_1, LIGHT_ON);
			light_control(LIGHT_2, LIGHT_ON);
			light_control(LIGHT_3, LIGHT_ON);
			light_control(LIGHT_4, LIGHT_ON);
			light_control(LIGHT_5, LIGHT_ON);
			light_control(LIGHT_6, LIGHT_ON);
			light_control(LIGHT_7, LIGHT_ON);
			//flag所指示的那盏灯被关闭
			light_control(lights[flag & 0x7], LIGHT_OFF);
		}
		//以下加入用户程序--------------------------------------------------------
	}	//主循环end_for
		//主循环结束==================================================================
}
