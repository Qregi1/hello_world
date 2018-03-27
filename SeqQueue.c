#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqQueue.h"

//��ʼ��
void QueueInit(Queue* que) {
	if (que == NULL) {
		return;
	}
	que->head = 0;
	que->tail = 0;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* que) {
	if (que == NULL) {
		return 1;
	}
	if (que->head == que->tail) {
		return 1;
	}
	else {
		return 0;
	}
}

//�����һ��Ԫ��
void QueuePush(Queue* que, QueueType value) {
	if (que == NULL) {
		return;
	}
	int index_tail = que->tail + 1;
	if (index_tail >= QUEUEMAXSIZE) {
		index_tail %= QUEUEMAXSIZE;
	}
	if (index_tail == que->head) {
		//�����Ѿ�����
		printf("��������");
		return;
	}
	que->data[index_tail] = value;
	que->tail = index_tail;
}
//������һ��Ԫ��
void QueuePop(Queue* que) {
	if (que == NULL) {
		return;
	}
	if (QueueEmpty(que)) {
		printf("�����ѿ�!\n");
		return;
	}
	que->head++;
	if (que->head >= QUEUEMAXSIZE) {
		que->head %= QUEUEMAXSIZE;
	}
}

//ȡ����Ԫ��
QueueType QueueHeadValue(Queue* que) {
	if (que == NULL) {
		return;
	}
	if (QueueEmpty(que)) {
		printf("�����ѿգ�û��Ԫ�أ�\n");
		return;
	}
	//������headû�д�Ԫ��
	int head = que->head;
	if (++head >= QUEUEMAXSIZE) {
		head %= QUEUEMAXSIZE;
	}
	return que->data[head];
}

//���ٶ���
void QueueDestory(Queue* que) {
	if (que == NULL) {
		return;
	}
	que->head = 0;
	que->tail = 0;
}

/////////////////////////////////////////////////
//�����ǲ��Դ���
/////////////////////////////////////////////////
#if 0
#include<stdio.h>
#include<stdlib.h>

void Test() {
	Queue que;
	QueueInit(&que);
	//�����
	QueuePush(&que, 'a');
	QueuePush(&que, 'b');
	QueuePush(&que, 'c');
	QueuePush(&que, 'd');
	QueuePush(&que, 'e');
	char arr[5];
	int i = 0;
	for (; i < 5; ++i) {
		arr[i] = QueueHeadValue(&que);
		QueuePop(&que);
	}
	printf("expect a b c d e\nactual ");
	for (i = 0; i < 5; ++i) {
		printf("[%c] ", arr[i]);
	}
}

void Test2() {
	//����һЩ���˵����
	Queue que;
	QueueInit(&que);
	//�����5��Ԫ��
	QueuePush(&que, 'a');
	QueuePush(&que, 'b');
	QueuePush(&que, 'c');
	QueuePush(&que, 'd');
	QueuePush(&que, 'e');
	//���ڶ����Ѿ�����
	//�ٳ��������һ��Ԫ��
	QueuePush(&que, 'f');
	//����ɾ��һ��Ԫ�أ������������һ��Ԫ��
	QueuePop(&que);
	QueuePush(&que, 'o');
	//������������ĵ�һ��Ԫ��
	char ch = que.data[0];
	printf("expect o, actual:%c\n", ch);
	//����ɾ���ĸ�Ԫ��
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	//������������ĸ�Ԫ��
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	//�����ٳ��������һ��Ԫ��
	QueuePush(&que, 'y');
	//�ٳ�����һ��Ԫ��
	QueuePop(&que);
	QueuePush(&que, 't');
	char c = que.data[5];
	printf("expect t, actual:%c\n", c);
}

int main() {
//	Test();
	Test2();
	system("pause");
	return 0;
}
#endif