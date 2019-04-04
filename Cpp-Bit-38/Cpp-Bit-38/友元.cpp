#include<iostream>
#include<cstdlib>

using namespace std;


class Date {
	friend class Time;
	friend ostream& operator<<(ostream& outs, Date& d);
	friend istream& operator>>(istream& ins, Date& d);
public:
	Date(int year = 1900, int mouth = 1, int day = 1)
		:_year(year)
		, _mouth(mouth)
		, _day(day)
	{}
	//cout << Date
	ostream& operator<<(ostream& outs,const Date& d) {
		cout <<d._year << "-" <<d._mouth << "-" <<d._day << endl;
	}
	//
	istream& operator>>(istream& ins,const Date& d) {
		ins >> d._year >> d.mouth >> d._day;
	}

	void SetDate(int date,Time& t) {
		t._date = date;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
class Time {
	//Date 类 是 Time 类 的友元
	//Date 类 可以访问和设置 Time 类 中的所有成员
	friend class Date;
public:
	Time(int date)
		:_date(date)
	{}
	void DisPlay(Date& d) {
		cout << d._year << "-" << d._mouth << "-" << d._day << endl;
	}
private:
	int _date;
};
int main() {

	Date d1(2019, 1, 1);

	//d1.operator<< (cout);
	//d1<<cout;

	//operator<<(cout, d1);
	//cout << d1 << d1;

	cin >> d1;
	cout << d1;

	system("pause");
	return 0;
}


