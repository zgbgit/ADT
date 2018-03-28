#ifndef _STACK_H
#define _STACK_H
#include "LinkList.h"

/*将堆栈作为链表实现*/  
typedef LinkList Stack;
typedef LNode SNode;


/*将Stack_InitStack 定义成LinkList_InitList，栈通过Stack_InitStack初始化*/  
#define Stack_InitStack 	LinkList_InitList  
/*将Stack_Destroy定义成LinkList_DestoryList，栈通过Stack_Destroy销毁*/ 
#define Stack_Destroy 		LinkList_DestoryList 
/*宏，获取栈顶元素数据*/
#define Stack_Peek(Stack)	((Stack->head) == NULL ? NULL : (Stack)->head->data)  
/*宏，获取栈的大小*/ 
#define Stack_Size 			LinkList_ListLength                                                  

/*在栈中插入元素e*/
Status Stack_Push(Stack * s , ElemType e);
/*若栈不为空，删除栈顶元素，用e返回其值，并返回OK，否则返回ERROR*/
Status Stack_Pop(Stack * s , ElemType * e);
/*依次对栈s中的每个元素调用函数visit*/
Status Stack_Traverse( Stack * s , Status (* visit)(SNode * p));


#endif

