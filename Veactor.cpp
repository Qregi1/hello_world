#define _CRT_SECURE_NO_WARNINGS 1
#include "Veactor.h"

//β��һ��Ԫ��
void Veactor::PushBack(DataType value) {
	size_t pos = _finsh - _first;
	Insert(pos, value);
}

//����
void Veactor::Reverse(size_t n) {
	if (n > Size()) {
		printf("�����������!\n");
		return;
	}

	DataType* prev = _first;
	DataType* post = _first + n - 1;

	for (size_t i = 0; i < n / 2; ++i) {
		DataType tmp = *prev;
		*prev = *post;
		*post = tmp;

		//����prev��post
		prev++;
		post--;
	}
}

//βɾһ��Ԫ��
void Veactor::PopBack() {
	//Erase�����λ�ô����������ϸ�һ��
	size_t pos = _finsh - _first - 1;
	Erase(pos);
}

//����һ��Ԫ��
void Veactor::Insert(size_t pos, DataType x) {
	if (_first + pos > _finsh) {
		printf("posλ�ô������!\n");
		return;
	}
	if (_finsh == _endofstorage) {
		//����_endofstorage
		Expand(Size() * 2);
	}
	DataType* end = _first + pos;
	DataType* prev = _finsh - 1;
	DataType* next = _finsh;
	//��pos֮���Ԫ�ض����Ųһλ
	while (next != end) {
		*next = *prev;
		next--, prev--;
	}
	//��Ԫ�ش���posλ��
	*end = x;
	_finsh++;
}

//ɾ��һ��Ԫ��
void Veactor::Erase(size_t pos) {

	if (_first + pos >= _finsh) {
		printf("posλ�ô������!\n");
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
//����
size_t Veactor::Find(DataType value) {
	DataType* cur = _first;
	//����˳���
	while (cur != _finsh) {
		if (*cur == value) {
			return cur - _first;
		}
		cur++;
	}
	return -1;
}

//////////////////////////////
//����Ϊ���Դ���
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

	v.Display("��������Ԫ��");

	v.Insert(0, 6);
	v.Insert(0, 5);
	v.Insert(0, 4);
	v.Insert(0, 3);
	v.Insert(0, 2);
	v.Insert(0, 1);
	v.Display("��0λ�ò�������Ԫ��");
}

//����Ĭ�ϳ�Ա����
void Test1() {
	TESTHEAD;
	//���캯��
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

	v.Display("��������Ԫ��");
	//�������캯��
	Veactor v2 = v;
	v2.Display("�������캯��");
	//��ֵ���������
	v1 = v;
	v1.Display("��ֵ���������");
	v.Insert(0, 11);
	v1.Display();
	v2.Display();
	v.Size();
	v.Capacity();
	//����β��
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
	//����ʾ��
	v.Erase(0);
	v.Display();
	
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.Display("β���ĸ�Ԫ��");
	v.PopBack();
	v.Display("βɾһ��Ԫ��");
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
	v.Display("β���߸�Ԫ��");

	v.Reverse(6);
	v.Display("��������");
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
	v.Display("β���߸�Ԫ��");

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