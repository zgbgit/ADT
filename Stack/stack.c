#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "Stack.h"

Status Stack_Push(Stack * s , ElemType e)
{
	Status ret;
	LNode * p_tmp = NULL;
	
	ret = LinkList_MakeNode(&p_tmp,e);
	ret = LinkList_AddNodeTail(s,p_tmp);

	return ret;
}

Status Stack_Pop(Stack * s , ElemType * e)
{
	Status ret;
	LNode * p_tmp = NULL;

	p_tmp = LinkList_GetLast(s);
	if(p_tmp != NULL)
	{
		memcpy(e, p_tmp, sizeof(ElemType));
	}
	
	ret = LinkList_RemoveNode(s,p_tmp);

	return ret;
}

Status Stack_Traverse( Stack * s , Status (* visit)(SNode * p))
{
	SNode * p_tmp = NULL;

	if( NULL == s)
	{
		printf("[ERR]: Traverse err.\n");
		return ERROR;
	}

	p_tmp = s->head;
	while(p_tmp != NULL)
	{
		(* visit)(p_tmp);
		p_tmp = p_tmp->next;
	}
	
	return OK;
}


