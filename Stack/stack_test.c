#include <stdio.h>
#include <memory.h>
#include "stack.h"
#include "common_cont.h"
#include "err.h"

typedef struct _user_stack_item{
	int freq;
	int pci;
}user_stack_item;

typedef struct _stack_item{
	user_stack_item item;
	SNode snode;
}stack_item;

static Status ShowItem(SNode * p)
{	
	stack_item * item = NULL;
	item = c_cont(p,stack_item,snode);
	printf("freq : %5d pci : %3d \n",item->item.freq,item->item.pci);
	return OK;
}

int main(int ac, char *av[])
{
	LinkList * stack_a = NULL;
	SNode * s_tmp = NULL;
	stack_item item[4];
	stack_item * item_pop = NULL;
	memset(&item,0,4*sizeof(stack_item));

	printf("\nStack init.\n");
	Stack_InitStack(&stack_a);

	printf("\nPush freq 37900 pci 220 to stack.\n");
	item[0].item.freq = 37900;
	item[0].item.pci = 220;
	Stack_Push(stack_a,&item[0].snode);
	Stack_Traverse(stack_a,ShowItem);


	printf("\nPush freq 37900 pci 221 to stack.\n");
	item[1].item.freq = 37900;
	item[1].item.pci = 221;
	Stack_Push(stack_a,&item[1].snode);
	Stack_Traverse(stack_a,ShowItem);

	printf("\nPush freq 38400 pci 222 to stack.\n");
	item[2].item.freq = 38400;
	item[2].item.pci = 222;
	Stack_Push(stack_a,&item[2].snode);
	Stack_Traverse(stack_a,ShowItem);

	Stack_Pop(stack_a,&s_tmp);
	item_pop = c_cont(s_tmp,stack_item,snode);
	printf("\nPop freq %d pci %d.\n",item_pop->item.freq,item_pop->item.pci);
	Stack_Traverse(stack_a,ShowItem);

	c_assert_return (ERROR == Stack_Empty(stack_a));
	Stack_Pop(stack_a,&s_tmp);
	item_pop = c_cont(s_tmp,stack_item,snode);
	printf("\nPop freq %d pci %d.\n",item_pop->item.freq,item_pop->item.pci);
	Stack_Traverse(stack_a,ShowItem);

	c_assert_return (ERROR == Stack_Empty(stack_a));
	Stack_Pop(stack_a,&s_tmp);
	item_pop = c_cont(s_tmp,stack_item,snode);
	printf("\nPop freq %d pci %d.\n",item_pop->item.freq,item_pop->item.pci);
	Stack_Traverse(stack_a,ShowItem);

	c_assert_return (ERROR == Stack_Empty(stack_a));
	Stack_Pop(stack_a,&s_tmp);
	item_pop = c_cont(s_tmp,stack_item,snode);
	printf("\nPop freq %d pci %d.\n",item_pop->item.freq,item_pop->item.pci);
	Stack_Traverse(stack_a,ShowItem);

	printf("\nDestory stack.\n");
	Stack_Destroy(&stack_a);
	return 0;
}



