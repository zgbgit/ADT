#ifndef _STACK_H
#define _STACK_H
#include "LinkList.h"

/*����ջ��Ϊ����ʵ��*/  
typedef LinkList Stack;
typedef LNode SNode;


/*��Stack_InitStack �����LinkList_InitList��ջͨ��Stack_InitStack��ʼ��*/  
#define Stack_InitStack 	LinkList_InitList  
/*��Stack_Destroy�����LinkList_DestoryList��ջͨ��Stack_Destroy����*/ 
#define Stack_Destroy 		LinkList_DestoryList 
/*�꣬��ȡջ��Ԫ������*/
#define Stack_Peek(Stack)	((Stack->head) == NULL ? NULL : (Stack)->head->data)  
/*�꣬��ȡջ�Ĵ�С*/ 
#define Stack_Size 			LinkList_ListLength                                                  

/*��ջ�в���Ԫ��e*/
Status Stack_Push(Stack * s , ElemType e);
/*��ջ��Ϊ�գ�ɾ��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR*/
Status Stack_Pop(Stack * s , ElemType * e);
/*���ζ�ջs�е�ÿ��Ԫ�ص��ú���visit*/
Status Stack_Traverse( Stack * s , Status (* visit)(SNode * p));


#endif

