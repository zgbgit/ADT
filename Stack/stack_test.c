#include <stdio.h>
#include "stack.h"

static Status ShowItem(SNode * p)
{
	printf("freq : %5d pci : %3d \n",p->data.freq,p->data.pci);
	return OK;
}

int main(int ac, char *av[])
{
	LinkList * stack_a = NULL;
	ElemType item = {0};

	printf("\nStack init.\n");
	Stack_InitStack(&stack_a);

	printf("\nPush freq 37900 pci 220 to stack.\n");
	item.freq = 37900;
	item.pci = 220;
	Stack_Push(stack_a,item);
	Stack_Traverse(stack_a,ShowItem);


	printf("\nPush freq 37900 pci 221 to stack.\n");
	item.freq = 37900;
	item.pci = 221;
	Stack_Push(stack_a,item);
	Stack_Traverse(stack_a,ShowItem);

	printf("\nPush freq 38400 pci 222 to stack.\n");
	item.freq = 38400;
	item.pci = 222;
	Stack_Push(stack_a,item);
	Stack_Traverse(stack_a,ShowItem);

	Stack_Pop(stack_a,&item);
	printf("\nPop freq %d pci %d.\n",item.freq,item.pci);
	Stack_Traverse(stack_a,ShowItem);
	
	Stack_Pop(stack_a,&item);
	printf("\nPop freq %d pci %d.\n",item.freq,item.pci);
	Stack_Traverse(stack_a,ShowItem);
	
	Stack_Pop(stack_a,&item);
	printf("\nPop freq %d pci %d.\n",item.freq,item.pci);
	Stack_Traverse(stack_a,ShowItem);

	Stack_Pop(stack_a,&item);
	printf("\nPop freq %d pci %d.\n",item.freq,item.pci);
	Stack_Traverse(stack_a,ShowItem);

	printf("\nDestory stack.\n");
	Stack_Destroy(&stack_a);
	return 0;
}



