#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "SeqQueue.h"

Status SeqQueue_Init( SeqQueue ** Q ,int len )
{
	SeqQueue * q_tmp = NULL;
	
	q_tmp = (SeqQueue *)malloc(sizeof(SeqQueue));
	if(NULL == Q)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	q_tmp->tail = NULL;
	q_tmp->head = q_tmp->tail;
	q_tmp->queue_len = len;
	q_tmp->index = 0;

	*Q = q_tmp;
	return OK;
}

Status SeqQueue_AddQuNode( SeqQueue * Q , QuNode * p )
{
	QuNode * tmp_head = NULL;
	QuNode * tmp_tail = NULL;
	
	if(NULL == Q || NULL == p)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(OK == SeqQueue_Empty(Q))
	{
		Q->head = p;
		Q->tail = p;
		Q->index = (Q->index + 1)%(Q->queue_len);
		return OK;
	}

	if(OK == SeqQueue_NodeIsInQueue(Q,p))
	{
		return ERROR;
	}

	if(SeqQueue_Length(Q) >= Q->queue_len)
	{
		tmp_head = Q->head->next;
		tmp_tail = Q->head;
		Q->tail->next = Q->head;
		Q->head->next = NULL;
		Q->tail = tmp_tail;
		Q->head = tmp_head;
		Q->index = (Q->index + 1)%(Q->queue_len);
		return OK;
	}

	Q->tail->next = p;
	p->next = NULL;
	Q->tail = p;
	Q->index = (Q->index + 1)%(Q->queue_len);

	return OK;
}

Status SeqQueue_Empty( SeqQueue * Q)
{
	if(NULL == Q)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(Q->head == NULL && Q->tail == NULL)
	{
		return OK;
	}

	return ERROR;
}

Status SeqQueue_NodeIsInQueue( SeqQueue * Q , QuNode * p )
{
	QuNode * q_tmp = Q->head;
	QuNode * q_tail = Q->tail;

	if(unlikely(NULL == p || NULL == Q))
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	if(q_tmp == p)
	{
		return OK;
	}
	
	while(q_tmp != q_tail)
	{
		if(q_tmp->next == p)
		{
			return OK;
		}
		q_tmp = q_tmp->next;
	}

	return ERROR;
}

int SeqQueue_Length( SeqQueue * Q )
{
	int len = 0;
	QuNode * q_tmp = NULL;

	q_tmp = SeqQueue_GetHead(Q);

	while(q_tmp != NULL)
	{
		q_tmp = q_tmp->next;
		len++;
	}
	return len;
}

QuNode * SeqQueue_GetHead( SeqQueue * Q )
{
	if(unlikely(NULL == Q))
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return NULL;
	}
	
	return Q->head;
}

Status SeqQueue_GetNodeIndex(SeqQueue * Q)
{
	if(unlikely(NULL == Q))
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}

	return OK;
}

Status SeqQueue_Destory( SeqQueue ** Q )
{
	if(NULL == *Q || NULL == Q)
	{
		printf("[ERR]: %s %d\n",__func__,__LINE__);
		return ERROR;
	}
	free(*Q);
	*Q = NULL;

	return OK;
}

Status SeqQueue_Traverse( SeqQueue * Q , Status (* visit)(QuNode * p))
{
	QuNode * p_tmp = NULL;

	if( NULL == Q)
	{
		printf("[ERR]: Traverse err.\n");
		return ERROR;
	}

	p_tmp = Q->head;
	while(p_tmp != NULL)
	{
		(* visit)(p_tmp);
		p_tmp = p_tmp->next;
	}
	
	return OK;
}



