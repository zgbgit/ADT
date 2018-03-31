#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "array.h"

Status Array_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base = (char *)malloc(len);
	Arr_tmp->len = len;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Destroy(Array ** arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	free((*arr)->base);
	free(*arr);

	return OK;
}

Status Array_Value(Array * arr,int index,char * value)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(index >= arr->len)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	
	*value = *(arr->base + index);

	return OK;
}

Status Array_Assign(Array * arr,int index,char value)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(index >= arr->len)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	*(arr->base + index) = value;

	return OK;
}

Status Array_InsertSort(Array * arr)
{
	int i,j;
	char tmp;
	
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(arr->len < 2)
	{
		return OK;
	}

	for(i = 1;i < arr->len;i++)
	{
		if(arr->base[i] < arr->base[i-1])//�²����Ԫ��������Ǳ�����������һ���󣬾�Ҫ���в�������
		{
			tmp = *(arr->base + i);//��Ҫ���в����ֵ����
			//arr->base[i] = arr->base[i-1];//����������һ��Ԫ���ƶ�����ǰ��������
			for(j = i - 1;tmp < *(arr->base + j);j--)
			{
				*(arr->base + j + 1) = *(arr->base + j);//��������
			}
			*(arr->base + j + 1) = tmp;//����
		}
	}

	return OK;
}

Status Array_Show( Array * arr )
{
	int i;

	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	for(i = 0;i < arr->len; i++)
	{
		printf("%3d ",*(arr->base + i));
		if(0 == ((i + 1) % 10))
		{
			printf("\n");
		}
	}

	printf("\n");

	return OK;
}

