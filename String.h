#pragma once
#include <iostream>
using namespace std;

//引用计数写实拷贝
class String {
public:
	//构造函数
	String(char* str);
	//拷贝构造函数
	String(const String& str);
	//等号赋值操作符重载
	String& operator=(const String& s);
	//返回字符串
	const char* C_str();
	//写时拷贝
	void CopyOnWrite();
	char& operator[](size_t pos);

	//其他的一些操作和深拷贝一样，只是需要CopyOnWrite()来复制一下

	//析构函数
	~String();
	void Show(char* msg = "打印如下") {
		printf("%s:\n", msg);
		printf("_str = %s\n", _str);
		printf("_pCount = %lu\n", *_pCount);
	}
private:
	//成员变量有一个字符串和一个用来计数的
	char* _str;
	size_t* _pCount;
};