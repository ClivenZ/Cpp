#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int Test(string& str, int len) {
	string rem = "ASDFGH";
	int ret = 0;
	if (len <= 6) {
		ret = len - 1;
		return ret;
	}
	else if (len > 6) {
		/*
			ASDFDSAG
			=>GASDF
		*/
		queue<char> s;
		int i = 0;
		while(rem[i] != '\0'){
			for (int j = 0; j < len; ++j) {
				if (str[j] == rem[i]) {
					s.push(str[j]);
					ret += j;
					
				}
			}
			break;
		}

		return ret;
	}
}

int main() {
	int num = 0;
	cin >> num;
	vector<int> ret;
	for (int i = 0; i < num; ++i) {
		string str;
		cin >> str;
		int len = str.size();
		int n = Test(str, len);
		ret.push_back(n);
	}
	for (auto x : ret)
		cout << x << endl;
	return 0;
}
