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
			for(j = i - 1;tmp < *(arr->base + j);j-=1)
			{
				*(arr->base + j + 1) = *(arr->base + j);//��������
			}
			*(arr->base + j + 1) = tmp;//����
		}
	}

	return OK;
}

static Status Array_ShellInsert(Array * arr, int dk)
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

	for(i = dk;i < arr->len;i++)
	{
		if(*(arr->base + i) < *(arr->base + i - dk))
		{
			tmp = *(arr->base + i);
			
			for(j = i - dk;tmp < *(arr->base + j);j-=dk)
			{
				*(arr->base + j + dk) = *(arr->base + j);
			}
			*(arr->base + j + dk) = tmp;
		}
	}

	return OK;
}

Status Array_ShellSort(Array * arr)
{
	int dlta[] = {9,5,3,2,1};
	int i;

	for(i = 0;i < 5;i++)
	{
		Array_ShellInsert(arr,dlta[i]);
	}

	return OK;
}

Status Array_BubbleSort(Array * arr)
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

	for(i = 0;i < (arr->len - 1); i++)
	{
		for(j = 0;j < (arr->len - i - 1);j++)
		{
			if(*(arr->base + j + 1) < *(arr->base + j))
			{
				tmp = *(arr->base + j + 1);
				*(arr->base + j + 1) = *(arr->base + j);
				*(arr->base + j) = tmp;
			}
		}
	}
	return OK;
}

static int Array_Partition(Array * arr, int low, int high)
{
	char pivokey = 0;

	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	pivokey = *(arr->base + low);
	while(low < high)
	{
		while((low < high) && (*(arr->base + high) >= pivokey)) --high;
		*(arr->base + low) = *(arr->base + high);
		while((low < high) && (*(arr->base + low) <= pivokey)) ++low;
		*(arr->base + high) = *(arr->base + low);
	}
	*(arr->base + low) = pivokey;

	return low;
}

static Status Array_QuickSortRecursion(Array * arr, int low, int high)
{
	int pivoloc = 0;
	
	if(low < high)
	{
		pivoloc = Array_Partition(arr,low,high);
		Array_QuickSortRecursion(arr,low,pivoloc - 1);
		Array_QuickSortRecursion(arr,pivoloc + 1,high);
	}

	return OK;
}

Status Array_QuickSort(Array * arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	
	Array_QuickSortRecursion(arr,0,arr->len - 1);

	return OK;
}

static Status Array_QuickSortRecursion_Improve(Array * arr, int low, int high)
{
	int pivoloc = 0;
	
	if(low < high)
	{
		pivoloc = Array_Partition(arr,low,high);
		if(pivoloc >= ((low + high) >> 1))
		{
			Array_QuickSortRecursion(arr,pivoloc + 1,high);
			Array_QuickSortRecursion(arr,low,pivoloc - 1);
		}
		else
		{
			Array_QuickSortRecursion(arr,low,pivoloc - 1);
			Array_QuickSortRecursion(arr,pivoloc + 1,high);
		}
	}

	return OK;
}

Status Array_QuickSort_Improve(Array * arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	
	Array_QuickSortRecursion_Improve(arr,0,arr->len - 1);

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

