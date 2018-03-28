#include <stdio.h>
#include "LinkList.h"

static Status ShowItem(LNode * p)
{
	printf("freq : %5d pci : %3d \n",p->data.freq,p->data.pci);
	return OK;
}

int main(int ac, char *av[])
{
	LinkList * linklist = NULL;
	LinkList * linklist_b = NULL;
	ElemType item;
	LNode * p = NULL;
	LNode * q = NULL;
	LNode * k = NULL;

	printf("\nLinked list init.\n");
	LinkList_InitList(&linklist);
	item.freq = 37900;
	item.pci = 220;
	LinkList_MakeNode(&p,item);

	printf("\nAdd freq 37900 pci 220 to linked list.\n");
	LinkList_AddNodeTail(linklist,p);
	LinkList_Traverse(linklist,ShowItem);

	item.freq = 37900;
	item.pci = 221;
	LinkList_MakeNode(&p,item);
	printf("\nAdd freq 37900 pci 221 to linked list.\n");
	LinkList_AddNodeTail(linklist,p);
	LinkList_Traverse(linklist,ShowItem);
	
	item.freq = 38400;
	item.pci = 222;
	LinkList_MakeNode(&q,item);
	printf("\nInsert freq 38400 pci 222 before freq 37900 pci 221.\n");
	LinkList_InsBefore(linklist,p,q);
	LinkList_Traverse(linklist,ShowItem);

	item.freq = 39148;
	item.pci = 223;
	LinkList_MakeNode(&k,item);
	printf("\nInsert freq 39148 pci 223 after freq 38400 pci 222.\n");
	LinkList_InsAfter(linklist,q,k);
	LinkList_Traverse(linklist,ShowItem);

	item.freq = 38950;
	item.pci = 224;
	printf("\nSet current node freq 39148 pci 223 to freq 38950 pci 224.\n");
	LinkList_SetCurElem(k,item);
	LinkList_Traverse(linklist,ShowItem);


	LinkList_InitList(&linklist_b);
	item.freq = 450;
	item.pci = 225;
	LinkList_MakeNode(&p,item);
	LinkList_AddNodeTail(linklist_b,p);
	item.freq = 1650;
	item.pci = 226;
	LinkList_MakeNode(&q,item);
	LinkList_AddNodeTail(linklist_b,q);
	printf("\nLinked list B is:\n");
	LinkList_Traverse(linklist_b,ShowItem);

	printf("\nAppend list B to list A:\n");
	LinkList_Append(linklist,linklist_b->head);
	LinkList_Traverse(linklist,ShowItem);
	
	item.freq = LinkList_GetCurElem(p).freq;
	item.pci = LinkList_GetCurElem(p).pci;
	printf("\nGet item.freq %d item.pci %d \n",item.freq,item.pci);

	printf("\nGet the last node in list A and remove it.\n");
	p = LinkList_GetLast(linklist);
	LinkList_RemoveNode(linklist,p);
	LinkList_Traverse(linklist,ShowItem);

	printf("\nGet the first node in list A and remove it.\n");
	p = LinkList_GetHead(linklist);
	LinkList_RemoveNode(linklist,p);
	LinkList_Traverse(linklist,ShowItem);

	printf("\nDestory linked list.\n");
	LinkList_DestoryList(&linklist);
	return 0;
}



