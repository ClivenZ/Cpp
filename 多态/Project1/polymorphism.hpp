#pragma once
#include<iostream>
#include<string>
using namespace std;
#if 0
class Person {
public:
	virtual void BuyTicket() {
		cout << "全" << endl;
	}
};
class Studetn :public Person {
public:
	virtual void BuyTicket() {
		cout << "半" << endl;
	}
};
void Useing(Person& p) {
	p.BuyTicket();
}
void Test() {
	Person PS;
	Studetn ST;
	
	Useing(PS);
	Useing(ST);
}
#endif
#if 0
//协变
class A{};
class B :public A {};
class Person {
	virtual A* f() {
		return new A;
	}
};
class Student :public Person {
public:
	virtual B* f() {
		return new B;
	}
};
#endif

#if 0
class Preson {
public:
	virtual ~Preson() {
		cout << "~Preson" << endl;
	}
};
class Student :public Preson {
public:
	virtual ~Student() {
		cout << "~Student" << endl;
	}
};
void Test() {
	Preson* p1 = new Preson;
	Preson* p2 = new Student;

	delete p1;
	delete p2;
}
#endif

#if 0
class Car {
public:
	virtual void Drive()  {

	}
};
class Benz :public Car {
public:
	virtual void Drive() override {
		cout << "dsa" << endl;
	}
};
#endif
#if 0
//抽象类
class Car {
public:
	virtual void Drive() = 0;
};
class Benz :public Car {
public:
	virtual void Drive() {
		cout << "nice" << endl;
	}
};
class BMW :public Car {
public:
	virtual void Drive() {
		cout << "using" << endl;
	}
};
void Test() {
	Car* pBenz = new Benz;
	pBenz->Drive();

	Car* pBMW = new BMW;
	pBMW->Drive();


	delete pBenz;
	delete pBMW;
}

#endif


#if 0
class Base {
public:
	virtual void Fun1() {
		cout << "Fun1" << endl;
	}
	virtual void Fun2() {
		cout << "Fun2" << endl;
	}
	virtual void Fun3() {
		cout << "Fun3" << endl;
	}
private:
	int _b = 1;
};
class Derive :public Base {
public:
	virtual void Fun1() {
		cout << "Derive::Fun1" << endl;
	}
private:
	int _d = 2;
};
void Test(){
	/*int i = sizeof(Base);
	cout << i << endl;*/
	Base b;
	Derive d;
}
#endif
#if 0
class Preson {
public:
	virtual void BuyTicket() {
		cout << "全" << endl;
	}
};
class student :public Preson {
public:
	virtual void BuyTicket() {
		cout << "半" << endl;
	}
};
void Func(Preson& p) {
	p.BuyTicket();
}
void Test(){
	Preson Mike;
	Func(Mike);

	student John;
	Func(John);
}
#endif
#include"PrintXuFun.hpp"
#if 0
class Base {
public:
	virtual void Fun1() {
		cout << "Base::Fun1" << endl;
	}
	virtual void Fun2() {
		cout << "Base::Fun2" << endl;
	}
private:
	int a;
};
class Derive :public Base {
public:
	virtual void Fun1() {
		cout << "Derive::Fun1" << endl;
	}
	virtual void Fun3() {
		cout << "Derive::Fun3" << endl;
	}
	virtual void Fun4() {
		cout << "Derive::Fun4" << endl;
	}
private:
	int b;
};

void Test() {
	Base b;
	Derive d;


	VFPTR* Vtableb = (VFPTR*)(*(int*)& b);
	PrintVTable(Vtableb);

	VFPTR* Vtabled = (VFPTR*)(*(int*)& d);
	PrintVTable(Vtabled);
}
#endif

class Base1 {
public:
	virtual void Fun1() {
		cout << "Base1::Fun1" << endl;
	}
	virtual void Fun2() {
		cout << "Base1::Fun2" << endl;
	}
private:
	int b1;
};
class Base2 {
public:
	virtual void Fun1() {
		cout << "Base2::Fun1" << endl;
	}
	virtual void Fun2() {
		cout << "Base2::Fun2" << endl;
	}
private:
	int b2;
};
class Derive :public Base1, public Base2 {
public:
	virtual void Fun1() {
		cout << "Derive::Fun1" << endl;
	}
	virtual void Fun3() {
		cout << "Derive::Fun3" << endl;
	}
private:
	int d1;
};
void Test() {
	Derive d;

	VFPTR* vTableb1 = (VFPTR*)(*(int*)& d);
	PrintVTable(vTableb1);

	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)& d + sizeof(Base1)));
	PrintVTable(vTableb2);


}











