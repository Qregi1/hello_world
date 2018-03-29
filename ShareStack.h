#pragma once

#include<stdio.h>


#define STACKMAXSIZE 1000
typedef char StackType;

/*����һ������ջ�Ľṹ*/
typedef struct {
	StackType data[STACKMAXSIZE];
	/*top1��top2�ֱ�������ջ��ջ��*/
	int top1;
	int top2;
}ShareStack;

/*��ʼ������ջ*/
void ShareStackInit(ShareStack* stack);
/*��ջ��ѹ��Ԫ��*/
void ShareStackPush(ShareStack* stack, StackType value, int StackNum);
/*��ջһ��Ԫ��*/
void ShareStackPop(ShareStack* stack, int StackNum);
/*��ӡջ*/
void PrintStack(ShareStack* stack, int StackNum, char* msg);
/*ȡջ��Ԫ��*/
StackType ShareStackGetTopValue(ShareStack* stack, int StackNUm);
/*����ջ*/
void ShareStackDestory(ShareStack* stack, int StackNum);