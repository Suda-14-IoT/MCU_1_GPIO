//˵���������ļ����µ�Doc�ļ�����Readme.txt�ļ�
//======================================================================

#include "includes.h"   //������ͷ�ļ�

int main(void)
{
	//1. ����������ʹ�õı���
	uint_8 flag;		//����״̬��ɵı�־
	uint_16 lights[8];	//�±�����Ӧ�Ƶ�ӳ�����飬��0����LIGHT_0
	//2. �����ж�
	DISABLE_INTERRUPTS;

	//3. ��ʼ������ģ��
	//LIGHT��KEY�����ź궨�������Ӧ��.h�ļ���
	//��ʼ�����ƣ����Ĺ�light.h��LIGHT_ON��LIGHT_OFF����Ӧ���߼���
	light_init(LIGHT_0, LIGHT_OFF);
	light_init(LIGHT_1, LIGHT_OFF);
	light_init(LIGHT_2, LIGHT_OFF);
	light_init(LIGHT_3, LIGHT_OFF);
	light_init(LIGHT_4, LIGHT_OFF);
	light_init(LIGHT_5, LIGHT_OFF);
	light_init(LIGHT_6, LIGHT_OFF);
	light_init(LIGHT_7, LIGHT_OFF);
	//��ʼ�������أ�KEY_0-KEY-2����ɵ�3λ������������ָʾ��յ����
	//KEY_3״̬ΪKEY_ONʱ��ʾ�߼���ת��������ָʾ����յ����
	key_init(KEY_0);
	key_init(KEY_1);
	key_init(KEY_2);
	key_init(KEY_3);

	//4. ���йر�������ֵ
	//�����±�����Ӧ�Ƶ�ӳ��
	lights[0] = LIGHT_0;
	lights[1] = LIGHT_1;
	lights[2] = LIGHT_2;
	lights[3] = LIGHT_3;
	lights[4] = LIGHT_4;
	lights[5] = LIGHT_5;
	lights[6] = LIGHT_6;
	lights[7] = LIGHT_7;

	//5. ʹ��ģ���ж�

	//6. �����ж�
	ENABLE_INTERRUPTS;

	//������ѭ��
	//��ѭ����ʼ==================================================================
	for (;;)
	{
		//flag��0
		flag = 0;
		//��ȡ3�����ص�״̬����������flag
		flag |= (key_get(KEY_0) << 0);
		flag |= (key_get(KEY_1) << 1);
		flag |= (key_get(KEY_2) << 2);

		//��ȡKEY_3����״̬
		if (key_get(KEY_3) == KEY_OFF)	//�����عر�ʱ��Ϊ���߼�
		{
			//�ر����е�
			light_control(LIGHT_0, LIGHT_OFF);
			light_control(LIGHT_1, LIGHT_OFF);
			light_control(LIGHT_2, LIGHT_OFF);
			light_control(LIGHT_3, LIGHT_OFF);
			light_control(LIGHT_4, LIGHT_OFF);
			light_control(LIGHT_5, LIGHT_OFF);
			light_control(LIGHT_6, LIGHT_OFF);
			light_control(LIGHT_7, LIGHT_OFF);
			//flag��ָʾ����յ�Ʊ�����
			light_control(lights[flag & 0x7], LIGHT_ON);
		}
		else	//�����ؿ���ʱ��Ϊ���߼�
		{
			//�������е�
			light_control(LIGHT_0, LIGHT_ON);
			light_control(LIGHT_1, LIGHT_ON);
			light_control(LIGHT_2, LIGHT_ON);
			light_control(LIGHT_3, LIGHT_ON);
			light_control(LIGHT_4, LIGHT_ON);
			light_control(LIGHT_5, LIGHT_ON);
			light_control(LIGHT_6, LIGHT_ON);
			light_control(LIGHT_7, LIGHT_ON);
			//flag��ָʾ����յ�Ʊ��ر�
			light_control(lights[flag & 0x7], LIGHT_OFF);
		}
		//���¼����û�����--------------------------------------------------------
	}	//��ѭ��end_for
		//��ѭ������==================================================================
}
