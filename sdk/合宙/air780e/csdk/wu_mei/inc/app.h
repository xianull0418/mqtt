#pragma once

#include "header.h"
/**************************************************************************

Copyright: ���˽�

Author: ���˽� 1066950103@qq.com

Date: 2022-11-23

Description: ����app �Խӿ���

**************************************************************************/

//const char* pstrVersion = "0.1";
//const char* pstrUserId = "1";

const char* getFunctionData(char* pGetDataBuffer, int nLength, const char* pstrRecvMessage);
const char* getPropertyData(char* pGetDataBuffer, int nLength, const char* pstrRecvMessage);
const char* getInformationData(char* pGetDataBuffer, int nLength, const char* pstrRecvMessage);
const char* getEventData(char* pGetDataBuffer, int nLength, const char* pstrRecvMessage);