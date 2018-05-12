#pragma once 

#include <iostream>
using namespace std;

//实现一个顺序表
typedef int DataType;

#define DATASIZE 5

class Veactor {
public:
	//构造函数
	Veactor()
		: _first(new DataType[DATASIZE])
		, _finsh(_first)
		, _endofstorage(_first + DATASIZE)
	{}
	//拷贝构造函数
	Veactor(const Veactor& v) 
		: _first(new DataType[v.Size()])
		, _finsh(_first + v.Size())
		, _endofstorage(_first + v.Capacity())
	{
		size_t i = 0;
		for (; i < v.Size(); ++i) {
			_first[i] = v._first[i];
		}
	}
	//赋值运算符重载
	Veactor& operator=(Veactor v) {
		DataType* tmp = _first;
		_first = v._first;
		v._first = tmp;

		_finsh = v._finsh;
		_endofstorage = v._endofstorage;

		return *this;
	}
	//析构函数
	~Veactor() {
		delete[] _first;
		_first = NULL;
		_finsh = NULL;
		_endofstorage = NULL;
	}
	//顺序表大小
	size_t Size() const {
		return _finsh - _first;
	}
	//顺序表容量
	size_t Capacity() const {
		return _endofstorage - _first;
	}
	//顺序表扩容
	void Expand(size_t n) {
		DataType* new_first = new DataType[n];
		size_t i = 0;
		for (; i < Size(); ++i) {
			new_first[i] = _first[i];
		}
		delete[] _first;
		size_t size = Size();
		_first = new_first;
		_finsh = _first + size;
		_endofstorage = _first + n;
	}
	//尾插一个元素
	void PushBack(DataType value);
	//逆置
	void Reverse(size_t n);
	//尾删一个元素
	void PopBack();
	//插入一个元素
	void Insert(size_t pos, DataType x);
	//删除一个元素
	void Erase(size_t pos);
	//查找
	size_t Find(DataType value);

	//打印
	void Display(const char* msg = "") {
		size_t sz = Size();
		printf("%s:\n", msg);
		for (size_t i = 0; i < sz; ++i) {
			printf("[%d] ", _first[i]);
		}
		printf("\n");
	}

private:
	DataType* _first;
	DataType* _finsh;
	DataType* _endofstorage;
};