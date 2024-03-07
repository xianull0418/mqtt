#pragma once

#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-11-19

Description: ���������� ��������

**************************************************************************/

typedef void(*fnCallbackSendData)(const char* pstrTopic, const char* pstrMessage, unsigned char nQs);
typedef const char* (*fnCallbackGetMessage)(char* pGetDataBuffer, int nLength, const char* pstrRecvMessage);
/*
*Summary:������ʼ��
*Parameters:
* pstrProductId ��ƷID
* pstrDeviceNum �豸���� IMEI
* callbackSendData ���ݷ��ͺ���
* callbackPropertyData ��Ʒ��ȡ
*Return:
*/
void comInteractionInit(
	const int nProductId,
	const char* pstrDeviceNum,
	void* callbackSendData,
	void* callbackPropertyData,
	void* callbackFunctionData,
	void* callbackEventData,
	void* callbackDeviceInformationData);
/*
*Summary:��ʱ��ʼ��
*Parameters:
*Return:
*/
void comInteractionDelayInit();

/*
*Summary:�������Է���
*Parameters:
* nTime ��������, 0ֹͣ��ʱ�� ����ֵ������ʱ��
*Return:
*/
void setPropertyPush(unsigned int nTime);

/*
*Summary:���ù��ܷ���
*Parameters:
* nTime ��������, 0ֹͣ��ʱ�� ����ֵ������ʱ��
*Return:
*/
void setFunctionPush(unsigned int nTime);

/*
*Summary:�����¼�����
*Parameters:
* nTime ��������, 0ֹͣ��ʱ�� ����ֵ������ʱ��
*Return:
*/
void setEventPush(unsigned int nTime);

/*
*Summary:��ȡҪ���ĵ���������
*Parameters:
*Return: �����ڲ��ַ��� �ѷָ�����ɶ��
*/
const char* getSubscriberAll();

/*
*Summary:���ݻص�����
*Parameters:
* pstrTopic ����
* pstrmessage ��Ϣ
*Return:
*/
void onRecvData(const char* pstrTopic, const char* pstrmessage);

void triggerPropertyPush();
void triggerFunctionPush();
void triggerEventPush();
