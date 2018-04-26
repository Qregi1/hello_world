#define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"

//构造函数
String::String(char* str = "")
	:_str(new char[strlen(str) + 1])
	, _pCount(new size_t(1)) {
	
	strcpy(_str, str);
}

//拷贝构造函数
String::String(const String& s)
	:_str(s._str)
	,_pCount(s._pCount){
	//把引用计数增加个1
	(*_pCount)++;
}
//析构函数
String::~String() {
	if (*_pCount == 1) {
		delete[] _str;
		_str = NULL;
		delete _pCount;
		_pCount = NULL;
	}
	else {
		(*_pCount)--;
	}
	cout << "~String" << endl;
}

//等号赋值操作符重载
String& String::operator=(const String& s) {
	if (&s != this) {
		if (--(*_pCount) == 0) {
			//调用一个析构函数
			String::~String();
		}
		_str = s._str;
		_pCount = s._pCount;
		(*_pCount)++;
	}
	return *this;
}
//返回字符串
const char* String::C_str() {
	return _str;
}

//写时拷贝
void String::CopyOnWrite() {
	//如果引用计数等于1，就表示当前字符串只有一个指针指向
	//那么无论进行任何操作都可以，为所欲为
	if (*_pCount > 1) {
		//把旧的引用计数减1
		--(*_pCount);
		char* new_str = new char[strlen(_str) + 1];
		strcpy(new_str, _str);
		_str = new_str;
		//给新拷贝成功的_str的计数开辟一段内存空间
		_pCount = new size_t(1);
	}
}

char& String::operator[](size_t pos) {
	CopyOnWrite();
	return _str[pos];
}