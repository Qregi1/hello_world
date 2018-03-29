#pragma once
 

#include<stdio.h>
#include<stddef.h>

typedef char DLinkType;

//双向链表
typedef struct DLinkNode {

	DLinkType data;
	struct DLinkNode* _next;
	struct DLinkNode* _prev;

}DLinkNode;
//
//typedef struct DLinkList{
//
//	struct DLinkNode head;
//	struct DLinkNode tail;
//	size_t size;
//
//}DLinkList;

//创建结点
DLinkNode* CreatNewNode(DLinkType data);
//初始化
void DLinkListInit(DLinkNode** head);
//尾插一个元素
DLinkNode* DLinkListPushBack(DLinkNode* head, DLinkType value);
//打印双向链表
void PrintDLinkNode(DLinkNode* head, const char* msg);
//释放某个结点的地址空间
void DestoyNode(DLinkNode* node);
//尾删一个元素
void DLinkListPopBack(DLinkNode* head);
//头插一个元素
void DLinkListPushFront(DLinkNode* head, DLinkType value);
//头删一个元素
void DLinkListPopFront(DLinkNode* head);
//查找一个元素
DLinkNode* DLinkListFind(DLinkNode* head, DLinkType to_find);
//往指定位置之前插入一个元素
void DLinkListInsert(DLinkNode* pos, DLinkType value);
//往指定位置之后插入一个元素
void DLinkListInsertAfter(DLinkNode* pos, DLinkType value);
//删除指定位置的元素
void DLinkListErase(DLinkNode* pos);
//删除指定值的元素
void DLinkListRemove(DLinkNode* head, DLinkType value);
//求出链表的长度
size_t DLinkListSize(DLinkNode* head);
//删除所有链表中指定值得元素
void DLinkLisrRemoveAll(DLinkNode** head,DLinkType to_delete);
//判断链表是否为空
int DLinkListEmpty(DLinkNode* head);