//======================================================================
//�ļ����ƣ�key.c
//���ܸ�Ҫ�����ع���Դ�ļ�
//������λ���Կ���
//���¼�¼��2016-10-16 V1.0
//======================================================================

#include "key.h"	//����������ͷ�ļ�

//=====================================================================
//�������ƣ�key_init
//�������أ���
//����˵����port_pin��(�˿ں�)|(���ź�)���磺(PTB_NUM)|(9) ��ʾΪB��9�Žţ�
//���ܸ�Ҫ����ʼ��ָ���˿�������Ϊ���ع���
//=====================================================================
void key_init(uint_16 port_pin)
{
	//��ʼ��������ΪGPIO���빦��
	gpio_init(port_pin, GPIO_IN, KEY_OFF);
	//���ߵ�ƽ����ȷ������δ����ʱʼ�ջ�ȡ���ǹر�״̬
	gpio_pull(port_pin, KEY_OFF);
}

//=====================================================================
//�������ƣ�key_get
//�������أ�ָ�����ص�״̬��KEY_ON(0)��KEY_OFF(1)��
//����˵����port_pin��(�˿ں�)|(���ź�)���磺(PTB_NUM)|(9) ��ʾΪB��9�Žţ�
//���ܸ�Ҫ����ָ���˿����ű�����Ϊ���ع���ʱ����������ȡָ������״̬
//=====================================================================
uint_8 key_get(uint_16 port_pin)
{
	return gpio_get(port_pin);
}