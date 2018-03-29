#pragma once

#include<stdio.h>

typedef char LinkType;

typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

//初始化带头节点的单链表
void LinkNodeInit(LinkNode** head);
//尾插一个元素
LinkNode* LinkNodePushBack(LinkNode** head, LinkType value);
//尾删一个元素
void LinkNodePopBack(LinkNode** head);
/*打印链表*/
void PrintChar(LinkNode* head, char* msg);
//删除单链表的一个非尾结点
void LinkNodePopNode(LinkNode* pos);
//逆序打印单链表
void PrintLinkListReverse(LinkNode* head);
//在单链表一个非头节点之前插入一个元素,不允许遍历链表
void LinkNodeInsert(LinkNode* pos, LinkType value);
//单链表实现约瑟夫环问题
/*
**约瑟夫环，已知n个人围坐在一张桌子上，从编号为k的人开始报数，
数到m的那个人出列，他的下一个人又从1开始报数，数到m的人出列，
依次循环下去，知道圆桌的人全部出列
*/
LinkNode* JosephCycle(LinkNode* head, int k, int n);

//初始化一个无头节点的单链表
void InitWithJosephy(LinkNode** head);
//无头节点的单链表的尾插
LinkNode* PushBack(LinkNode** head, LinkType value);
//逆置反转无头节点的链表
void RevereseLinkList(LinkNode** head);
//打印无头节点的单链表
void PrintCharWithoutHead(LinkNode* head, char* msg);

//单链表排序（冒泡排序）
void LinkListBubbleSort(LinkNode* head);
//单链表排序（快速排序）
void QuickSort(LinkNode* left, LinkNode* right);

//合并两个单链表，合并后依然有序
LinkNode* Merge(LinkNode** head1, LinkNode** head2);
//合并两个链表（递归），合并后依然有序
LinkNode* MergeRecursive(LinkNode* head1, LinkNode* head2);
//查找链表的中间结点，要求只能遍历一次链表
LinkNode* FindMidNode(LinkNode* head);
//查找单链表的倒数第k个结点，要求只能遍历一次链表
LinkNode* FindKNode(LinkNode* head, int k);
//判断链表是否带环，若带环，求环的长度和相遇结点,不带环返回1
size_t CheckCycle(LinkNode* head, LinkNode** MeetNode);

/*求带环单链表的入口点
*两种方法
*1.第一种，定义两个指针，一个从相遇点开始走，
*一个从头开始走，第一次相遇点则为入口点
*
*2.从相遇点断开，则转化为两个单链表求交点
*/
LinkNode* FindEntryNode1(LinkNode* head);
LinkNode* FindEntryNode2(LinkNode* head);

/*
*判断两个链表相交
*1.两个链表都不带环
*  相交
*  不相交
*
*2.一个带环一个不带环
*  不可能相交
*
*3.两个都带环
*  相交在环外（可能在入口点，可能不在）
*  相交在环内（两个交点，两个链表环的入口点）
*/

int CheckCross(LinkNode* head1, LinkNode* head2, LinkNode** MeetNode);

/* 
*复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
*还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复
*制这个链表，返回复制后的新链表
*/

typedef struct ComplexeNode{
	LinkType data;
	struct ComplexeNode* _next;
	struct ComplexeNode* _random;
}ComplexeNode;

/*创建一个复杂链表的结点*/
ComplexeNode* CreatComplexeNode(LinkType data);
/*创建一个复杂链表*/
void CreatComplexeList(ComplexeNode** head);
/*打印一个复杂链表*/
void PrintComplexeList(ComplexeNode* head);
/*复杂链表的复制*/
ComplexeNode* CopyCompexeList(ComplexeNode* cplist);