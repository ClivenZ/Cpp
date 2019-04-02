#include <iostream>
#include <cstdlib>

using namespace std;

class Date {
public:
	//构造函数
	Date(int year, int mouth) {
		_year = year;
		_mouth = mouth;
	}
	//拷贝构造函数
	Date(const Date& d1) {
		_year = d1._year;
		_mouth = d1._mouth;
	}
	//析构函数
	~Date() {
		cout << "~Date()" << endl;
	}
	//(连续)赋值运算附重载
	Date& operator=(const Date& d1) {
		if (this != &d1) {
			_year = d1._year;
			_mouth = d1._mouth;
		}
		return *this;
	}
	//“==”运算符重载
	bool operator==(Date& d2) {
		return _year == d2._year && _mouth == d2._mouth;
	}
	void SetDate(int year, int mouth) {
		_year = year;
		_mouth = mouth;
	}
	void DisPlay() {
		cout << this->_year << "-" << this->_mouth << " " << endl;
	}
	void Test() {
		cout << "Date Test()" << endl;
	}
private:
	int _year;
	int _mouth;
};

//bool operator==(const Date& d1,const Date& d2) {
//	return d1._year == d2._year && d1._mouth == d2._mouth;
//}
int main() {

	/*Date d1(2019, 4);
	Date d2(d1);
	d1.DisPlay();
	d2.DisPlay();
	cout << (d1 == d2) << endl;*/


	//赋值测试
	Date d1(1996, 06);
	Date d2(1997, 04);
	Date d3 = d1;
	d1.DisPlay();
	d2.DisPlay();
	d3.DisPlay();
	//d1.operator = (d3) --> d2.operator(d1)
	d2 = d1 = d3;
	d2.DisPlay();
	system("pause");
	return 0;
}