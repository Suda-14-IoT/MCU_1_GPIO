//======================================================================
//文件名称：key.h
//功能概要：开关构件头文件
//制作单位：赵俊杰
//更新记录：2016-10-16 V1.0
//======================================================================

#ifndef _KEY_H	//防止重复定义（_KEY_H  开头)
#define _KEY_H

//头文件包含
#include "common.h"    //包含公共要素头文件
#include "gpio.h"      //用到gpio构件

//定义使用的开关引脚
#define KEY_0 (PTD_NUM|0)

//定义开关状态
#define KEY_ON  (0)		//低电平代表开关开启
#define KEY_OFF (1)		//高电平代表开关关闭

//=====================================================================
//函数名称：key_init
//函数返回：无
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：初始化指定端口引脚作为开关功能
//=====================================================================
void key_init(uint_16 port_pin);

//=====================================================================
//函数名称：key_get
//函数返回：指定开关的状态（KEY_ON(0)或KEY_OFF(1)）
//参数说明：port_pin：(端口号)|(引脚号)（如：(PTB_NUM)|(9) 表示为B口9号脚）
//功能概要：当指定端口引脚被定义为开关功能时，本函数获取指定引脚状态
//=====================================================================
uint_8 key_get(uint_16 port_pin);

#endif
