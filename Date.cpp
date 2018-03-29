#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;

//�ж�����
bool Date::isleap(int year) {
	if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)) {
		return true;
	}
	return false;
}
//�����ǰ�µ�����
int Date::_GetMonthDay(int year, int month) {
	//��year��month�ĺϷ��Խ����ж�
	assert(month > 0 && month < 13);
	assert(year >= 0);
	//��ͬ�·ݵ�����
	int arr_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isleap(year) && month == 2) {
		//������Ķ��£��ͰѶ��µ�����+1
		return arr_month[month] + 1;
	}
	return arr_month[month];
}

//��ֵ
Date& Date::operator=(const Date& d) {
	//���ﴫ�����thisָ��,�������Ҫ��ֵ���������Ͳ���ȥ��ֵ��
	if (this != &d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

//�ж����
bool Date::operator==(const Date& d) {
	if (this == &d) return true;
	return (_year == d._year && _month == d._month && _day == d._day);
}

//�жϲ���
bool Date::operator!=(const Date& d) {
	return (!(*this == d));
}

//����
bool Date::operator>(const Date& d) {
	if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
}

//���ڵ���
bool Date::operator>=(const Date& d) {
	if (operator==(d) || operator>(d)) {
		//���ں͵��ڶ�Ϊ������ڵ���
		return true;
	}
	return false;
}

//С��
bool Date::operator<(const Date& d) {
	if (!operator>=(d)) return true;
	return false;
}

//С�ڵ���
bool Date::operator<=(const Date& d) {
	if (operator<(d) || operator==(d)) return true;
	return false;
}

//������
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
		}//_day < _GetMonthDay(_year, _month),��������Ϸ���ô����Ҳ�ͺϷ���
	}//day < 0
	return tmp;
}

//+=
Date& Date::operator+=(int day) {
	//�����ǵ�*this����μӵģ�
	*this = *this + day;
	return *this;
}

//������
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
			//��Ϊ�ǽ�λ������ϸ��µ�����������Ҫ�ȱ仯����������
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

//�Լ�����  ǰ��++
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

//�Լ�����  ����++
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

//�Լ�����  ǰ��--
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

//�Լ�����  ����--
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

//���������������
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
//����Ϊ���Դ���
//////////////////////////////////////////////
//���Թ��캯��
void TestDate() {
	//���Թ��캯������������
	Date d;
	d.Show();
	Date d2(2018, 3, 21);
	d2.Show();
	//���Կ������캯��
	Date d3 = d2;
	Date d4(d3);
	d3.Show();
	d4.Show();
	//����������
	Date d5(2018, 2, 29);
	d5.Show();
}
//��ֵ�͸����жϲ���
void TestJudge() {
	Date d1(2018, 3, 21);
	//�жϸ�ֵ
	Date d2;
	d2.operator=(d1);
	d1.Show();
	d2.Show();
	//�ж����
	if (d1.operator==(d2)) {
		cout << "���" << endl;
	}
	else {
		cout << "����" << endl;
	}
	//�жϲ���
	if (d1.operator!=(d2)) {
		cout << "�����" << endl;
	}
	else {
		cout << "���" << endl;
	}
	//�жϴ���
	Date d3(2018, 3, 22);
	if (d3.operator>(d1))
		printf("d3����d1\n");
	else
		printf("d3������d3\n");
	//�жϴ��ڵ���
	Date d4(2018, 3, 22);
	Date d5(2018, 3, 24);
	if (d4.operator>=(d3) && d5.operator>=(d3))
		cout << "yes" << endl;
	else {
		printf("����");
	}
	//�ж�С��
	Date d6(2018, 3, 11);
	if (d6.operator<(d5)) cout << "yes" << endl;
	//�ж�С�ڵ���
	if (d6.operator<=(d3) && d4.operator<=(d3)) cout << "yes" << endl;
}

void Test3() {
	//���ԼӼ�
	//��
	Date d1(2018, 2, 20);
	Date d2(d1);
	Date d3;
	d3 = d2+52;
	d2.Show();
	d3.Show();
	//�ӵ�
	d3 += 10;
	d3.Show();
	//��
	d3 = d3 - 10;
	d3.Show();
	//����
	d3 += 10;
	d3 -= 10;
	d3.Show();
}

//���������Լ�
void Test4() {
	Date d1(2018, 2, 21);
	Date d2;
	//ǰ��++
	d2 = d1++;
	d1.Show();
	d2.Show();
	//����++
	++d1;
	d1.Show();
	//ǰ��--
	--d1;
	d1.Show();
	//����--
	d2 = d1--;
	d2.Show();
	d1.Show();
	//��������֮�������
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


