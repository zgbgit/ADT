#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H

#include "LinkList.h"
#include "err.h"

typedef LNode QuNode;

typedef struct _SeqQueue{
	QuNode * head;
	QuNode * tail;
	int queue_len;
	int index;
}SeqQueue;

/*ѭ������Ϊ�գ�����OK�����򷵻�ERROR*/
Status SeqQueue_Empty( SeqQueue * q);

/*����һ���յ�ѭ������q*/
Status SeqQueue_Init( SeqQueue ** Q ,int len );

Status SeqQueue_AddQuNode( SeqQueue * Q , QuNode * p );

Status SeqQueue_Empty( SeqQueue * Q);

Status SeqQueue_NodeIsInQueue( SeqQueue * Q , QuNode * p );

int SeqQueue_Length( SeqQueue * Q );

QuNode * SeqQueue_GetHead( SeqQueue * Q );

Status SeqQueue_GetNodeIndex(SeqQueue * Q);

Status SeqQueue_Destory( SeqQueue ** Q );

Status SeqQueue_Traverse( SeqQueue * Q , Status (* visit)(QuNode * p));


#endif

