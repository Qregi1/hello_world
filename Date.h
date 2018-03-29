#pragma once

#include<iostream>

using namespace std;

/*������*/
class Date {
	
public:
	//���캯��
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day) {
		//�ԺϷ��Խ����ж�
		//�ж���
		if ((year >= 0) 
			&& (month >= 1 && month <= 12) 
			&& (day >= 1 && day <= _GetMonthDay(year, month))) {
			//��ǰ�����պϷ������Խ��г�ʼ��
			this->_year = year;
			this->_month = month;
			this->_day = day;
			}
		else {
			//��ǰ�²��Ϸ������г�ʼ��
			cout << "����Ĳ������Ϸ�" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//�������캯��
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��������
	~Date() {
		cout << "~Date" << endl;
	}

	//����������
	//��ֵ
	Date& operator=(const Date& d);
	//�ж����
	bool operator==(const Date& d);
	//�жϲ���
	bool operator!=(const Date& d);
	//����
	bool operator>(const Date& d);
	//���ڵ���
	bool operator>=(const Date& d);
	//С��
	bool operator<(const Date& d);
	//С�ڵ���
	bool operator<=(const Date& d);
	//������
	Date operator+(int day);
	//+=
	Date& operator+=(int day);
	//������
	Date operator-(int day);
	//-=
	Date& operator-=(int day);
	//���������������
	int operator-(const Date& d);
	//�Լ�����  ǰ��++
	Date& operator++();
	//�Լ�����  ����++
	Date operator++(int);
	//�Լ�����  ǰ��--
	Date& operator--();
	//�Լ�����  ����--
	Date operator--(int);
	//���
	//����
	void Show() {
		cout << "year = " << _year << endl;
		cout << "month = " << _month << endl;
		cout << "day = " << _day << endl;
	}
private:
	//�ж�����
	bool isleap(int year);
	//�õ���ǰ�µ�����
	int _GetMonthDay(int year, int month);
private:
	int _year;
	int _month;
	int _day;
};