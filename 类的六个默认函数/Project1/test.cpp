
#if 0
class Date;
class Time {
	friend class Date;
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
	//void DisPlay() {
	//	cout << _hour << _minute << _second << endl;
	//}
	//~Time() {rb
	//	cout << "~Time()" << endl;
	//}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date {
public:
	//构造函数，只对对象进行初始化，不负责开辟空间
	Date(int year = 1900,int mouth = 1,int day = 1)
		:_year(year)
		, _mouth(mouth)
		, _day(day)
	{}
	////拷贝构造函数
	//Date(const Date& d1)
	//	:_year(d1._year)
	//	,_mouth(d1._mouth)
	//	,_day(d1._day)
	//{}
	//void DisPlay() {
	//	cout << _year << _mouth << _day << endl;
	//}
	void SetTimeOfDate(int hour,int minute,int second) {
		Time& T(hour,minute,second);
		T._hour = hour;
		T._minute = minute;
		T._second = second;
	}
	//析构函数，释放资源
	//~Date() {
	//	cout << "~Date()" << endl;
	//}
private:
	int _year;
	int _mouth;
	int _day;
	//Time _t;   //类类型没有默认的构造函数
};
#endif
#if 0
//内存管理
class Test {
public:
	Test()
		:_date(0)
	{
		cout << "Test()" << endl;
	}
	~Test() {
		cout << "~Test()" << endl;
	}
private:
	int _date;
};
void CTest() {
	//申请单个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	//申请10个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
}
void CppTest() {
	//申请单个Test类型的对象
	Test* p1 = new Test;
	delete p1;

	//申请10个Test类型的对象
	Test* p2 = new Test[10];
	delete p2;
}
#if 0
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "MyString.hpp"
int main()
{
	using namespace My;
	My::String s1 = "Hello World";
	

	system("pause");
	return 0;
}
#endif
#if 0
//删除公共字符串
#include<iostream>
#include<string>

using namespace std;

int main() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	for (size_t i = 0; i < s2.size(); ++i) {
		for (size_t j = 0; j < s1.size(); ++j) {
			if (s1[j] == s2[i]) {
				s1.erase(j,1);
			}
		}
	}
	cout << s1 << endl;
	return 0;
}
#endif
