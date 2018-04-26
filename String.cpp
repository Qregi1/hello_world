#define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"

//���캯��
String::String(char* str = "")
	:_str(new char[strlen(str) + 1])
	, _pCount(new size_t(1)) {
	
	strcpy(_str, str);
}

//�������캯��
String::String(const String& s)
	:_str(s._str)
	,_pCount(s._pCount){
	//�����ü������Ӹ�1
	(*_pCount)++;
}
//��������
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

//�ȺŸ�ֵ����������
String& String::operator=(const String& s) {
	if (&s != this) {
		if (--(*_pCount) == 0) {
			//����һ����������
			String::~String();
		}
		_str = s._str;
		_pCount = s._pCount;
		(*_pCount)++;
	}
	return *this;
}
//�����ַ���
const char* String::C_str() {
	return _str;
}

//дʱ����
void String::CopyOnWrite() {
	//������ü�������1���ͱ�ʾ��ǰ�ַ���ֻ��һ��ָ��ָ��
	//��ô���۽����κβ��������ԣ�Ϊ����Ϊ
	if (*_pCount > 1) {
		//�Ѿɵ����ü�����1
		--(*_pCount);
		char* new_str = new char[strlen(_str) + 1];
		strcpy(new_str, _str);
		_str = new_str;
		//���¿����ɹ���_str�ļ�������һ���ڴ�ռ�
		_pCount = new size_t(1);
	}
}

char& String::operator[](size_t pos) {
	CopyOnWrite();
	return _str[pos];
}