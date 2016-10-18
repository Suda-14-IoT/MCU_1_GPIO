//˵���������ļ����µ�Doc�ļ�����Readme.txt�ļ�
//======================================================================

#include "includes.h"   //������ͷ�ļ�

int main(void)
{
	//1. ����������ʹ�õı���
	uint_32 mRuncount;		//��ѭ��������
	uint_8 cycle;			//��������־
	//2. �����ж�
	DISABLE_INTERRUPTS;

	//3. ��ʼ������ģ��
	light_init(LIGHT_RED, LIGHT_OFF);      //��Ƴ�ʼ��
	light_init(LIGHT_GREEN, LIGHT_OFF);    //�̵Ƴ�ʼ��

	//4. ���йر�������ֵ
	mRuncount = 0;
	cycle = 0;
	//5. ʹ��ģ���ж�

	//6. �����ж�
	ENABLE_INTERRUPTS;

	//������ѭ��
	//��ѭ����ʼ==================================================================
	for (;;)
	{
		mRuncount++;					   //��ѭ������������+1
		if (mRuncount >= RUN_COUNTER_MAX)  //��ѭ�����������������趨�ĺ곣��
		{
			mRuncount = 0;
			//���������������־�Եƽ��п��ƣ�0-13ʱΪ�̵ƣ�14-19ʱΪ��˸�̵ƣ�
			//20-25ʱΪ�Ƶƣ�26-45ʱΪ���
			if (cycle >= 0 && cycle <= 13)
			{
				//�̵�
				light_control(LIGHT_GREEN, LIGHT_ON);
				light_control(LIGHT_RED, LIGHT_OFF);
			}
			else if (cycle >= 14 && cycle <= 19)
			{
				if ((cycle & 0x1) == 0)	//������Ϊż��ʱ
				{
					//�̵�
					light_control(LIGHT_GREEN, LIGHT_ON);
					light_control(LIGHT_RED, LIGHT_OFF);
				}
				else	//������Ϊ����ʱ
				{
					//�޵�
					light_control(LIGHT_GREEN, LIGHT_OFF);
					light_control(LIGHT_RED, LIGHT_OFF);
				}
			}
			else if (cycle >= 20 && cycle <= 25)
			{
				//�Ƶ�
				light_control(LIGHT_GREEN, LIGHT_ON);
				light_control(LIGHT_RED, LIGHT_ON);
			}
			else
			{
				//���
				light_control(LIGHT_GREEN, LIGHT_OFF);
				light_control(LIGHT_RED, LIGHT_ON);
			}
			//��������1������1����ڵ���46������0
			if (++cycle >= 46)
			{
				cycle = 0;
			}
		}
		//���¼����û�����--------------------------------------------------------
	} //��ѭ��end_for
	  //��ѭ������==================================================================
}

