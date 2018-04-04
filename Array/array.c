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

Status Array_Int32_Init(Array ** arr,int len)
{
	Array * Arr_tmp = NULL;
	
	Arr_tmp = (Array *)malloc(sizeof(Array));
	if(NULL == arr)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	Arr_tmp->base_int32 = (int *)malloc(len*2);
	Arr_tmp->len = len;
	Arr_tmp->tpye_index = 4;
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

Status Array_Value(Array * arr,int index,...)
{
	va_list argp;
	void * tmp;
	
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

	va_start( argp, index );
	switch(arr->tpye_index)
	{
		case 0:
			tmp = va_arg(argp, char *);
			*tmp = *(arr->base_int8 + index);
			break;
		case 1:
			tmp = va_arg(argp, unsigned char *);
			*tmp = *(arr->base_uint8 + index);
			break;
		case 2:
			tmp = va_arg(argp, short *);
			*tmp = *(arr->base_int16 + index);
			break;
		case 3:
			tmp = va_arg(argp, unsigned short *);
			*tmp = *(arr->base_uint16 + index);
			break;
		case 4:
			tmp = va_arg(argp, int *);
			*tmp = *(arr->base_int32 + index);
			break;
		case 5:
			tmp = va_arg(argp, unsigned int *);
			*tmp = *(arr->base_uint32 + index);
			break;
		case default:
			printf("[ERR]: %s %d\n",__func__,__LINE__);
			return ERROR;
	}

	va_end(argp); 

	return OK;
}

Status Array_Assign(Array * arr,int index,...)
{
	va_list argp; 
	
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

	va_start( argp, index );
	switch(arr->tpye_index)
	{
		case 0:
			*(arr->base_int8 + index) = va_arg(argp, char);
			break;
		case 1:
			*(arr->base_uint8+ index) = va_arg(argp, unsigned char);
			break;
		case 2:
			*(arr->base_int16 + index) = va_arg(argp, short);
			break;
		case 3:
			*(arr->base_uint16 + index) = va_arg(argp, unsigned short);
			break;
		case 4:
			*(arr->base_int32 + index) = va_arg(argp, int);
			break;
		case 5:
			*(arr->base_uint32 + index) = va_arg(argp, unsigned int);
			break;
		case default:
			printf("[ERR]: %s %d\n",__func__,__LINE__);
			return ERROR;
	}

	va_end(argp); 

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
		if(*(arr->base + i) < *(arr->base + i - 1))//新插入的元素如果不是比有序表中最后一个大，就要进行插入排序
		{
			tmp = *(arr->base + i);//将要进行插入的值备份
			//arr->base[i] = arr->base[i-1];//有序表中最后一个元素移动到当前有序表最后
			for(j = i - 1;j >= 0 && tmp < *(arr->base + j);j-=1)
			{
				*(arr->base + j + 1) = *(arr->base + j);//有序表后移
			}
			*(arr->base + j + 1) = tmp;//插入
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
			
			for(j = i - dk;j >= 0 && tmp < *(arr->base + j);j-=dk)
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

