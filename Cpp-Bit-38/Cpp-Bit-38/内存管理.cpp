#include <iostream>
#include <cstdlib>

using namespace std;

class Test
{
public:
	Test()
		: _data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
int main() {
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	Test* p3 = new Test;
	Test* p4 = (Test*)malloc(sizeof(Test));
}