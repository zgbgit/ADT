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

typedef struct _LNode{	/*�ڵ�����*/
	ElemType	data;
	struct _LNode * next;
}LNode;

typedef struct {
	LNode * head;
	LNode * tail;		/*�ֱ�ָ�����������е�ͷ�������һ���ڵ�*/
	int len;			/*ָʾ�������������ݵĸ���*/
}LinkList;

/*������pָ���ֵΪe�Ľڵ㣬������OK��������ʧ�ܣ��򷵻�ERROR*/
Status LinkList_MakeNode( LNode ** p, ElemType e );
/*�ͷ�p��ָ��Ľ��*/
void LinkList_FreeNode( LNode * p);
/*����һ���յ���������L*/
Status LinkList_InitList( LinkList ** L );
/*������������L*/
Status LinkList_DestoryList( LinkList ** L );
/*����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�*/
Status LinkList_ClearList( LinkList * L );
/*��������L��Ԫ�ظ���*/
int LinkList_ListLength( LinkList * L );
/*������������L��ͷ���λ��*/
LNode * LinkList_GetHead( LinkList * L );
/*�����������������һ�����λ��*/
LNode * LinkList_GetLast( LinkList * L );
/*ɾ����������L�н��p*/
Status LinkList_RemoveNode( LinkList * L , LNode * p );
/*��������L��p��ָ����ֱ��ǰ��λ�ã�����ǰ��������NULL*/
LNode * LinkList_PriorPos( LinkList * L , LNode * p );
/*��������L��p��ָ����ֱ��ǰ���λ�ã����޺�̣�����NULL*/
LNode * LinkList_NextPos( LinkList * L , LNode * p );
/*���p��ָ����Ƿ�����������L�У��Ƿ���OK�����Ƿ���ERROR*/
Status LinkList_NodeIsInList( LinkList * L , LNode * p );
/*����������Ľ�β����p��ָ��Ľ��*/
Status LinkList_AddNodeTail( LinkList * L , LNode * p );
/*���ζ���������L�е�ÿ��Ԫ�ص��ú���visit*/
Status LinkList_Traverse( LinkList * L , Status (* visit)(LNode * p));
/*��֪pָ�����������ͷ��ɾ����ͷ���*/
Status LinkList_DelFirst( LinkList * L , LNode * p );
/*��֪pָ�����������β��㣬ɾ����β���*/
Status LinkList_InsFirst( LinkList * L ,LNode * h );
/*������������p֮ǰ������s*/
Status LinkList_InsBefore( LinkList * L , LNode * p , LNode * s);
/*������������p֮�������s*/
Status LinkList_InsAfter( LinkList * L , LNode * p , LNode * s);
/*���½��p��ֵΪe*/
Status LinkList_SetCurElem( LNode * p ,ElemType e);
/*����p��ָ���������Ԫ��ֵ*/
ElemType LinkList_GetCurElem( LNode * p );
/*���Ա�Ϊ�գ�����OK�����򷵻�ERROR*/
Status LinkList_ListEmpty( LinkList * L );
/*��ָ��p��ָ���һ�������������������L�����һ�����֮��*/
Status LinkList_Append( LinkList * L , LNode * p );



#endif
