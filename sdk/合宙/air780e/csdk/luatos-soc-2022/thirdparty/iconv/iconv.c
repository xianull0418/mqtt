/**************************************************************************
 *              Copyright (C), AirM2M Tech. Co., Ltd.
 *
 * Name:    iconv.c
 * Author:  liweiqiang
 * Version: V0.1
 * Date:    2013/7/15
 *
 * Description:
 *          �ַ�����ת��
 **************************************************************************/
 /*
@module  iconv
@summary �ַ�����ת��
@version V0.1
@data    2021��12��13��
*/

#include <string.h>
#include "iconv.h"
#include "prv_iconv.h"

typedef struct builtin_iconv_map_tag
{
    const char      *from;
    const char      *to;
    const iconv_fct fct;
}builtin_iconv_map;

static const builtin_iconv_map iconv_map[] =
{
    {"ucs2",    "gb2312",   iconv_ucs2_to_gb2312},
/*+\NEW\liweiqiang\2013.11.26\����gb2312<->ucs2(ucs2be)����ת��*/
    {"ucs2be",  "gb2312",   iconv_ucs2be_to_gb2312},
    {"gb2312",  "ucs2",     iconv_gb2312_to_ucs2},
    {"gb2312",  "ucs2be",   iconv_gb2312_to_ucs2be},
/*-\NEW\liweiqiang\2013.11.26\����gb2312<->ucs2(ucs2be)����ת��*/
/*+\NEW\liweiqiang\2013.7.19\����utf8<->ucs2,ucs2be����ת��*/
    {"utf8",    "ucs2",     iconv_utf8_to_ucs2},
    {"utf8",    "ucs2be",   iconv_utf8_to_ucs2be},
    {"ucs2",    "utf8",     iconv_ucs2_to_utf8},
    {"ucs2be",    "utf8",     iconv_ucs2be_to_utf8},
/*-\NEW\liweiqiang\2013.7.19\����utf8<->ucs2,ucs2be����ת��*/
};

/*
����Ӧ�ַ�����ת������
@function iconv.open(tocode, fromcode) 
@string tocode$Ŀ������ʽ$gb2312/ucs2/ucs2be/utf8
@string fromcode$Դ�����ʽ$gb2312/ucs2/ucs2be/utf8
@return table$cd$����ת��������ת�����$ 
@usage
--unicode��˱��� ת��Ϊ utf8����
local cd = iconv.open("utf8", "ucs2be")
*/
iconv_t iconv_open (const char * to_code, const char * from_code)
{
    size_t i;

    for(i = 0; i < sizeof(iconv_map)/sizeof(iconv_map[0]); i++)
    {
        if(strcmp(iconv_map[i].from, from_code) == 0 &&
            strcmp(iconv_map[i].to, to_code) == 0)
        {
            return (iconv_t)&iconv_map[i];
        }
    }

    return (iconv_t)-1;
}

/*
�ַ�����ת��
@function cd:iconv(inbuf) 
@string inbuf$�����ַ���$����:ucs2s 
@return number$result$���ر���ת����Ľ��$0�ɹ�,-1ʧ��
@usage
--unicode��˱��� ת��Ϊ utf8����
function ucs2beToUtf8(ucs2s)
    local cd = iconv.open("utf8", "ucs2be")
    return cd:iconv(ucs2s)
end
*/
size_t iconv_convert (iconv_t __cd, char ** __inbuf, size_t * __inbytesleft, char ** __outbuf, size_t * __outbytesleft)
{
    builtin_iconv_map *_map_cd = (builtin_iconv_map *)__cd;

    if(__inbuf == NULL || *__inbuf == NULL)
        return (size_t)-1;

    if(_map_cd < &iconv_map[0] &&
        _map_cd > &iconv_map[sizeof(iconv_map)/sizeof(iconv_map[0])])
        return (size_t)-1;

    return _map_cd->fct(__inbuf, __inbytesleft, __outbuf, __outbytesleft);
}

/*
�ر��ַ�����ת��
@function iconv.close(cd) 
@string cd$iconv.open���صľ��$ 
@return  
@usage
--�ر��ַ�����ת��
local cd = iconv.open("utf8", "ucs2be")
iconv.close(cd)
*/
int iconv_close (iconv_t cd)
{
    return 0;
}

