#include <stdio.h>
#include <memory.h>
#include "LinkList.h"
#include "common_cont.h"

typedef struct _user_item{
	int freq;
	int pci;
}user_item;

typedef struct _list_item{
	user_item item;
	LNode lnode;
}list_item;

static Status ShowItem(LNode * p)
{	
	list_item * item;
	item = c_cont(p,list_item,lnode);
	printf("freq : %5d pci : %3d \n",item->item.freq,item->item.pci);
	return OK;
}

int main(int ac, char *av[])
{
	LinkList * linklist = NULL;
	LinkList * linklist_b = NULL;
	//list_item item[4] = {{0},{0},{0},{0}};
	list_item item[4];
	memset(&item,0,4*sizeof(list_item));
	list_item item_b[2];
	memset(&item_b,0,2*sizeof(list_item));

	printf("\nLinked list A init.\n");
	LinkList_InitList(&linklist);
	
	item[0].item.freq = 37900;
	item[0].item.pci = 220;
	printf("\nAdd freq 37900 pci 220 to linked list A.\n");
	LinkList_AddNodeTail(linklist,&item[0].lnode);
	LinkList_Traverse(linklist,ShowItem);

	item[1].item.freq = 38400;
	item[1].item.pci = 221;
	printf("\nAdd freq 38400 pci 221 to linked list A.\n");
	LinkList_AddNodeTail(linklist,&item[1].lnode);
	LinkList_Traverse(linklist,ShowItem);
	
	item[2].item.freq = 38544;
	item[2].item.pci = 222;
	printf("\nInsert freq 38544 pci 222 before freq 38400 pci 221.\n");
	LinkList_InsBefore(linklist,&item[1].lnode,&item[2].lnode);
	LinkList_Traverse(linklist,ShowItem);

	item[3].item.freq = 39148;
	item[3].item.pci = 223;
	printf("\nInsert freq 39148 pci 223 after freq 38400 pci 222.\n");
	LinkList_InsAfter(linklist,&item[1].lnode,&item[3].lnode);
	LinkList_Traverse(linklist,ShowItem);

	LinkList_InitList(&linklist_b);
	item_b[0].item.freq = 450;
	item_b[0].item.pci= 225;
	LinkList_AddNodeTail(linklist_b,&item_b[0].lnode);
	item_b[1].item.freq = 1650;
	item_b[1].item.pci= 226;
	LinkList_AddNodeTail(linklist_b,&item_b[1].lnode);
	printf("\nLinked list B is:\n");
	LinkList_Traverse(linklist_b,ShowItem);


	printf("\nAppend list B to list A:\n");
	LinkList_Append(linklist,linklist_b->head);
	LinkList_Traverse(linklist,ShowItem);
	
	printf("\nGet the last node in list A and remove it.\n");
	LinkList_RemoveNode(linklist,LinkList_GetLast(linklist));
	LinkList_Traverse(linklist,ShowItem);

	printf("\nGet the first node in list A and remove it.\n");
	LinkList_RemoveNode(linklist,LinkList_GetHead(linklist));
	LinkList_Traverse(linklist,ShowItem);

	printf("\nDestory linked list.\n");
	LinkList_DestoryList(&linklist);
	LinkList_DestoryList(&linklist_b);
	return 0;
}



