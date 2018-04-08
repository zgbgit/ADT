#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "array.h"

Status Array_Int8_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_int8 = (char *)malloc(len);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 0;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Uint8_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_uint8 = (unsigned char *)malloc(len);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 1;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Int16_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_int16 = (short *)malloc(len);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 2;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Uint16_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_uint16 = (unsigned short *)malloc(len*2);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 3;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Init_Int32(Array_Int32 ** arr,int len)
{
	Array_Int32 * Arr_tmp = NULL;
	
	Arr_tmp = (Array_Int32 *)malloc(sizeof(Array_Int32));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_int32 = (int *)malloc(len*4);
	Arr_tmp->len = len;
	*arr = Arr_tmp;

	return OK;
}

Status Array_Uint32_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_uint32 = (unsigned int *)malloc(len*4);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 5;
	*arr = Arr_tmp;

	return OK;
}


Status Array_Destroy_Int32(Array_Int32 ** arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	free((*arr)->base_int32);
	free(*arr);

	return OK;
}

Status Array_Value_Int32(Array_Int32 * arr,int index,int * value)
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

	*value = *(arr->base_int32 + index);


	return OK;
}

Status Array_Assign_Int32(Array_Int32 * arr,int index,int value)
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
	
	*(arr->base_int32 + index) = value;
	
	return OK;
}

Status Array_InsertSort_Int32(Array_Int32 * arr)
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
		if(*(arr->base_int32+ i) < *(arr->base_int32 + i - 1))//新插入的元素如果不是比有序表中最后一个大，就要进行插入排序
		{
			tmp = *(arr->base_int32 + i);//将要进行插入的值备份
			//arr->base[i] = arr->base[i-1];//有序表中最后一个元素移动到当前有序表最后
			for(j = i - 1;j >= 0 && tmp < *(arr->base_int32 + j);j-=1)
			{
				*(arr->base_int32 + j + 1) = *(arr->base_int32 + j);//有序表后移
			}
			*(arr->base_int32 + j + 1) = tmp;//插入
		}
	}

	return OK;
}

static Status Array_ShellInsert_Int32(Array_Int32 * arr, int dk)
{
	int i,j;
	int tmp;
	
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
		if(*(arr->base_int32 + i) < *(arr->base_int32 + i - dk))
		{
			tmp = *(arr->base_int32 + i);
			
			for(j = i - dk;j >= 0 && tmp < *(arr->base_int32 + j);j-=dk)
			{
				*(arr->base_int32 + j + dk) = *(arr->base_int32 + j);
			}
			*(arr->base_int32 + j + dk) = tmp;
		}
	}

	return OK;
}

Status Array_ShellSort_Int32(Array_Int32 * arr)
{
	int dlta[] = {9,5,3,2,1};
	int i;

	for(i = 0;i < 5;i++)
	{
		Array_ShellInsert_Int32(arr,dlta[i]);
	}

	return OK;
}

Status Array_BubbleSort_Int32(Array_Int32 * arr)
{
	int i,j;
	int tmp;
	
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
			if(*(arr->base_int32 + j + 1) < *(arr->base_int32 + j))
			{
				tmp = *(arr->base_int32 + j + 1);
				*(arr->base_int32 + j + 1) = *(arr->base_int32 + j);
				*(arr->base_int32 + j) = tmp;
			}
		}
	}
	return OK;
}

static int Array_Partition_Int32(Array_Int32 * arr, int low, int high)
{
	int pivokey = 0;

	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	pivokey = *(arr->base_int32 + low);
	while(low < high)
	{
		while((low < high) && (*(arr->base_int32 + high) >= pivokey)) --high;
		*(arr->base_int32 + low) = *(arr->base_int32 + high);
		while((low < high) && (*(arr->base_int32 + low) <= pivokey)) ++low;
		*(arr->base_int32 + high) = *(arr->base_int32 + low);
	}
	*(arr->base_int32 + low) = pivokey;

	return low;
}

static Status Array_QuickSortRecursion_Int32(Array_Int32 * arr, int low, int high)
{
	int pivoloc = 0;
	
	if(low < high)
	{
		pivoloc = Array_Partition_Int32(arr,low,high);
		Array_QuickSortRecursion_Int32(arr,low,pivoloc - 1);
		Array_QuickSortRecursion_Int32(arr,pivoloc + 1,high);
	}

	return OK;
}

Status Array_QuickSort_Int32(Array_Int32 * arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	
	Array_QuickSortRecursion_Int32(arr,0,arr->len - 1);

	return OK;
}

static Status Array_QuickSortRecursion_Improve_Int32(Array_Int32 * arr, int low, int high)
{
	int pivoloc = 0;
	
	if(low < high)
	{
		pivoloc = Array_Partition_Int32(arr,low,high);
		if(pivoloc >= ((low + high) >> 1))
		{
			Array_QuickSortRecursion_Int32(arr,pivoloc + 1,high);
			Array_QuickSortRecursion_Int32(arr,low,pivoloc - 1);
		}
		else
		{
			Array_QuickSortRecursion_Int32(arr,low,pivoloc - 1);
			Array_QuickSortRecursion_Int32(arr,pivoloc + 1,high);
		}
	}

	return OK;
}

Status Array_QuickSort_Improve_Int32(Array_Int32 * arr)
{
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	
	Array_QuickSortRecursion_Improve_Int32(arr,0,arr->len - 1);

	return OK;
}

Status Array_Show_Int32( Array_Int32 * arr )
{
	int i;

	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	for(i = 0;i < arr->len; i++)
	{
		printf("%6d ",*(arr->base_int32 + i));
		if(0 == ((i + 1) % 10))
		{
			printf("\n");
		}
	}

	printf("\n");

	return OK;
}

