#pragma once
#include<iostream>
#include<string>
using namespace std;

#if 0
class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	//C++11特性：支持定义时进行初始化
	string _name = "Peter";
	int _age = 18;
private:
	int memoy = 20;
};
class Student :public Person {
public:

protected:
	int _stuid;
	int _major;
};
#endif
#if 0
class Preson {
protected:
	string _name;
	string _sex;
	int _age;
};
class Student :public Preson {
public:
	int _No;
};

void Test() {
	Student s;
	//子类对象赋值给父类对象/指针/引用
	Preson p = s;
	Preson* pp = &s;
	Preson& rp = s;

	//基类对象不能赋值给派生类对象
	//s = p;

	//基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &s;
	Student* ps1 = (Student*)pp;
	ps1->_No = 10;

	pp = &p;
	Student* ps2 = (Student*)pp;
	ps2->_No = 10;
}
#endif
#if 0
class Person {
protected:
	string _name = "xiaoxiao";//Name
	int _num = 111; //PersonID
};
class Student :public Person {
public:
	void Print() {
		cout << "Name = " << _name << endl;
		cout << "PersonID = " << _num << endl;
		cout << "StudentID = " << _num << endl;
	}
protected:
	int _num = 999; //StudentID
};
void Test() {
	Student s1;
	s1.Print();
}

class A {
public:
	void fun() {
		cout << "func" << endl;
	}
};
class B :public A {
public:
	void fun(int i) {
		fun();
		cout << "fun(int i)-->" << i << endl;
	}
};
void Test1() {
	B b;
	b.fun(10);
}
#endif
#if 0
class Preson {
public:
	Preson(const char* name = "peter")
		:_name(name)
	{
		cout << "Preson()" << endl;
	}
	Preson(const Preson& p) 
		:_name(p._name)
	{
		cout << "Preson(const Preson& p)" << endl;
	}
	Preson& operator=(const Preson& p) {
		cout << "Preson& operator=(const Preson& p)" << endl;
		if (this != &p) {
			_name = p._name;
		}
		return *this;
	}
	~Preson() {
		cout << "~Preson()" << endl;
	}
protected:
	string _name;
};
class Student :public Preson {
public:
	Student(const char* name, int num)
		:Preson(name)
		, _num(num)
	{
		cout << "Studetn()" << endl;
	}
	Student(const Student& s)
		:Preson(s)
		, _num(s._num)
	{
		cout << "Student(const Studetn& s)" << endl;
	}
	Student& operator=(const Student& s) {
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s) {
			Preson::operator = (s);
			_num = s._num;
		}
		return *this;
	}
	~Student() {
		cout << "~Student()" << endl;
	}
protected: 
	int _num;
};
void Test() {
	Student s1("jack",18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}
#endif
#if 0
//继承与友元
class Student;
class Person {
public:
	friend void DisPlay(const Person& p, const Student& s);
protected:
	string _name;
};
class Student :public Person {
protected:
	int _stuNum;
};
void DisPlay(const Person& p,const Student& s) {
	cout << p._name << endl;
	cout << s._stuNum << endl;
}
#endif
#if 0
//继承与静态成员
class Person {
public:
	Person() { ++_count; }
protected:
	string _name;
public:
	static int _count;
};
int Person::_count = 0;
class Student :public Person {
protected:
	int _num;
};
class Graduate :public Student {
protected:
	string _seminarCourse;
};
void Test(){
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	cout << "人数" << Person::_count << endl;
	Student::_count = 0;

	cout << "人数" << Person::_count << endl;
}
#endif
#if 0
//菱形继承
class Person {
public:
	string _name;
};
class Student :virtual public Person {
protected:
	int _num;
};
class Teacher :virtual public Person {
protected:
	int _id;
};
class Assistant :public Student, public Teacher {
protected:
	string _major;
};
void Test() {
	Assistant a;
	a._name = "peter";
}
#endif
#if 0
//探究虚拟继承的原理
class A {
public:
	int _a;
};
class B :virtual public A {
public:
	int _b;
};
class C : virtual public A {
public:
	int _c;
};
class D :public B, public C {
public:
	int _d;
};
void Test() {
	D d;
	d.B::_a = 1;
	d.C::_a = 2;

	d._b = 3;
	d._c = 4;
	d._d = 5;

	//cout << d.B::_a << endl;
	//cout << d.C::_a << endl;
	//cout << d._b << endl;
	//cout << d._c << endl;
	//cout << d._d << endl;

}
#endif
//探究多继承中的指针偏移问题
class Base1 {
public:
	int _b1;
};
class Base2 {
public:
	int _b2;
};
class Derive :public Base1, public Base2 {
public:
	int _d;
};
void Test() {
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

}






















