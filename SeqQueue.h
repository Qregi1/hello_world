#pragma once

#include<stdio.h>

struct BinTreeNode;
typedef struct BinTreeNode* QueueType;

#define QUEUEMAXSIZE 1000

//一个队列的结构体
typedef struct Queue{
	QueueType data[QUEUEMAXSIZE];
	int head;
	int tail;
}Queue;

//初始化
void QueueInit(Queue* que);
//入队列一个元素
void QueuePush(Queue* que, QueueType value);
//出队列一个元素
void QueuePop(Queue* que);
//取队首元素
QueueType QueueHeadValue(Queue* que);
//判断队列是否为空
int QueueEmpty(Queue* que);
//销毁队列
void QueueDestory(Queue* que);