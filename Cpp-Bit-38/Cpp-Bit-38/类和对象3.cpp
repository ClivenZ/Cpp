#include <iostream>
#include <cstdlib>

using namespace std;

class A {
public:
	//A(int ri, int ca) {
	//	_ri = ri;
	//	_ca = ca;
	//}
	//A(int ri, int ca)
	//	: _ri(ri)
	//	, _ca(ca)
	//{}
	void SetNum(int ri, int ca) {
		_ri = ri;
		_ca = ca;
	}
private:
	int _ri;
	int _ca;
};



int main1() {
	A ri;
	A ca;
	ri.SetNum(10,20);
	ca.SetNum(20,30);
	system("pause");
	return 0;
}