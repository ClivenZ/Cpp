#include<iostream>
#include<string>
#include<vector>
using namespace std;
int Test() {
	string str;
	getline(cin, str);
	vector<char> ret;
	int len = str.size();
	for (int i = len - 1; i >= 0; --i) {
		ret.push_back(str[i]);
	}
	for (auto x : ret)
		cout << x;
	cout << endl;
	return 0;
}

int main() {
	int num = 0;
	cin >> num;
	vector<int> v;
	int cur = num % 2;
	while (cur != 0) {
		v.push_back(cur);
		cur = num % 2;
	}
	int len = v.size();
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		if (v[i] == 1)
			ret += 1;
	}
	cout << ret << endl;
	return 0;
}