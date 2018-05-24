#define _CRT_SECURE_NO_WARNINGS 1
#include <string>

#include "SeqList.h"
#include "DLinkList.h"
#include "Stack.h"
#include "Queue.h"


//////////////////////////////////////////////////////
//顺序表的测试代码
//////////////////////////////////////////////////////
#define TESTHEADE printf("-------------------%s------------------\n",__FUNCTION__)

#if 0
void TestInsert() {
	TESTHEADE;
	SeqList <int> s;
	s.Insert(0, 11);
	s.Insert(0, 10);
	s.Insert(0, 9);
	s.Insert(0, 8);
	s.Insert(0, 7);
	s.Insert(0, 6);
	s.Insert(0, 5);
	s.Insert(0, 4);
	s.Insert(0, 3);
	s.Insert(0, 2);
	//扩容
	s.Insert(0, 1);
	s.Display();
	
	s.Insert(-1, 1);
	s.Insert(200, 1);

}

void TestErase() {
	TESTHEADE;
	SeqList <int> s;
	s.Insert(0, 11);
	s.Insert(0, 10);
	s.Insert(0, 9);
	s.Insert(0, 8);
	s.Insert(0, 7);
	s.Insert(0, 6);
	s.Insert(0, 5);
	s.Insert(0, 4);
	s.Insert(0, 3);
	s.Insert(0, 2);
	s.Insert(0, 1);

	s.Erase(0);
	s.Erase(0);
	s.Erase(0);
	s.Erase(0);
	s.Display();

}

void TestPushPop() {
	TESTHEADE;
	SeqList <int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);

	s.PopBack();
	s.PopBack();
	s.Display();

	s.PushFront(4);
	s.PushFront(3);
	s.PushFront(2);
	s.Display();
	s.PopFront();
	s.PopFront();
	s.PopFront();
	s.Display();
}

void Test2() {
	TESTHEADE;
	SeqList <int> s;
	s.Insert(0, 11);
	s.Insert(0, 10);
	s.Insert(0, 9);
	s.Insert(0, 8);
	s.Insert(0, 7);
	s.Insert(0, 6);
	s.Insert(0, 5);
	s.Insert(0, 4);
	s.Insert(0, 3);
	s.Insert(0, 2);
	s.Insert(0, 1);

	s.Remove(11);
	s.Display();
	s.Insert(0, 1);
	s.Insert(0, 1);
	s.RemoveAll(1);
	s.Display();
}

int main() {
	TestInsert();
	TestErase();
	TestPushPop();
	Test2();
	system("pause");
	return 0;
}
#endif

//////////////////////////////////////////////////
//带头结点的双向循环链表的测试代码
//////////////////////////////////////////////////
#if 0

//测试Insert和Erase
void Test1() {
	TESTHEADE;
	List<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	s.PushBack(5);
	s.PushBack(6);
	s.PushBack(7);
	s.Display();

	//测试Insert
	s.InsertSomeNode(3, 10);
	s.InsertSomeNode(3, 9);
	s.InsertSomeNode(3, 8);
	s.Display();

	s.EraseSomeNode(3);
	s.EraseSomeNode(3);
	s.EraseSomeNode(3);
	s.Display();
}

//测试Push和Pop
void Test2() {
	TESTHEADE;
	List<int> s1;
	s1.PushFront(6);
	s1.PushFront(5);
	s1.PushFront(4);
	s1.PushFront(3);
	s1.PushFront(2);
	s1.PushFront(1);
	s1.Display();
	s1.PopsBack();
	s1.PopsBack();
	s1.Display();

	s1.PopFront();
	s1.PopFront();
	s1.PopFront();
	s1.Display();
}

//测试默认构造函数
void Test3() {
	TESTHEADE;
	List<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.PushBack(6);
	s1.Display();
	List<int> s2 = s1;
	s2.Display();

	s1.PushBack(7);
	s1.PushBack(8);
	s1.PushBack(9);

	s2 = s1;
	s1.Display();
	s2.Display();
}

int main() {
	Test1();
	Test2();
	Test3();
	system("pause");
	return 0;
}
#endif

//////////////////////////////////////////////////
//栈的测试代码
//////////////////////////////////////////////////

#if 0

void TestStack() {
	Stack<int> s1;
	Stack<char, SeqList<char>> s2;

	//测试s1
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Display();

	s1.Pop();
	s1.Display();
	const int ret = s1.Top();
	cout << "ret:" << ret << endl;
	s1.Pop();
	const int ret2 = s1.Top();
	cout << "ret2:" << ret2 << endl;
	if (s1.Empty()) {
		printf("1:stack is empty\n");
	}
	s1.Pop();
	s1.Pop();
	if (s1.Empty()) {
		printf("2:stack is empty\n");
	}
	//测试s2
	s2.Push('a');
	s2.Push('b');
	s2.Push('c');
	s2.Push('d');
	s2.Push('e');
	const char ret3 = s2.Top();
	printf("expect e, actual:%c\n", ret3);
	s2.Pop();
	s2.Pop();
	s2.Pop();
	s2.Pop();
	if (s2.Empty() == false) {
		printf("1:not empty\n");
	}
	else {
		printf("1:empty\n");
	}
	s2.Pop();
	if (s2.Empty() == false) {
		printf("2:not empty\n");
	}
	else {
		printf("2:empty\n");
	}

	////////////////
	//测试s3，s3为链表
	////////////////
	Stack<int, List<int>> s3;
	s3.Push(5);
	s3.Push(4);
	s3.Push(3);
	s3.Push(2);
	s3.Push(1);

	s3.Display();
	const int ret4 = s3.top();
	printf("expect 1, actual:%d\n", ret4);
	s3.Pop();
	s3.Pop();
	s3.Pop();
	s3.Pop();
	s3.Pop();
	bool is_empty = s3.Empty();
	if (is_empty) {
		printf("stack is empty\n");
	}
}

int main() {
	TestStack();
	system("pause");
	return 0;
}
#endif


///////////////////////////////////////////////////
//队列的测试代码
///////////////////////////////////////////////////
#if 0

string replaceSpace(string iniString, int length) {
	// write code here
	string insert_str = "%20";
	while (1) {
		size_t index = iniString.find(" ");
		if (index == string::npos) {
			break;
		}
		iniString.erase(index, 1);
		iniString.insert(index, insert_str);
	}
	return iniString;
}
void TestUpFunc() {
	//string s1 = "abc";
	//const char* str = s1.c_str;
	//printf("%s\n", str);
	string s1 = "Mr John Simth";
	string s2;
	string s3 = "Hello   World";
	s2 = replaceSpace(s3, 12);
	cout << s2 << endl;
}

//测试队列的适配器模式
void TestQueue() {
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.Push(5);
	
	const int ret = q1.HeadValue();
	printf("expect 1, actual:%d\n", ret);
	q1.Pop();
	q1.Pop();
	q1.Pop();
	q1.Pop();
	if (q1.Empty()) {
		printf("queue is empty!\n");
	}
	else {
		printf("queue is not empty!\n");
	}
	q1.Pop();
	if (q1.Empty()) {
		printf("queue is empty!\n");
	}
	else {
		printf("queue is not empty!\n");
	}
}

int main() {
	TestQueue();
	
	system("pause");
	return 0;
}

#endif