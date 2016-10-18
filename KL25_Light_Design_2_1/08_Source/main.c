//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#include "includes.h"   //包含总头文件

int main(void)
{
	//1. 声明主函数使用的变量

	//2. 关总中断
	DISABLE_INTERRUPTS;
	//3. 初始化外设模块

	//GPIO基本编程步骤：

	//(1)计算给出PORTB9的引脚控制寄存器地址
	//PORTB端口的引脚控制寄存器基地址为0x4004A000u（后缀u表示无符号数）
	volatile uint_32 *portB_ptr = (uint_32*) 0x4004A000u;
	//PORTB9的引脚控制寄存器地址=基地址+偏移量
	volatile uint_32 *portB_PCR_9 = portB_ptr + 9;

	//(2)计算给出PORTB的数据方向寄存器、输出寄存器地址
	//PORTB端口（作为GPIO功能）的基地址为0x400FF040u
	volatile uint_32 *gpioB_ptr = (uint_32*) 0x400FF040u;
	//PORTB的数据方向寄存器地址=基地址+偏移量
	volatile uint_32 *portB_PDDR = gpioB_ptr + 5;
	//PORTB的输出寄存器地址=基地址+偏移量
	volatile uint_32 *portB_PDO = gpioB_ptr + 0;

	//(3)设置PORTB9引脚为GPIO引脚，即令相应引脚控制寄存器的10-8位
	//(MUX)字段为001
	*portB_PCR_9 &= 0b11111111111111111111100011111111; //清MUX位段
	*portB_PCR_9 |= 0b00000000000000000000000100000000;

	//(4)通过PORTB的输出寄存器(给蓝色小灯的寄存器）赋初值1，保证定义为输出时为暗
	*portB_PDO |= (1 << 9);

	//(5)通过PORTB的方向寄存器，定义PORTB9引脚输出
	*portB_PDDR |= (1 << 9);

	//(6)计算给出PORTD0的引脚控制寄存器地址
	//PORTD0的引脚控制寄存器地址=基地址+偏移量
	volatile uint_32 *portD_PCR_0 = (uint_32*) 0x4004C000u + 0;

	//(7)计算给出PORTD的数据方向寄存器、引脚状态寄存器
	//PORTD端口（作为GPIO功能）的基地址为0x400FF0C0u
	volatile uint_32 *gpioD_ptr = (uint_32*) 0x400FF0C0u;
	//PORTD的数据方向寄存器地址=基地址+偏移量
	volatile uint_32 *portD_PDDR = gpioD_ptr + 5;
	//PORTD的引脚状态寄存器地址=基地址+偏移量
	volatile uint_32 *portD_PDIR = gpioD_ptr + 4;

	//(8)设置PORTD0引脚为GPIO引脚，即令相应引脚控制寄存器的10-8位
	//(MUX)字段为001
	*portD_PCR_0 &= 0b11111111111111111111100011111111; //清MUX位段
	*portD_PCR_0 |= 0b00000000000000000000000100000000;

	//(9)通过PORTD的方向寄存器，定义PORTD0引脚输入
	*portD_PDDR &= ~(1 << 0);

	//(10)拉高PORTD0引脚（讲道理来说是要拉高引脚的，但是这里拉高拉低效果都一样，我怀疑PTD|0没上下拉电阻）
	//设定正常驱动能力（低驱动能力）（5mA）
	*portD_PCR_0 &= ~(1 << 6);
	//将引脚上下拉使能
	*portD_PCR_0 |= (1 << 1);
	//拉高引脚
	*portD_PCR_0 |= (1 << 0);

	//4. 给有关变量赋初值

	//5. 使能模块中断

	//6. 开总中断
	ENABLE_INTERRUPTS;

	for (;;)
	{
		//不断获取PORTD0引脚状态寄存器的状态
		if (((*portD_PDIR >> 0) & 0x1) == 0)	//状态为0，即开关开启时
		{
			*portB_PDO &= ~(1 << 9);   //灯亮
		}
		else	//状态为1，即开关关闭时
		{
			*portB_PDO |= (1 << 9);    //灯暗
		}
		//以下加入用户程序-----------------------------------------------------
	} //end_for
	  //主循环结束===================================================================

}

