#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

class String {
public:
	String(const char* str = ""){
		if (str == nullptr) {
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	~String() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void test() {
	String s1("Hello World");
	String s2(s1);	
}
void Test() {
	string s("Hello world");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(500);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void Test2() {
	string str;
	str.push_back(' ');
	str.append("Hello");
	str += 'w';
	str += "orld";
	cout << str << endl;
	cout << str.c_str() << endl;
}

void UrlStr() {
	string url("http://www.baidu.com/hahah/heheh/121231");
	cout << url << endl;
	size_t start = url.find("://");
	//cout << "start" <<start << endl;
	if (start == string::npos) {
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/',start);
	//cout << "finish" << finish << endl;
	string address = url.substr(start, finish - start);
	cout << "address" << address << endl;

	//Delete
	/*size_t pos = url.find("://");
	url.erase(0,pos+3);
	cout << url << endl;*/
}
#endif
#if 0
class string {
public:
	string(const char* str = ""){
		if (str == nullptr) {
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	string(const string& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	~string() {
		if (_str) {
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif
#include "vector.hpp"

int main() {
	
	VecTest();
	return 0;
}