#include <iostream>

using namespace std;

class Student {
public:
	void ShowInfo() {
		cout << _name << " " << _age << " " << endl;
	}

	void SetAge(int age) {
		_age = age;
	}
public:
	char* _name;
protected:
	int _age;
};

int main() {
	Student s;
	s._name = "Jack";
	s.SetAge(10);
	s.ShowInfo();
	


	return 0;
}