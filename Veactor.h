#pragma once 

#include <iostream>
using namespace std;

//ʵ��һ��˳���
typedef int DataType;

#define DATASIZE 5

class Veactor {
public:
	//���캯��
	Veactor()
		: _first(new DataType[DATASIZE])
		, _finsh(_first)
		, _endofstorage(_first + DATASIZE)
	{}
	//�������캯��
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
	//��ֵ���������
	Veactor& operator=(Veactor v) {
		DataType* tmp = _first;
		_first = v._first;
		v._first = tmp;

		_finsh = v._finsh;
		_endofstorage = v._endofstorage;

		return *this;
	}
	//��������
	~Veactor() {
		delete[] _first;
		_first = NULL;
		_finsh = NULL;
		_endofstorage = NULL;
	}
	//˳����С
	size_t Size() const {
		return _finsh - _first;
	}
	//˳�������
	size_t Capacity() const {
		return _endofstorage - _first;
	}
	//˳�������
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
	//β��һ��Ԫ��
	void PushBack(DataType value);
	//����
	void Reverse(size_t n);
	//βɾһ��Ԫ��
	void PopBack();
	//����һ��Ԫ��
	void Insert(size_t pos, DataType x);
	//ɾ��һ��Ԫ��
	void Erase(size_t pos);
	//����
	size_t Find(DataType value);

	//��ӡ
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