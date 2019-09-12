#include<iostream>
#include<string>

using namespace std;

int main2() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	if (str1.empty())
		cout << "" << endl;
	int len1 = str1.size();
	return 0;
}