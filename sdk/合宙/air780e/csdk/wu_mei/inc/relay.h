#pragma once

#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-11-19

Description: ���������� �̵���ͷ�ļ�

**************************************************************************/
#include "luat_gpio.h"
#include "platform_define.h"


/*
*Summary:�̵�����ʼ��
*Parameters:
*Return:
*/
void relayInit();

/*
*Summary:�̵�������
*Parameters:
*	nRelayIndex:�̵�����
*   nValue ����ֵ
*Return: 0 ʧ�� 1�ɹ�
*/
unsigned char relayControl(unsigned char nRelayIndex, unsigned char nValue);

unsigned char relayGetValue(unsigned char nRelayIndex);