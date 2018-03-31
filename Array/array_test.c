#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "array.h"

int main(int ac, char *av[])
{
	Array * arr_a = NULL;

	Array_Init(&arr_a,5);

	Array_Assign(arr_a,0,15);
	Array_Show(arr_a);

	Array_Assign(arr_a,1,14);
	Array_Show(arr_a);

	Array_Assign(arr_a,2,13);
	Array_Show(arr_a);

	Array_Assign(arr_a,3,12);
	Array_Show(arr_a);

	Array_Assign(arr_a,4,11);
	Array_Show(arr_a);

	Array_InsertSort(arr_a);
	Array_Show(arr_a);

	Array_Destroy(&arr_a);
}


