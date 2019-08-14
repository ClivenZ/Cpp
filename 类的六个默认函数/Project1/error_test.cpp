#if 0
#include<iostream>
using namespace std;
class Date {
public:
	/*Date() {
		_year = 1900;
		_mouth = 1;
		_day = 1;
	}*/
	Date(int year = 1900,int mouth = 1,int day = 1) {
		_year = year;
		_mouth = mouth;
		_day = day;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
int main() {
	Date d1;
	return 0;
}
#endif
