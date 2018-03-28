#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct _ElemType{
	int freq;
	int pci;
}ElemType;

typedef enum {
	OK,
	ERROR,
	INFEASIBLE,
	OVERFLOW
}Status;

typedef struct _LNode{	/*节点类型*/
	ElemType	data;
	struct _LNode * next;
}LNode;

typedef struct {
	LNode * head;
	LNode * tail;		/*分别指向线性链表中的头结点和最后一个节点*/
	int len;			/*指示线性链表中数据的个数*/
}LinkList;

/*分配由p指向的值为e的节点，并返回OK；若分配失败，则返回ERROR*/
Status LinkList_MakeNode( LNode ** p, ElemType e );
/*释放p所指向的结点*/
void LinkList_FreeNode( LNode * p);
/*构造一个空的线性链表L*/
Status LinkList_InitList( LinkList ** L );
/*销毁线性链表L*/
Status LinkList_DestoryList( LinkList ** L );
/*将线性链表L重置为空表，并释放原链表的结点空间*/
Status LinkList_ClearList( LinkList * L );
/*线性链表L中元素个数*/
int LinkList_ListLength( LinkList * L );
/*返回线性链表L中头结点位置*/
LNode * LinkList_GetHead( LinkList * L );
/*返回线性链表中最后一个结点位置*/
LNode * LinkList_GetLast( LinkList * L );
/*删除线性链表L中结点p*/
Status LinkList_RemoveNode( LinkList * L , LNode * p );
/*线性链表L中p所指结点的直接前驱位置，若无前驱，返回NULL*/
LNode * LinkList_PriorPos( LinkList * L , LNode * p );
/*线性链表L中p所指结点的直接前后继位置，若无后继，返回NULL*/
LNode * LinkList_NextPos( LinkList * L , LNode * p );
/*检查p所指结点是否在线性链表L中，是返回OK，不是返回ERROR*/
Status LinkList_NodeIsInList( LinkList * L , LNode * p );
/*在线性链表的结尾加上p所指向的结点*/
Status LinkList_AddNodeTail( LinkList * L , LNode * p );
/*依次对线性链表L中的每个元素调用函数visit*/
Status LinkList_Traverse( LinkList * L , Status (* visit)(LNode * p));
/*已知p指向线性链表的头，删除此头结点*/
Status LinkList_DelFirst( LinkList * L , LNode * p );
/*已知p指向线性链表的尾结点，删除此尾结点*/
Status LinkList_InsFirst( LinkList * L ,LNode * h );
/*在线性链表结点p之前插入结点s*/
Status LinkList_InsBefore( LinkList * L , LNode * p , LNode * s);
/*在线性链表结点p之后插入结点s*/
Status LinkList_InsAfter( LinkList * L , LNode * p , LNode * s);
/*更新结点p的值为e*/
Status LinkList_SetCurElem( LNode * p ,ElemType e);
/*返回p所指结点中数据元素值*/
ElemType LinkList_GetCurElem( LNode * p );
/*线性表为空，返回OK，否则返回ERROR*/
Status LinkList_ListEmpty( LinkList * L );
/*将指针p所指向的一串结点链接在线性链表L的最后一个结点之后*/
Status LinkList_Append( LinkList * L , LNode * p );



#endif
