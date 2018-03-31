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

/*����һ���յ�ѭ������q*/
Status SeqQueue_Init( SeqQueue ** Q ,int len );
/*�������*/
Status SeqQueue_AddQuNode( SeqQueue * Q , QuNode * p );
/*�ж϶����Ƿ�Ϊ�գ����򷵻�OK�����򷵻�ERROR*/
Status SeqQueue_Empty( SeqQueue * Q);
/*�жϽ���Ƿ��ڶ�����,�Ƿ���OK�����򷵻�ERROR*/
Status SeqQueue_NodeIsInQueue( SeqQueue * Q , QuNode * p );
/*�õ����г���*/
int SeqQueue_Length( SeqQueue * Q );
/*�õ���ͷԪ��*/
QuNode * SeqQueue_GetHead( SeqQueue * Q );
/*���ٶ���*/
Status SeqQueue_Destory( SeqQueue ** Q );
/*���ζԶ����е�Ԫ�ص���visit����*/
Status SeqQueue_Traverse( SeqQueue * Q , Status (* visit)(QuNode * p));
/*��ѭ��������ɾ����ͷԪ��*/
Status SeqQueue_RemoveQuNode( SeqQueue * Q );

#endif

