#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-12-01

Description: ���������� ����ͷ�ļ�

**************************************************************************/
#include "luat_uart.h"

void uartInit();
void uartSend(unsigned char nUartId, unsigned char* pnData, unsigned int nLength);
unsigned char* getUartBuffer(unsigned char nUartId);
unsigned int getUartRxLength(unsigned char nUartId);
