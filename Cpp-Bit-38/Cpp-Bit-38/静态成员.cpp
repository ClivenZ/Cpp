#include <iostream>
#include <cstdlib>

using namespace std;

class Date {
public:
	Date(int year) {
		_count++;
		_year = year;
		cout << "Date(int)" << endl;
	}
	Date(const Date& d1) {
		_count++;
		_year = d1._year;
		cout << "Date(const Date&)" << endl;
	}
	static int GetCount() {
		return _count;
	}
private:
	int _year;
	static int _count;
};

Date Fun1(Date d1) {
	return d1;
}

int Date::_count = 0;

int main() {

	Date d1(2019);
	Date d2(2018);
	Date d3(2017);
	
	
	Fun1(d1);

	cout << Date::GetCount() << endl;
	cout << d1.GetCount() << endl;

	//cout << Date::_count << endl;
	//cout << d1._count << endl;
	//cout << &Date::_count << endl;
	//cout << &d1._count << endl;
	//cout << &d2._count << endl;
	//cout << &d3._count << endl;


	system("pause");
	return 0;
}