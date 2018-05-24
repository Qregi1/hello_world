#pragma once

#include <iostream>
using namespace std;

template<typename T>
class SeqList{
public:
	SeqList();
	SeqList(const SeqList& s);
	SeqList<T>& operator=(const SeqList<T> s);
	~SeqList();

	void PushBack(const T& x);
	void PopBack();
	void PushFront(const T& x);
	void PopFront();
	
	void Remove(const T& x);
	void RemoveAll(const T& x);
	void Insert(size_t pos, const T& x);
	void Erase(size_t pos);
	T& operator[](size_t pos);
	void Display();
	void Expand(int n);
	size_t Size() {
		return _size;
	}
private:
	T* _data;
	int _size;
	int _capacity;
};

//构造函数
template<typename T>
SeqList<T>::SeqList()
:_size(0)
, _capacity(10)
{
	_data = new T[_capacity];
}

//拷贝构造函数
template<typename T>
SeqList<T>::SeqList(const SeqList& s)
: _size = s._size
, _capacity = s._capacity
, _data = new T[_capacity] {
	//不用memcpy函数是因为对有些类型T这样做可能会出问题，例如string类
	for (int i = 0; i < _size; ++i) {
		_data[i] = s._data[i];
	}
}

//赋值运算符重载
template<typename T>
SeqList<T>& SeqList<T>::operator=(SeqList<T> s) {
	if (this != &s) {
		swap(_data, s._data);
		_size = s._size;
		_capacity = s._capacity;
	}
	return *this;
}

//析构函数
template<typename T>
SeqList<T>::~SeqList() {
	_size = 0;
	_capacity = 0;
	delete[] _data;
	_data = NULL;
}

template<typename T>
void SeqList<T>::Expand(int n) {

	T* new_data = new T[n];
	for (int i = 0; i < _size; ++i) {
		new_data[i] = _data[i];
	}
	_size = _size;
	_capacity = n;
	delete[] _data;
	_data = new_data;
}

template<typename T>
void SeqList<T>::Insert(size_t pos, const T& x) {
	if (_size >= _capacity) {
		Expand(_capacity * 2 + 1);
	}
	if (pos > _capacity) {
		printf("pos位置传入错误!\n");
		perror("pos");
		return;
	}
	int index = _size - 1;
	while (index >= (int)pos) {
		_data[index + 1] = _data[index];
		--index;
	}
	_data[pos] = x;
	++_size;
}

template<typename T>
void SeqList<T>::Erase(size_t pos) {
	if (pos >= _size) {
		printf("pos位置传入错误!\n");
		perror("pos");
		return;
	}
	int index = pos;
	while (index < _size - 1) {
		_data[index] = _data[index + 1];
		++index;
	}
	--_size;
}

template<typename T>
void SeqList<T>::Display() {
	for (int i = 0; i < _size; ++i) {
		printf("[%d] ", _data[i]);
	}
	cout << endl;
}

template<typename T>
void SeqList<T>::PushBack(const T& x) {
	Insert(_size, x);
}

template<typename T>
void SeqList<T>::PopBack() {
	Erase(_size - 1);
}

template<typename T>
void SeqList<T>::PushFront(const T& x) {
	Insert(0, x);
}

template<typename T>
void SeqList<T>::PopFront() {
	Erase(0);
}

template<typename T>
void SeqList<T>::Remove(const T& x) {
	for (int i = 0; i < _size; ++i) {
		if (_data[i] == x) {
			Erase(i);
			break;
		}
	}
}

template<typename T>
void SeqList<T>::RemoveAll(const T& x) {
	for (int i = 0; i < _size; ++i) {
		while (1) {
			if (_data[i] != x) {
				break;
			}
			Erase(i);
		}
	}
}

template<typename T>
T& SeqList<T>::operator[](size_t pos) {
	if (pos >= _size) {
		perror("pos");
	}
	return _data[pos];
}