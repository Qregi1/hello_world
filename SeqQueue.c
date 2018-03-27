#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqQueue.h"

//初始化
void QueueInit(Queue* que) {
	if (que == NULL) {
		return;
	}
	que->head = 0;
	que->tail = 0;
}

//判断队列是否为空
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

//入队列一个元素
void QueuePush(Queue* que, QueueType value) {
	if (que == NULL) {
		return;
	}
	int index_tail = que->tail + 1;
	if (index_tail >= QUEUEMAXSIZE) {
		index_tail %= QUEUEMAXSIZE;
	}
	if (index_tail == que->head) {
		//队列已经满了
		printf("队列满了");
		return;
	}
	que->data[index_tail] = value;
	que->tail = index_tail;
}
//出队列一个元素
void QueuePop(Queue* que) {
	if (que == NULL) {
		return;
	}
	if (QueueEmpty(que)) {
		printf("队列已空!\n");
		return;
	}
	que->head++;
	if (que->head >= QUEUEMAXSIZE) {
		que->head %= QUEUEMAXSIZE;
	}
}

//取队首元素
QueueType QueueHeadValue(Queue* que) {
	if (que == NULL) {
		return;
	}
	if (QueueEmpty(que)) {
		printf("队列已空，没有元素！\n");
		return;
	}
	//我这里head没有存元素
	int head = que->head;
	if (++head >= QUEUEMAXSIZE) {
		head %= QUEUEMAXSIZE;
	}
	return que->data[head];
}

//销毁队列
void QueueDestory(Queue* que) {
	if (que == NULL) {
		return;
	}
	que->head = 0;
	que->tail = 0;
}

/////////////////////////////////////////////////
//以下是测试代码
/////////////////////////////////////////////////
#if 0
#include<stdio.h>
#include<stdlib.h>

void Test() {
	Queue que;
	QueueInit(&que);
	//入队列
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
	//测试一些极端的情况
	Queue que;
	QueueInit(&que);
	//入队列5个元素
	QueuePush(&que, 'a');
	QueuePush(&que, 'b');
	QueuePush(&que, 'c');
	QueuePush(&que, 'd');
	QueuePush(&que, 'e');
	//现在队列已经满了
	//再尝试入队列一个元素
	QueuePush(&que, 'f');
	//现在删除一个元素，再试试入队列一个元素
	QueuePop(&que);
	QueuePush(&que, 'o');
	//看看队列数组的第一个元素
	char ch = que.data[0];
	printf("expect o, actual:%c\n", ch);
	//现在删除四个元素
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	QueuePop(&que);
	//现在再入队列四个元素
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	QueuePush(&que, 'o');
	//现在再尝试入队列一个元素
	QueuePush(&que, 'y');
	//再出队列一个元素
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