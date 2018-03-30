
#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef char DLinkType;

//C语言双向链表

typedef struct DLinkNode{

	 DLinkType data;
	 struct DLinkNode* _next;
	 struct DLinkNode* _prev;

}DLinkNode;

typedef struct DLinkList{

	DLinkNode* head;
	DLinkNode* tail;
	int size;

}DLinkList;

//创建一个结点
DLinkNode* CreatNewNode(DLinkType value);
//释放一个结点
void DestoryNode(DLinkNode** node);
//初始化双向链表
DLinkList* InitDLinkList();
//判断链表是否为空
int DLinkListEmpty(DLinkList* plist);
//尾插一个元素
DLinkList* DLinkListPushBack(DLinkList* plist, DLinkType value);
//打印整个链表
void PrintChar(DLinkList* plist, char* msg);
//尾删一个元素
void DLinkListPopBack(DLinkList* plist);
//头插一个元素
void DLinkListPushFront(DLinkList* plist, DLinkType value);
//头删一个元素
void DLinkListPopFront(DLinkList* plist);
//查找某个元素
DLinkNode* DLinkListFind(DLinkList* plist, DLinkType to_find);
//往指定位置之前插入一个元素
void DLinkListInsert(DLinkList* plist,DLinkNode* pos, DLinkType value);
//往指定位置之后插入一个元素
void DLinkListInsertAfter(DLinkList* plist, DLinkNode* pos, DLinkType value);
//删除指定位置的元素
void DLinkListErase(DLinkList* plist, DLinkNode* pos);
//删除指定值的元素
void DLinkListRemove(DLinkList* plist, DLinkType to_delete);
//删除所有指定值的元素
void DLinkListRemoveAll(DLinkList* plist, DLinkType to_delete);

//删除一个链表的所有元素
void DLinkListClear(DLinkList* plist);