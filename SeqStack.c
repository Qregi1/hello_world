#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqStack.h"
#include<stdio.h>
#include<stdlib.h>

//��ʼ��
void SeqStackInit(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	st->top = 0;
	st->bottom = 0;
	st->size = 0;
}

//��ջ
void SeqStackPush(SeqStack* st, StackType value) {
	if (st == NULL) {
		return;
	}
	if (st->size == STACKMAXSIZE) {
		printf("ջ�Ѿ�����!\n");
		return;
	}
	//������0��λ�ò��洢Ԫ�أ�����top�͵���size
	st->data[++st->top] = value;
	++st->size;
}

//��ջ
void SeqStackPop(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	if (st->top == st->bottom) {
		printf("ջΪ��!\n");
		return;
	}
	--st->top;
	--st->size;
}

//ȡ��ջ��Ԫ��
StackType SeqStackTopValue(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	if (st->top == st->bottom) {
		printf("ջΪ��!\n");
	}
	else {
		return st->data[st->top];
	}
}

//����ջ
void SeqStackDestory(SeqStack* st) {
	if (st == NULL) {
		return;
	}
	st->top = st->bottom;
	st->size = 0;
}
//�ж�ջ�Ƿ�Ϊ��
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
//����Ϊ���Դ���
///////////////////////////////////////////////
#if 0
#define TESTHEAD printf("---------------%s---------------\n",__FUNCTION__)

void Test() {
	SeqStack st;
	TESTHEAD;
	SeqStackInit(&st);
	//������ջ
	SeqStackPush(&st, 'e');
	SeqStackPush(&st, 'd');
	SeqStackPush(&st, 'c');
	SeqStackPush(&st, 'b');
	SeqStackPush(&st, 'a');

	//���Գ�ջ
	SeqStackPop(&st);
	//����ȡջ��Ԫ��
	char ch = SeqStackTopValue(&st);
	printf("expect b, actual:%c\n",ch);
	//�����ж�ջ��
	SeqStackPop(&st);
	SeqStackPop(&st);
	SeqStackPop(&st);
	int t = SeqStackIsEmpty(&st);
	printf("expect 0, actual:%d\n", t);
	SeqStackPop(&st);
	t = SeqStackIsEmpty(&st);
	printf("expect 1, actual:%d\n", t);
	//��������ջ
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