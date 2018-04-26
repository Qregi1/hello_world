#define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"

#define TESTHEAD printf("--------------%s---------------\n", __FUNCTION__)

//测试构造函数
void Test1() {
	TESTHEAD;
	String s1("qiuxia");
	s1.Show();
}

//测试拷贝构造函数
void Test2() {
	TESTHEAD;
	String s1("hello world");
	s1.Show();
	String s2(s1);
	s2.Show();
}

//测试赋值运算符重载
void Test3() {
	TESTHEAD;
	String s1("hello bit");
	String s2("hello world");
	s1.Show("s1");
	s2.Show("s2");
	s1 = s2;
	s1.Show("new s1");
}

//测试写实拷贝
void Test4() {
	TESTHEAD;
	String s1("hello world");
	s1.Show("s1 = ");
	//更改
	s1[0] = 'a';
	s1.Show();
	//获取返回值
	printf("%c ", s1[1]);
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	system("pause");
	return 0;
}