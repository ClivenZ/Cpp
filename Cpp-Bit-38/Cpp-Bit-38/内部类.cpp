#include <iostream>
#include <cstdlib>

using namespace std;

class A {
	// B 是 A 的内部类，相当于 B 是 A 的友元类
	class B {
	public:
		void DisPlay(A& a) {
			//外部类的普通私有成员只能通过外部类对象访问
			cout << a._a << endl;
			//外部类的静态私有成员可以通过外部类对象访问，也可以直接访问
			cout << _s << endl;
			cout << a._s << endl;
		}
	private:
		int _b;
	};
	void DisPlay() {
		//外部类对于内部类没有任何的访问权限，不能访问内部类的私有成员
		//cout << b._b << endl;
		
	}
private:
	int _a;
	static int _s;
};

int main() {

	system("pause");
	return 0;
}