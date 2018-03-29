#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "Stack.h"

Status Stack_Push(Stack * s , SNode * sn)
{
	Status ret;
	
	ret = LinkList_AddNodeTail(s,sn);

	return ret;
}

Status Stack_Pop(Stack * s , SNode ** sn)
{
	Status ret;

	*sn = LinkList_GetLast(s);
	
	ret = LinkList_RemoveNode(s,*sn);

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


