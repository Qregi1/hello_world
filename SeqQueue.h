#pragma once

#include<stdio.h>

struct BinTreeNode;
typedef struct BinTreeNode* QueueType;

#define QUEUEMAXSIZE 1000

//һ�����еĽṹ��
typedef struct Queue{
	QueueType data[QUEUEMAXSIZE];
	int head;
	int tail;
}Queue;

//��ʼ��
void QueueInit(Queue* que);
//�����һ��Ԫ��
void QueuePush(Queue* que, QueueType value);
//������һ��Ԫ��
void QueuePop(Queue* que);
//ȡ����Ԫ��
QueueType QueueHeadValue(Queue* que);
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* que);
//���ٶ���
void QueueDestory(Queue* que);