#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "SeqQueue.h"
#include "common_cont.h"

typedef struct _user_queue_item{
	int freq;
	int pci;
}user_queue_item;

typedef struct _queue_item{
	user_queue_item item;
	QuNode qnode;
}queue_item;

#define USER_QUEUE_LEN 3

static Status ShowItem(QuNode * p)
{	
	queue_item * item = NULL;
	item = c_cont(p,queue_item,qnode);
	printf("freq : %5d pci : %3d \n",item->item.freq,item->item.pci);
	return OK;
}

int main(int ac, char *av[])
{
	static queue_item item[USER_QUEUE_LEN];/*±ØÐëÊÇstatic*/
	memset(&item,0,USER_QUEUE_LEN*sizeof(queue_item));

	SeqQueue * queue_a = NULL;
	//user_queue_item user_item = {0};
	
	printf("\nSeqQueue init.\n");
	SeqQueue_Init(&queue_a,USER_QUEUE_LEN);

	item[queue_a->index].item.freq = 37900;
	item[queue_a->index].item.pci = 220;
	printf("\nSeqQueue add freq 37900 pci 220.\n");
	printf("index = %d\n",queue_a->index);
	SeqQueue_AddQuNode(queue_a,&item[queue_a->index].qnode);
	SeqQueue_Traverse(queue_a,ShowItem);

	item[queue_a->index].item.freq = 38400;
	item[queue_a->index].item.pci = 221;
	printf("\nSeqQueue add freq 38400 pci 221.\n");
	printf("index = %d\n",queue_a->index);
	SeqQueue_AddQuNode(queue_a,&item[queue_a->index].qnode);
	SeqQueue_Traverse(queue_a,ShowItem);

	item[queue_a->index].item.freq = 39148;
	item[queue_a->index].item.pci = 222;
	printf("\nSeqQueue add freq 39148 pci 222.\n");
	printf("index = %d\n",queue_a->index);
	SeqQueue_AddQuNode(queue_a,&item[queue_a->index].qnode);
	SeqQueue_Traverse(queue_a,ShowItem);

	item[queue_a->index].item.freq = 40936;
	item[queue_a->index].item.pci = 223;
	printf("\nSeqQueue add freq 40936 pci 223.\n");
	printf("index = %d\n",queue_a->index);
	SeqQueue_AddQuNode(queue_a,&item[queue_a->index].qnode);
	SeqQueue_Traverse(queue_a,ShowItem);

	c_assert_return (ERROR == SeqQueue_Empty(queue_a));
	printf("\nRemove ");
	ShowItem(SeqQueue_GetHead(queue_a));
	SeqQueue_RemoveQuNode(queue_a);
	SeqQueue_Traverse(queue_a,ShowItem);

	c_assert_return (ERROR == SeqQueue_Empty(queue_a));
	printf("\nRemove ");
	ShowItem(SeqQueue_GetHead(queue_a));
	SeqQueue_RemoveQuNode(queue_a);
	SeqQueue_Traverse(queue_a,ShowItem);

	c_assert_return (ERROR == SeqQueue_Empty(queue_a));
	printf("\nRemove ");
	ShowItem(SeqQueue_GetHead(queue_a));
	SeqQueue_RemoveQuNode(queue_a);
	SeqQueue_Traverse(queue_a,ShowItem);

	c_assert_return (ERROR == SeqQueue_Empty(queue_a));
	printf("\nRemove ");
	ShowItem(SeqQueue_GetHead(queue_a));
	SeqQueue_RemoveQuNode(queue_a);
	SeqQueue_Traverse(queue_a,ShowItem);

	SeqQueue_Destory(&queue_a);
}




