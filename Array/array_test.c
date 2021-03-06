#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include "array.h"

int main(int ac, char *av[])
{
	struct timeval start,end;
	suseconds_t usec;
	time_t sec;
	Array_Int32 * arr_a = NULL;
	int i = 0;
	int array_len = 500;

	gettimeofday(&start,NULL);

	Array_Init_Int32(&arr_a,array_len);

	for(i = 0;i < array_len;i++)
	{
		Array_Assign_Int32(arr_a,i,array_len - i);
	}
	Array_Show_Int32(arr_a);
	printf("\n\n");
#if 0
	Array_Assign(arr_a,0,15);
	Array_Show(arr_a);

	Array_Assign(arr_a,1,14);
	Array_Show(arr_a);

	//Array_ShellSort(arr_a);
	//Array_Show(arr_a);

	Array_Assign(arr_a,2,13);
	Array_Show(arr_a);

	Array_Assign(arr_a,3,12);
	Array_Show(arr_a);

	Array_Assign(arr_a,4,11);
	Array_Show(arr_a);
#endif
	//Array_InsertSort(arr_a);
	//Array_ShellSort(arr_a);
	//Array_BubbleSort(arr_a);
	//Array_QuickSort(arr_a);
	Array_QuickSort_Improve_Int32(arr_a);
	Array_Show_Int32(arr_a);

	Array_Destroy_Int32(&arr_a);

	gettimeofday(&end,NULL);
	usec = end.tv_usec - start.tv_usec;
	sec = end.tv_sec - start.tv_sec;
	usec = usec + 1000000*sec;
	printf("time used:%ld us\n",usec);
}


