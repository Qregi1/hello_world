#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;

//判断闰年
bool Date::isleap(int year) {
	if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
		return true;
	}
	return false;
}
//求出当前月的天数
int Date::_GetMonthDay(int year, int month) {
	//对year和month的合法性进行判断
	assert(month > 0 && month < 13);
	assert(year >= 0);
	//不同月份的天数
	int arr_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isleap(year) && month == 2) {
		//是闰年的二月，就把二月的天数+1
		return arr_month[month] + 1;
	}
	return arr_month[month];
}

//赋值
Date& Date::operator=(const Date& d) {
	//这里传入的是this指针,如果两个要赋值的是自身，就不用去赋值了
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//判断相等
bool Date::operator==(const Date& d) {
	if (this == &d) return true;
	return (_year == d._year && _month == d._month && _day == d._day);
}

//判断不等
bool Date::operator!=(const Date& d) {
	return (!(*this == d));
}

//大于
bool Date::operator>(const Date& d) {
	if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
}

//大于等于
bool Date::operator>=(const Date& d) {
	if (operator==(d) || operator>(d)) {
		//大于和等于都为真则大于等于
		return true;
	}
	return false;
}

//小于
bool Date::operator<(const Date& d) {
	if (!operator>=(d)) return true;
	return false;
}

//小于等于
bool Date::operator<=(const Date& d) {
	if (operator<(d) || operator==(d)) return true;
	return false;
}

//加天数
Date Date::operator+(int day) {
	Date tmp(*this);
	if (day < 0) {
		return *this = operator-(-day);
	}
	else {
		tmp._day += day;
		while (tmp._day > _GetMonthDay(tmp._year, tmp._month)) {
			tmp._day -= _GetMonthDay(tmp._year, tmp._month);
			if (tmp._month == 12) {
				++tmp._year;
				tmp._month = 1;
			}
			else {
				++tmp._month;
			}
		}//_day < _GetMonthDay(_year, _month),天数如果合法那么日期也就合法了
	}//day < 0
	return tmp;
}

//+=
Date& Date::operator+=(int day) {
	//这里是的*this是如何加的？
	*this = *this + day;
	return *this;
}

//减天数
Date Date::operator-(int day) {
	Date tmp(*this);
	if (day < 0) {
		return *this + (-day);
	}
	else {
		tmp._day -= day;
		while (tmp._day <= 0) {
			if (tmp._month = 1) {
				--tmp._year;
				tmp._month = 12;
			}
			else {
				--tmp._month;
			}
			//因为是借位借的是上个月的天数，所以要先变化年数和天数
			tmp._day += _GetMonthDay(tmp._year, tmp._month);
		}
	}
	return tmp;
}

//-=
Date& Date::operator-=(int day) {
	*this = *this - day;
	return *this;
}

//自加天数  前置++
Date& Date::operator++() {
	++_day;
	if (_day > _GetMonthDay(_year, _month)) {
		_day = 1;
		if (_month == 12) {
			++_year;
			_month = 1;
		}
		else {
			++_month;
		}
	}
	return *this;
}

//自加天数  后置++
Date Date::operator++(int) {
	Date tmp(*this);
	++_day;
	if (_day > _GetMonthDay(_year, _month)) {
		_day = 1;
		if (_month == 12) {
			++_year;
			_month = 1;
		}
		else {
			++_month;
		}
	}
	return tmp;
}

//自减天数  前置--
Date& Date::operator--() {
	--_day;
	if (_day < 0) {
		if (_month == 1) {
			--_year;
			_month = 12;
		}
		else {
			--_month;
		}
		_day = _GetMonthDay(_year, _month);
	}
	return *this;
}

//自减天数  后置--
Date Date::operator--(int) {
	Date tmp(*this);
	--_day;
	if (_day < 0) {
		if (_month == 1) {
			--_year;
			_month = 12;
		}
		else {
			--_month;
		}
		_day = _GetMonthDay(_year, _month);
	}
	return tmp;
}

//两个日期相隔天数
int Date::operator-(const Date& d) {
	int day = 0;
	Date Max, Min;
	if (*this > d) {
		Max = *this;
		Min = d;
	}
	else {
		Max = d;
		Min = *this;
	}
	while (Min != Max) {
		--Max;
		++day;
	}
	return day;
}

#if 1
//////////////////////////////////////////////
//以下为测试代码
//////////////////////////////////////////////
//测试构造函数
void TestDate() {
	//测试构造函数和析构函数
	Date d;
	d.Show();
	Date d2(2018, 3, 21);
	d2.Show();
	//测试拷贝构造函数
	Date d3 = d2;
	Date d4(d3);
	d3.Show();
	d4.Show();
	//出错的情况下
	Date d5(2018, 2, 29);
	d5.Show();
}
//赋值和各种判断操作
void TestJudge() {
	Date d1(2018, 3, 21);
	//判断赋值
	Date d2;
	d2.operator=(d1);
	d1.Show();
	d2.Show();
	//判断相等
	if (d1.operator==(d2)) {
		cout << "相等" << endl;
	}
	else {
		cout << "不等" << endl;
	}
	//判断不等
	if (d1.operator!=(d2)) {
		cout << "不相等" << endl;
	}
	else {
		cout << "相等" << endl;
	}
	//判断大于
	Date d3(2018, 3, 22);
	if (d3.operator>(d1))
		printf("d3大于d1\n");
	else
		printf("d3不大于d3\n");
	//判断大于等于
	Date d4(2018, 3, 22);
	Date d5(2018, 3, 24);
	if (d4.operator>=(d3) && d5.operator>=(d3))
		cout << "yes" << endl;
	else {
		printf("不是");
	}
	//判断小于
	Date d6(2018, 3, 11);
	if (d6.operator<(d5)) cout << "yes" << endl;
	//判断小于等于
	if (d6.operator<=(d3) && d4.operator<=(d3)) cout << "yes" << endl;
}

void Test3() {
	//测试加减
	//加
	Date d1(2018, 2, 20);
	Date d2(d1);
	Date d3;
	d3 = d2+52;
	d2.Show();
	d3.Show();
	//加等
	d3 += 10;
	d3.Show();
	//减
	d3 = d3 - 10;
	d3.Show();
	//减等
	d3 += 10;
	d3 -= 10;
	d3.Show();
}

//测试自增自减
void Test4() {
	Date d1(2018, 2, 21);
	Date d2;
	//前置++
	d2 = d1++;
	d1.Show();
	d2.Show();
	//后置++
	++d1;
	d1.Show();
	//前置--
	--d1;
	d1.Show();
	//后置--
	d2 = d1--;
	d2.Show();
	d1.Show();
	//两个日期之间的天数
	Date d3(2018, 2, 10);
	d3.Show();
	d1.Show();
	int day = d1 - d3;
	int day2 = d3 - d1;
	cout << day << day << endl;
}

int main() {
	//TestDate();
	//TestJudge();
	//Test3();
	Test4();
	system("pause");
	return 0;
}
#endif


