#pragma once

#include <iostream>
using namespace std;

template<typename T, typename Container = SeqList<T>>
class Stack{
public:
	void Push(const T& x) {
		_con.PushBack(x);
	}
	void Pop() {
		_con.PopBack();
	}
	//È¡Õ»¶¥ÔªËØ
	const T& Top() {
		return _con[_con.Size() - 1];
	}
	const T& top() {
		return _con.LastNodeValue();
	}
	bool Empty() {
		if (_con.Size() == 0) {
			return true;
		}
		return false;
	}
	void Display() {
		_con.Display();
	}
private:
	Container _con;
};

