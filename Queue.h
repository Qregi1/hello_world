#pragma once

#include <iostream>

using namespace std;

template<typename T, typename Container = List<T>>
class Queue{
public:
	void Push(const T& x) {
		_con.PushBack(x);
	}
	void Pop() {
		_con.PopFront();
	}
	const T&  HeadValue() {
		return _con.FirstNodeValue();
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