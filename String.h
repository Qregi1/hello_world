#pragma once
#include <iostream>
using namespace std;

//���ü���дʵ����
class String {
public:
	//���캯��
	String(char* str);
	//�������캯��
	String(const String& str);
	//�ȺŸ�ֵ����������
	String& operator=(const String& s);
	//�����ַ���
	const char* C_str();
	//дʱ����
	void CopyOnWrite();
	char& operator[](size_t pos);

	//������һЩ���������һ����ֻ����ҪCopyOnWrite()������һ��

	//��������
	~String();
	void Show(char* msg = "��ӡ����") {
		printf("%s:\n", msg);
		printf("_str = %s\n", _str);
		printf("_pCount = %lu\n", *_pCount);
	}
private:
	//��Ա������һ���ַ�����һ������������
	char* _str;
	size_t* _pCount;
};