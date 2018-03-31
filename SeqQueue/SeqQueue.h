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

/*构造一个空的循环队列q*/
Status SeqQueue_Init( SeqQueue ** Q ,int len );
/*新增结点*/
Status SeqQueue_AddQuNode( SeqQueue * Q , QuNode * p );
/*判断队列是否为空，是则返回OK，否则返回ERROR*/
Status SeqQueue_Empty( SeqQueue * Q);
/*判断结点是否在队列中,是返回OK，否则返回ERROR*/
Status SeqQueue_NodeIsInQueue( SeqQueue * Q , QuNode * p );
/*得到队列长度*/
int SeqQueue_Length( SeqQueue * Q );
/*得到队头元素*/
QuNode * SeqQueue_GetHead( SeqQueue * Q );
/*销毁队列*/
Status SeqQueue_Destory( SeqQueue ** Q );
/*依次对队列中的元素调用visit函数*/
Status SeqQueue_Traverse( SeqQueue * Q , Status (* visit)(QuNode * p));
/*从循环队列中删除队头元素*/
Status SeqQueue_RemoveQuNode( SeqQueue * Q );

#endif

