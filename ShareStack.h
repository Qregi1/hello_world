#pragma once

#include<stdio.h>


#define STACKMAXSIZE 1000
typedef char StackType;

/*定义一个共享栈的结构*/
typedef struct {
	StackType data[STACKMAXSIZE];
	/*top1和top2分别是两个栈的栈顶*/
	int top1;
	int top2;
}ShareStack;

/*初始化共享栈*/
void ShareStackInit(ShareStack* stack);
/*往栈里压入元素*/
void ShareStackPush(ShareStack* stack, StackType value, int StackNum);
/*出栈一个元素*/
void ShareStackPop(ShareStack* stack, int StackNum);
/*打印栈*/
void PrintStack(ShareStack* stack, int StackNum, char* msg);
/*取栈顶元素*/
StackType ShareStackGetTopValue(ShareStack* stack, int StackNUm);
/*销毁栈*/
void ShareStackDestory(ShareStack* stack, int StackNum);