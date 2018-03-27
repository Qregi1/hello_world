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

//初始化
void SeqStackInit(SeqStack* st);
//入栈
void SeqStackPush(SeqStack* st, StackType value);
//出栈
void SeqStackPop(SeqStack* st);
//取出栈顶元素
StackType SeqStackTopValue(SeqStack* st);
//销毁栈
void SeqStackDestory(SeqStack* st);
//判断栈是否为空
int SeqStackIsEmpty(SeqStack* st);