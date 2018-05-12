#define _CRT_SECURE_NO_WARNINGS 1
#include "Veactor.h"

//尾插一个元素
void Veactor::PushBack(DataType value) {
	size_t pos = _finsh - _first;
	Insert(pos, value);
}

//逆置
void Veactor::Reverse(size_t n) {
	if (n > Size()) {
		printf("参数传入错误!\n");
		return;
	}

	DataType* prev = _first;
	DataType* post = _first + n - 1;

	for (size_t i = 0; i < n / 2; ++i) {
		DataType tmp = *prev;
		*prev = *post;
		*post = tmp;

		//更新prev和post
		prev++;
		post--;
	}
}

//尾删一个元素
void Veactor::PopBack() {
	//Erase里面的位置传入错误可以严格一点
	size_t pos = _finsh - _first - 1;
	Erase(pos);
}

//插入一个元素
void Veactor::Insert(size_t pos, DataType x) {
	if (_first + pos > _finsh) {
		printf("pos位置传入错误!\n");
		return;
	}
	if (_finsh == _endofstorage) {
		//扩容_endofstorage
		Expand(Size() * 2);
	}
	DataType* end = _first + pos;
	DataType* prev = _finsh - 1;
	DataType* next = _finsh;
	//把pos之后的元素都向后挪一位
	while (next != end) {
		*next = *prev;
		next--, prev--;
	}
	//把元素存入pos位置
	*end = x;
	_finsh++;
}

//删除一个元素
void Veactor::Erase(size_t pos) {

	if (_first + pos >= _finsh) {
		printf("pos位置传入错误!\n");
		return;
	}

	DataType* prev = _first + pos;
	DataType* next = prev + 1;
	while (next != _finsh) {
		*prev = *next;
		prev++, next++;
	}
	_finsh--;
}
//查找
size_t Veactor::Find(DataType value) {
	DataType* cur = _first;
	//遍历顺序表
	while (cur != _finsh) {
		if (*cur == value) {
			return cur - _first;
		}
		cur++;
	}
	return -1;
}

//////////////////////////////
//以下为测试代码
//////////////////////////////
#if 1

#define TESTHEAD printf("----------------------%s--------------------\n\n",__FUNCTION__)

void TestInsert() {
	TESTHEAD;
	Veactor v;
	v.Insert(0, 1);
	v.Insert(1, 2);
	v.Insert(2, 3);
	v.Insert(3, 4);
	v.Insert(4, 5);
	v.Insert(5, 6);

	v.Display("插入六个元素");

	v.Insert(0, 6);
	v.Insert(0, 5);
	v.Insert(0, 4);
	v.Insert(0, 3);
	v.Insert(0, 2);
	v.Insert(0, 1);
	v.Display("在0位置插入六个元素");
}

//测试默认成员函数
void Test1() {
	TESTHEAD;
	//构造函数
	Veactor v1;
	
	size_t sz = v1.Size();
	size_t ca = v1.Capacity();
	Veactor v;
	v.Insert(0, 1);
	v.Insert(1, 2);
	v.Insert(2, 3);
	v.Insert(3, 4);
	v.Insert(4, 5);
	v.Insert(5, 6);

	v.Display("插入六个元素");
	//拷贝构造函数
	Veactor v2 = v;
	v2.Display("拷贝构造函数");
	//赋值运算符重载
	v1 = v;
	v1.Display("赋值运算符重载");
	v.Insert(0, 11);
	v1.Display();
	v2.Display();
	v.Size();
	v.Capacity();
	//测试尾插
	v.PushBack(11);
	v.PushBack(12);
	v.PushBack(13);
	v.Display();
}

void TestErase() {
	TESTHEAD;
	Veactor v;
	v.PushBack(0);
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);
	v.PushBack(8);


	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	v.Erase(0);
	//错误示例
	v.Erase(0);
	v.Display();
	
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.Display("尾插四个元素");
	v.PopBack();
	v.Display("尾删一个元素");
}

void TestReverse() {
	TESTHEAD;
	Veactor v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);
	v.Display("尾插七个元素");

	v.Reverse(6);
	v.Display("逆置链表");
}

void TestFind() {
	TESTHEAD;
	Veactor v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);
	v.Display("尾插七个元素");

	size_t index = v.Find(7);
	printf("expect 6, actual:%d\n", index);

	int i = v.Find(10);
	printf("expect -1, actual:%d\n", i);
}

int main() {
	Test1();
	TestInsert();
	TestErase();
	TestReverse();
	TestFind();
	system("pause");
	return 0;
}

#endif