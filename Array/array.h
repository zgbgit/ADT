#ifndef _ARRAY_H
#define _ARRAY_H

#include "LinkList.h"
#include "err.h"

typedef struct _array
{
	char * base;
	int len;
}Array;

/*初始化一个数组*/
Status Array_Init(Array ** arr,int len);
/*释放一个数组*/
Status Array_Destroy(Array ** arr);
/*获取数组中下标为index的元素的值给value*/
Status Array_Value(Array * arr,int index,char * value);
/*设置数组中下标为index的元素的值为value*/
Status Array_Assign(Array * arr,int index,char value);
/*将数组中的元素进行插入排序*/
Status Array_InsertSort(Array * arr);
/*打印数组中的元素*/
Status Array_Show( Array * arr );
/*最多5趟排序的希尔排序*/
Status Array_ShellSort(Array * arr);
/*冒泡排序*/
Status Array_BubbleSort(Array * arr);
/*快速排序*/
Status Array_QuickSort(Array * arr);
/*优化栈使用的快速排序*/
Status Array_QuickSort_Improve(Array * arr);

#endif

