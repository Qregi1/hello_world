#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqStack.h"
#include<stdio.h>
#include<stdlib.h>

//初始化
void SeqStackInit(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	st->top = 0;
	st->bottom = 0;
	st->size = 0;
}

//入栈
void SeqStackPush(SeqStack* st, StackType value) {
	if (st == NULL) {
		return;
	}
	if (st->size == STACKMAXSIZE) {
		printf("栈已经满了!\n");
		return;
	}
	//数组中0的位置不存储元素，所以top就等于size
	st->data[++st->top] = value;
	++st->size;
}

//出栈
void SeqStackPop(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	if (st->top == st->bottom) {
		printf("栈为空!\n");
		return;
	}
	--st->top;
	--st->size;
}

//取出栈顶元素
StackType SeqStackTopValue(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	if (st->top == st->bottom) {
		printf("栈为空!\n");
	}
	else {
		return st->data[st->top];
	}
}

//销毁栈
void SeqStackDestory(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	st->top = st->bottom;
	st->size = 0;
}
//判断栈是否为空
int SeqStackIsEmpty(SeqStack* st) {
	if (st == NULL) {
		return 1;
	}
	if (st->top == st->bottom) {
		return  1;
	}
	else {
		return 0;
	}
}


///////////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////////
#if 0
#define TESTHEAD printf("---------------%s---------------\n",__FUNCTION__)

void Test() {
	SeqStack st;
	TESTHEAD;
	SeqStackInit(&st);
	//测试入栈
	SeqStackPush(&st, 'e');
	SeqStackPush(&st, 'd');
	SeqStackPush(&st, 'c');
	SeqStackPush(&st, 'b');
	SeqStackPush(&st, 'a');

	//测试出栈
	SeqStackPop(&st);
	//测试取栈顶元素
	char ch = SeqStackTopValue(&st);
	printf("expect b, actual:%c\n",ch);
	//测试判断栈空
	SeqStackPop(&st);
	SeqStackPop(&st);
	SeqStackPop(&st);
	int t = SeqStackIsEmpty(&st);
	printf("expect 0, actual:%d\n", t);
	SeqStackPop(&st);
	t = SeqStackIsEmpty(&st);
	printf("expect 1, actual:%d\n", t);
	//测试销毁栈
	SeqStackPush(&st, 'a');
	SeqStackDestory(&st);
	t = SeqStackIsEmpty(&st);
	printf("expect 1, actual:%d\n", t);
}

int main() {
	Test();
	system("pause");
	return 0;
}
#endif