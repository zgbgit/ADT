#ifndef _ARRAY_H
#define _ARRAY_H

#include "LinkList.h"
#include "err.h"

typedef struct _array
{
#if 1
	char * base_int8;
	unsigned char * base_uint8;
	short * base_int16;
	unsigned short * base_uint16;
	int * base_int32;
	unsigned * base_uint32;
	int len;
	int tpye_index;//0-char 1-uchar 2-int16 3-uint16 4-int32 5-uint32
#endif
}Array;

typedef struct _array_int32
{
	int * base_int32;
	int len;
}Array_Int32;


/*��ʼ��һ��char������*/
Status Array_Int8_Init(Array ** arr,int len);
/*��ʼ��һ��uchar������*/
Status Array_Uint8_Init(Array ** arr,int len);
/*��ʼ��һ��int16������*/
Status Array_Int16_Init(Array ** arr,int len);
/*��ʼ��һ��uint16������*/
Status Array_Uint16_Init(Array ** arr,int len);
/*��ʼ��һ��int32������*/
Status Array_Init_Int32(Array_Int32 ** arr,int len);
/*��ʼ��һ��uint32������*/
Status Array_Uint32_Init(Array ** arr,int len);
/*�ͷ�һ������*/
Status Array_Destroy_Int32(Array_Int32 ** arr);
/*��ȡ�������±�Ϊindex��Ԫ�ص�ֵ��value*/
Status Array_Value_Int32(Array_Int32 * arr,int index,int * value);
/*�����������±�Ϊindex��Ԫ�ص�ֵΪvalue*/
Status Array_Assign_Int32(Array_Int32 * arr,int index,int value);
/*�������е�Ԫ�ؽ��в�������*/
Status Array_InsertSort_Int32(Array_Int32 * arr);
/*��ӡ�����е�Ԫ��*/
Status Array_Show_Int32( Array_Int32 * arr );
/*ϣ������*/
Status Array_ShellSort_Int32(Array_Int32 * arr);
/*ð������*/
Status Array_BubbleSort_Int32(Array_Int32 * arr);
/*��������*/
Status Array_QuickSort_Int32(Array_Int32 * arr);
/*�Ż�ջʹ�õĿ�������*/
Status Array_QuickSort_Improve_Int32(Array_Int32 * arr);

#endif

