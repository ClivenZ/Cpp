#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
int main() {
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
#endif

#if 0
int main() {
	int num = 0;
	cin >> num;
	vector<int> v;
	int cur = num % 2;
	while (cur != 0) {
		v.push_back(cur);
		cur = cur % 2;
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
#endif

#if 0
int main() {
	int num = 0;
	cin >> num;
	vector<int> key;
	vector<int> value;
	for (int i = 0; i < num; ++i) {
		int k, v;
		int n = 0;
		int lenv = key.size();
		cin >> k >> v;
		for (int j = 0; j < lenv; ++j) {
			if (key[j] == k) {
				value[j] = value[j] + v;
				n = 1;
			}
		}
		if (n == 0) {
			key.push_back(k);
			value.push_back(v);
		}
		else {
			n = 0;
		}
	}
	int len = key.size();
	for (int i = 0; i < len; ++i) {
		cout << key[i] << " " << value[i] << endl;
	}
	return 0;
}
#endif

#if 0
int main() {
	string strin;
	vector<string> ret;
	string s;
	getline(cin, strin);
	int len = strin.size();
	int i = 0, j = 0, num = 0,n = 0;
	while (i <= (len - 1)) {
		while (strin[j] != ' ' && strin[j] != '\0') {
			s.push_back(strin[j]);
			++n;
			++j;
		}
		num = num + 1;
		ret.push_back(s);
		s.clear();
		++j;
		i = i + n + 1;
		n = 0;
	}
	cout << num << endl;
	for (auto x : ret)
		cout << x << endl;
	return 0;
}
#endif


#if 0
int main() {
	string strin;
	getline(cin, strin);
	vector<string> ret;
	string s;
	string n = " ";
	int lenin = strin.size();
	for (int i = lenin - 1; i >= 0; --i) {
		if (strin[i] != ' ') {
			s.push_back(strin[i]);
		}
		if (strin[i] == ' ' ||  i == 0) {
			ret.push_back(s);
			ret.push_back(n);
			s.clear();
		}
	}
	for (auto x : ret)
		cout << x ;
	cout << endl;
	return 0;
}
#endif



