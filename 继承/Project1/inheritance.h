#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	void Print() {
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	//C++11���ԣ�֧�ֶ���ʱ���г�ʼ��
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

void Test() {


}