#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int Test(string& str,int len) {
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
		string s;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < len; ++j) {
				if (str[j] == rem[i])
					s.push_back(str[j]);
			}
		}
		return ret;
	}
}

int main2() {
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


vector<int> u;

void Test1(string& n1,string& n2) {
	vector<int> ret = { 0,0,0,0,0,0,0,0,0 };
	int len1 = n1.size();
	int len2 = n2.size();
	for (int i = 0; i < len1; ++i) {
		if (n1[i] != '0') {
			int q = (n1[i] - 1) - 48;
			ret[q] += 1;
		}
	}
	for (int i = 0; i < len2; ++i) {
		if (n2[i] != '0') {
			int q = (n2[i] - 1) - 48;
			ret[q] += 1;
		}
	}
	int _n1 = atoi(n1.c_str());
	int _n2 = atoi(n2.c_str());
	while (_n2 != 0) {
		string use;
		//个位
		int num = _n2 % 10;
		int sub = _n1 * num;
		use = to_string(sub);
		int len = use.size();
		for (int i = 0; i < len; ++i) {
			if (use[i] != '0') {
				int q = (use[i] - 1) - 48;
				ret[q] += 1;
			}
		}
		use.clear();
		//十位
		if (len2 > 1) {
			num = (_n2 % 100) - (_n2 % 10);
			num = num / 10;
			sub = _n1 * num;
			use = to_string(sub);
			len = use.size();
			for (int i = 0; i < len; ++i) {
				if (use[i] != '0') {
					int q = (use[i] - 1) - 48;
					ret[q] += 1;
				}
			}
			use.clear();
		}
		//百位
		if (len2 > 2) {
			num = _n2 / 100;
			sub = _n1 * num;
			use = to_string(sub);
			len = use.size();
			for (int i = 0; i < len; ++i) {
				if (use[i] != '0') {
					int q = (use[i] - 1) - 48;
					ret[q] += 1;
				}
			}
			use.clear();
		}
		//乘积
		sub = _n1 * _n2;
		use = to_string(sub);
		len = use.size();
		for (int i = 0; i < len; ++i) {
			if (use[i] != '0') {
				int q = (use[i] - 1) - 48;
				ret[q] += 1;
			}
		}
		use.clear();
		_n2 = 0;
	}
	for (auto x : ret)
		cout << x << " ";
	cout << endl;
	u = ret;
}

int main1() {
	int N = 0;
	cin >> N;
	vector<int> ret = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < N; ++i) {
		string n1;
		string n2;
		cin >> n1 >> n2;
		vector<int> use;
		Test1(n1, n2);
		for (int i = 0; i < 9; ++i) {
			ret[i] += u[i];
		}
		u.clear();
	}
	int num = 1;
	int max = ret[0];
	for (int i = 1; i < 9; ++i) {
		if (ret[i] > max) {
			max = ret[i];
			num = i + 1;
		}
	}
	cout << num << endl;
	return 0;
}