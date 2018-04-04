#ifndef _ARRAY_H
#define _ARRAY_H

#include "LinkList.h"
#include "err.h"

typedef struct _array
{
	char * base_int8;
	unsigned char * base_uint8;
	short * base_int16;
	unsigned short * base_uint16;
	int * base_int32;
	unsigned * base_uint32;
	int len;
	int tpye_index;//0-char 1-uchar 2-int16 3-uint16 4-int32 5-uint32
}Array;

/*��ʼ��һ��char������*/
Status Array_Int8_Init(Array ** arr,int len);
/*��ʼ��һ��uchar������*/
Status Array_Uint8_Init(Array ** arr,int len);
/*��ʼ��һ��int16������*/
Status Array_Int16_Init(Array ** arr,int len);
/*��ʼ��һ��uint16������*/
Status Array_Uint16_Init(Array ** arr,int len);
/*��ʼ��һ��int32������*/
Status Array_Int32_Init(Array ** arr,int len);
/*��ʼ��һ��uint32������*/
Status Array_Uint32_Init(Array ** arr,int len);
/*�ͷ�һ������*/
Status Array_Destroy(Array ** arr);
/*��ȡ�������±�Ϊindex��Ԫ�ص�ֵ��value*/
Status Array_Value(Array * arr,int index,char * value);
/*�����������±�Ϊindex��Ԫ�ص�ֵΪvalue*/
Status Array_Assign(Array * arr,int index,...);
/*�������е�Ԫ�ؽ��в�������*/
Status Array_InsertSort(Array * arr);
/*��ӡ�����е�Ԫ��*/
Status Array_Show( Array * arr );
/*���5�������ϣ������*/
Status Array_ShellSort(Array * arr);
/*ð������*/
Status Array_BubbleSort(Array * arr);
/*��������*/
Status Array_QuickSort(Array * arr);
/*�Ż�ջʹ�õĿ�������*/
Status Array_QuickSort_Improve(Array * arr);

#endif

