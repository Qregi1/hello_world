#pragma once

#include<iostream>

using namespace std;

/*日期类*/
class Date {
	
public:
	//构造函数
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day) {
		//对合法性进行判断
		//判断月
		if ((year >= 0) 
			&& (month >= 1 && month <= 12) 
			&& (day >= 1 && day <= _GetMonthDay(year, month))) {
			//当前年月日合法，可以进行初始化
			this->_year = year;
			this->_month = month;
			this->_day = day;
			}
		else {
			//当前月不合法，进行初始化
			cout << "传入的参数不合法" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//拷贝构造函数
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//析构函数
	~Date() {
		cout << "~Date" << endl;
	}

	//操作符重载
	//赋值
	Date& operator=(const Date& d);
	//判断相等
	bool operator==(const Date& d);
	//判断不等
	bool operator!=(const Date& d);
	//大于
	bool operator>(const Date& d);
	//大于等于
	bool operator>=(const Date& d);
	//小于
	bool operator<(const Date& d);
	//小于等于
	bool operator<=(const Date& d);
	//加天数
	Date operator+(int day);
	//+=
	Date& operator+=(int day);
	//减天数
	Date operator-(int day);
	//-=
	Date& operator-=(int day);
	//两个日期相隔天数
	int operator-(const Date& d);
	//自加天数  前置++
	Date& operator++();
	//自加天数  后置++
	Date operator++(int);
	//自减天数  前置--
	Date& operator--();
	//自减天数  后置--
	Date operator--(int);
	//输出
	//输入
	void Show() {
		cout << "year = " << _year << endl;
		cout << "month = " << _month << endl;
		cout << "day = " << _day << endl;
	}
private:
	//判断闰年
	bool isleap(int year);
	//得到当前月的日期
	int _GetMonthDay(int year, int month);
private:
	int _year;
	int _month;
	int _day;
};