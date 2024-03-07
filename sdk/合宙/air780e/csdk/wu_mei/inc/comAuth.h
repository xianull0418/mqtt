#pragma once

#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-11-20

Description: ����csdk ��֤

**************************************************************************/
char* getComAuthUser();
char* getComAuthPassword();
char* getComAuthClientId();
char* getComAuthIp();
/*û�з���ֵ ����Ϊ���0 ʧ�� 1�ɹ�*/
typedef void(*pComAuthResultFunction)(unsigned char );

/*
*Summary:������֤��ʼ��
*Parameters:
* pstrEncryptionMode ����ģʽ
* pstrProductId ��ƷID
* pstrDeviceId �豸ID
* pstrUserId �û�ID
* pstrUse �û�
* pstrPassword ����
* nTimeout ����ʱ�� ��Ϊ��λ
* pstrIp ip
* pstrDeviceAuthorizationCode �豸��֤code
* pstrProductPassword ��Ʒ����
* callback �ص�����
*Return:
*/
void ComAuthInit(
	const char* pstrEncryptionMode, 
	const int nProductId,
	const char* pstrDeviceId, 
	const char* pstrUserId, 
	const char* pstrUser, 
	const char* pstrPassword, 
	unsigned int nTimeout, 
	const char* pstrIp, 
	const char* pstrDeviceAuthorizationCode, 
	const char* pstrProductPassword, 
	void* callback
);


