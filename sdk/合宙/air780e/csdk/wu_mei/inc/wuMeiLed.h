#pragma once

#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-11-23

Description: ����������Led 

**************************************************************************/
#include "luat_gpio.h"
#include "platform_define.h"


/*
*Summary:�̵�����ʼ��
*Parameters:
*Return:
*/
void ledInit();

/*
*Summary:�̵�������
*Parameters:
*	nledIndex:�̵�����
*   nValue ����ֵ
*Return: 0 ʧ�� 1�ɹ�
*/
unsigned char ledControl(unsigned char nledIndex, unsigned char nValue);