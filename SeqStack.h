#pragma once

#include<stdio.h>
#include"BinTree.h"
#include<stddef.h>

struct BinTreeNode;

typedef struct BinTreeNode* StackType;

#define STACKMAXSIZE 1000

typedef struct SeqStack{
	StackType data[STACKMAXSIZE];
	int top;
	int bottom;
	size_t size;
}SeqStack;

//��ʼ��
void SeqStackInit(SeqStack* st);
//��ջ
void SeqStackPush(SeqStack* st, StackType value);
//��ջ
void SeqStackPop(SeqStack* st);
//ȡ��ջ��Ԫ��
StackType SeqStackTopValue(SeqStack* st);
//����ջ
void SeqStackDestory(SeqStack* st);
//�ж�ջ�Ƿ�Ϊ��
int SeqStackIsEmpty(SeqStack* st);