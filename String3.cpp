#define _CRT_SECURE_NO_WARNINGS 1
#include "String3.h"

//构造函数
String::String(char* str = "")
	:_str(new char[strlen(str) + 1 + 4]) {
	//多申请四个字节存储_pCount
	_str += 4;
	strcpy(_str, str);
	GetCount() = 1;
}

int& String::GetCount() {
	return *(int*)(_str - 4);
}

String::~String() {
	if (GetCount() == 1) {
		_str -= 4;
		delete[] _str;
		_str = NULL;
	}
	else {
		--GetCount();
	}
	cout << "~String" << endl;
}
//拷贝构造函数
String::String(const String& s)
	:_str(s._str){
	GetCount()++;
}

//赋值运算符重载
String& String::operator=(const String& s) {
	if (&s != this) {
		if (GetCount() == 1) {
			//只有当前一个引用，可以直接删除
			String::~String();
		}
		else {
			--GetCount();
		}
		_str = s._str;
		++GetCount();
	}
	return *this;
}

//返回c风格的字符串
const char* String::c_str() {
	return _str;
}

//写实拷贝
void String::CopyOnWrite() {
	//如果引用计数大于1，即有不止一个引用，那么就需要重新拷贝了
	//因为能用到这个函数的地方，基本都是需要重新拷贝一份了
	if (GetCount() > 1) {
		//原有的引用计数减1
		--GetCount();
		//先申请一段足够的内存空间
		char* new_str = new char[strlen(_str) + 5];
		new_str += 4;
		//然后把字符串赋值过来
		strcpy(new_str, _str);
		//再新申请的内存空间的引用计数初始化为1
		*(int*)(new_str) = 1;
		//最后再让_str指向新拷贝的内存空间
		_str = new_str;
	}
}

char& String::operator[](size_t pos) {
	CopyOnWrite();
	return _str[pos];
}
