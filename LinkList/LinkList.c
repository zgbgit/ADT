#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "LinkList.h"

Status LinkList_MakeNode( LNode ** p, ElemType e )
{
	LNode * p_tmp = NULL;
	
	p_tmp = (LNode *)malloc(sizeof(LNode));
	if(NULL == p_tmp)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	memcpy(&p_tmp->data, &e, sizeof(ElemType));
	p_tmp->next = NULL;
	*p = p_tmp;

	return OK;
}

Status LinkList_SetCurElem( LNode * p ,ElemType e)
{
	if(NULL == p)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	memcpy(&p->data, &e, sizeof(ElemType));

	return OK;
}

ElemType LinkList_GetCurElem( LNode * p )
{
	ElemType e = {0};

	if(NULL == p)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return e;
	}

	memcpy(&e, &p->data, sizeof(ElemType));
	return e;
}

void LinkList_FreeNode( LNode * p)
{
	free(p);
}

Status LinkList_InitList( LinkList ** L )
{
	LinkList * L_tmp = NULL;
	
	L_tmp = (LinkList *)malloc(sizeof(LinkList));
	if(NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	L_tmp->tail = NULL;
	L_tmp->head = L_tmp->tail;
	L_tmp->len = 0;

	*L = L_tmp;
	return OK;
}

Status LinkList_DestoryList( LinkList ** L )
{
	if(NULL == *L || NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	LinkList_ClearList(*L);
	free(*L);
	*L = NULL;

	return OK;
}

Status LinkList_ClearList( LinkList * L )
{
	if(NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	while(LinkList_ListLength(L) > 0)
	{
		LinkList_RemoveNode(L,LinkList_GetHead(L));
	}

	return OK;
}

int LinkList_ListLength( LinkList * L )
{
	int len = 0;
	LNode * p_tmp = NULL;

	p_tmp = LinkList_GetHead(L);

	while(p_tmp != NULL)
	{
		p_tmp = p_tmp->next;
		len++;
	}
	return len;
}

LNode * LinkList_GetHead( LinkList * L )
{
	if(NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return NULL;
	}
	
	return L->head;
}

LNode * LinkList_GetLast( LinkList * L )
{
	if(NULL == L)
	{
		return NULL;
	}
	
	return L->tail;
}

Status LinkList_DelFirst( LinkList * L , LNode * p )
{
	if(NULL == p || NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(L->head == L->tail)
	{
		L->tail = p->next;
	}
	L->head = p->next;
	L->len = LinkList_ListLength(L);
	LinkList_FreeNode(p);
	return OK;
}

Status LinkList_RemoveNode( LinkList * L , LNode * p )
{
	LNode * p_prior = NULL;
	LNode * p_next = NULL;
	
	if(NULL == p || NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(p == L->head)
	{
		LinkList_DelFirst(L,p);
		return OK;
	}

	p_prior = LinkList_PriorPos(L,p);
	p_next = LinkList_NextPos(L,p);
	p_prior->next = p_next;
	if(NULL == p_next)
	{
		L->tail = p_prior;
	}
	L->len = LinkList_ListLength(L);
	LinkList_FreeNode(p);

	return OK;
}

Status LinkList_InsBefore( LinkList * L , LNode * p , LNode * s)
{
	LNode * p_before = NULL;
	
	if(NULL == p || NULL == L || NULL == s)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(OK == LinkList_NodeIsInList(L,s))
	{
		return ERROR;
	}
	
	if(p == L->head )
	{
		LinkList_InsFirst(L,s);		
	}

	p_before = LinkList_PriorPos(L,p);
	p_before->next = s;
	s->next = p;
	L->len = LinkList_ListLength(L);
	
	return OK;
}

Status LinkList_InsAfter( LinkList * L , LNode * p , LNode * s)
{
	LNode * p_after = NULL;
	
	if(NULL == p || NULL == L || NULL == s)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(OK == LinkList_NodeIsInList(L,s))
	{
		return ERROR;
	}
	
	if(p == L->tail)
	{
		LinkList_AddNodeTail(L,s);	

		return OK;
	}

	p_after = LinkList_NextPos(L,p);

	p->next = s;
	s->next = p_after;

	return OK;
}

LNode * LinkList_PriorPos( LinkList * L , LNode * p )
{
	LNode * p_tmp = NULL;

	if(NULL == p || NULL == L || p == L->head)
	{
		return NULL;
	}

	if(ERROR == LinkList_NodeIsInList(L,p))
	{
		return NULL;
	}
	p_tmp = L->head;

	while(p_tmp->next != NULL)
	{
		if(p_tmp->next == p)
		{
			return p_tmp;
		}
		p_tmp = p_tmp->next;
	}

	return NULL;
}

LNode * LinkList_NextPos( LinkList * L , LNode * p )
{
	if(NULL == p || NULL == L || p == L->head)
	{
		return NULL;
	}

	if(ERROR == LinkList_NodeIsInList(L,p))
	{
		return NULL;
	}

	return p->next;
}

Status LinkList_NodeIsInList( LinkList * L , LNode * p )
{
	LNode * p_tmp = L->head;
	LNode * p_tail = L->tail;

	if(NULL == p || NULL == L)
	{
		printf("[ERR]: Node is not in linked list.\n");
		return ERROR;
	}

	if(p_tmp == p)
	{
		return OK;
	}
	
	while(p_tmp != p_tail)
	{
		if(p_tmp->next == p)
		{
			return OK;
		}
		p_tmp = p_tmp->next;
	}

	return ERROR;
}

Status LinkList_AddNodeTail( LinkList * L , LNode * p )
{
	if(NULL == p || NULL == L)
	{
		printf("[ERR]: Add node err.\n");
		return ERROR;
	}

	if(OK == LinkList_ListEmpty(L))
	{
		L->head = p;
		L->tail = p;
		L->len = LinkList_ListLength(L);
		return OK;
	}

	if(OK == LinkList_NodeIsInList(L,p))
	{
		return ERROR;
	}

	L->tail->next = p;
	L->tail = p;
	L->len = LinkList_ListLength(L);

	return OK;
}

Status LinkList_InsFirst( LinkList * L ,LNode * h )
{
	if(NULL == h || NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(OK == LinkList_NodeIsInList(L,h))
	{
		return ERROR;
	}

	h->next = L->head;
	L->head = h;
	L->len = LinkList_ListLength(L);

	return OK;
}

Status LinkList_Traverse( LinkList * L , Status (* visit)(LNode * p))
{
	LNode * p_tmp = NULL;

	if( NULL == L)
	{
		printf("[ERR]: Traverse err.\n");
		return ERROR;
	}

	p_tmp = L->head;
	while(p_tmp != NULL)
	{
		(* visit)(p_tmp);
		p_tmp = p_tmp->next;
	}
	
	return OK;
}

Status LinkList_ListEmpty( LinkList * L )
{
	if(NULL == L)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(L->head == NULL && L->tail == NULL)
	{
		return OK;
	}

	return ERROR;
}

Status LinkList_Append( LinkList * L , LNode * p )
{
	LNode * p_tmp = NULL;
	LNode * p_tail = NULL;
	
	if(NULL == L || NULL == p)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	p_tmp = p;
	while(p_tmp != NULL)
	{
		if(OK == LinkList_NodeIsInList(L,p_tmp))
		{
			return ERROR;
		}
		p_tail = p_tmp;
		p_tmp = p_tmp->next;
		
	}

	if(OK == LinkList_ListEmpty(L))
	{
		L->head = p;
		L->tail = p_tail;
		L->len = LinkList_ListLength(L);
		return OK;
	}
	
	L->tail->next = p;
	L->tail = p_tail;
	L->len = LinkList_ListLength(L);

	return OK;
}


