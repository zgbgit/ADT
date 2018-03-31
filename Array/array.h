#ifndef _ARRAY_H
#define _ARRAY_H

#include "LinkList.h"
#include "err.h"

typedef struct _array
{
	char * base;
	int len;
}Array;

/*��ʼ��һ������*/
Status Array_Init(Array ** arr,int len);
/*�ͷ�һ������*/
Status Array_Destroy(Array ** arr);
/*��ȡ�������±�Ϊindex��Ԫ�ص�ֵ��value*/
Status Array_Value(Array * arr,int index,char * value);
/*�����������±�Ϊindex��Ԫ�ص�ֵΪvalue*/
Status Array_Assign(Array * arr,int index,char value);
/*�������е�Ԫ�ؽ��в�������*/
Status Array_InsertSort(Array * arr);
/*��ӡ�����е�Ԫ��*/
Status Array_Show( Array * arr );





#endif

