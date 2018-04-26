#pragma once

#include <iostream>
using namespace std;

class String {
public:
	//构造函数
	String(char* str);
	int& GetCount();
	//拷贝构造函数
	String(const String& s);
	//赋值运算符重载
	String& operator=(const String& s);
	const char* c_str();
	void CopyOnWrite();
	char& operator[](size_t pos);
	//析构函数
	~String();

	void Show() {
		cout <<"_str = "<< _str << endl;
		cout << "_pCount = " << GetCount() << endl;
	}
private:
	char* _str;//引用计数在头上
};
