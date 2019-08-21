#pragma once
#include<iostream>
#include<queue>
#include<functional>

using namespace std;


void Test1() {
	//默认使用大堆结构
	vector<int> v{3, 2, 7, 6, 0, 4, 1, 9, 8, 5};
	priority_queue<int> q1;
	for (auto x : v)
		q1.push(x);
	cout << q1.top() << endl;

	//如果需要小堆，将第三个参数模板换成 greater 的比较方式
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(),v.end());
	cout << q2.top() << endl;
}


class Date {
public:
	Date(int year = 1900, int mouth = 1, int day = 1)
		:_year(year)
		, _mouth(mouth)
		, _day(day)
	{}
	bool operator<(const Date& d) const {
		return (_year < d._year) ||
			(_year == d._year && _mouth < d._mouth) ||
			(_year == d._year && _mouth == d._mouth && _day < d._day);
	}
	bool operator>(const Date& d)const {
		return (_year > d._year) ||
			(_year == d._year && _mouth > d._mouth) ||
			(_year == d._year && _mouth == d._mouth && _day > d._day);
	}
	friend ostream& operator<<(ostream&& _cout, const Date& d) {
		_cout << d._year << "-" << d._mouth << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
void Test2(){
	//大堆
	priority_queue<Date> q1;
	q1.push(Date(2018, 1, 1));
	q1.push(Date(2018, 2, 2));
	q1.push(Date(2018, 3, 3));



	//小堆
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2017, 1, 1));
	q2.push(Date(2017, 2, 2));
	q2.push(Date(2017, 3, 3));

}

class Less {
public:
	bool operator()(const Date* pLeft,const Date* pRight) {
		return *pLeft < *pRight;
	}
};
void Test3() {
	priority_queue<Date*, vector<Date*>, Less> q;
	q.push(&Date(2018, 1, 1));
	q.push(&Date(2018, 2, 2));
	q.push(&Date(2018, 3, 3));


}