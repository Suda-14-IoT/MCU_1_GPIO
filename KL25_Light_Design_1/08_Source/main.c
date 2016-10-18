//˵���������ļ����µ�Doc�ļ�����Readme.txt�ļ�
//======================================================================

#include "includes.h"   //������ͷ�ļ�

int main(void)
{
	//1. ����������ʹ�õı���
	uint_32 mRuncount;		//��ѭ��������
	uint_8 flag;			//�ƿ��Ʊ�־
	//2. �����ж�
	DISABLE_INTERRUPTS;

	//3. ��ʼ������ģ��
	light_init(LIGHT_RED, LIGHT_OFF);      //��Ƴ�ʼ��
	light_init(LIGHT_BLUE, LIGHT_OFF);     //���Ƴ�ʼ��
	light_init(LIGHT_GREEN, LIGHT_OFF);    //�̵Ƴ�ʼ��

	//4. ���йر�������ֵ
	mRuncount = 0;            //��ѭ��������
	flag = 0;
	//5. ʹ��ģ���ж�

	//6. �����ж�
	ENABLE_INTERRUPTS;

	//������ѭ��
	//��ѭ����ʼ==================================================================
	for (;;)
	{
		//����ָʾ�ƣ�RUN_LIGHT����˸---------------------------------------------
		mRuncount++;					   //��ѭ������������+1
		if (mRuncount >= RUN_COUNTER_MAX)  //��ѭ�����������������趨�ĺ곣��
		{
			mRuncount = 0;
			switch (flag)
			{
			case 0: //���
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 1: //����
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 2: //�̵�
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 3: //�ϵ�
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_OFF);
				break;
			case 4: //�Ƶ�
				light_control(LIGHT_RED, LIGHT_ON);
				light_control(LIGHT_BLUE, LIGHT_OFF);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 5: //���
				light_control(LIGHT_RED, LIGHT_OFF);
				light_control(LIGHT_BLUE, LIGHT_ON);
				light_control(LIGHT_GREEN, LIGHT_ON);
				break;
			case 6: //�׵�
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
		//���¼����û�����--------------------------------------------------------
	} //��ѭ��end_for
	  //��ѭ������==================================================================
}

