#include<iostream>
#include<string>


using namespace std;

template<typename T>
T Add(const T& left,const T& right) {
	return left + right;
}
class T {
public:

private:
	T* date;

};


int main() {
	string s("Hello Bit!");
	cout << s.length();
	cout << s.size();
	cout << s.capacity();

	s.clear();
	cout << s.size();
	cout << s.capacity();

	s.resize(20, 'a');
	cout << s << endl;
	cout << s.capacity();

	return 0;
}