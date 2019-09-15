#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main1() {
	string r;
	vector<int> ret;
	getline(cin, r);
	int len = r.size();
	for (int i = 0; i < len; ++i) {
		ret.push_back(1);
	}
	for (int i = 0; i < len; ++i) {
		if (r[i] == 'R') {
			ret[i + 1] += 1;
			ret[i] -= 1;
		}
		else if (r[i] == 'L') {
			ret[i - 1] += 1;
			ret[i] -= 1;
		}
	}
	int rem = 0;
	int num = 0;
	int m = 100;
	while (m != 1000) {
		for (int i = 0; i < len; ++i) {
			if (i < len - 1) {
				rem = ret[i + 1];
			}
			if (ret[i] != 0) {
				if (r[i] == 'R') {
					ret[i + 1] += num;
					ret[i] -= num;
				}
				else if (r[i] == 'L') {
					ret[i - 1] += num;
					ret[i] -= num;
				}
			}
			num = rem;
		}
		m += 100;
	}
	for (auto x : ret)
		cout << x << ' ';
	cout << endl;
	return 0;
}

int main() {
	string str;
	getline(cin,str);
	int count = 0;
	int len = str.size();
	for (int i = 0; i < len;++i) {
		if (str[i] == '?') {
			
		}
	}
	return 0;
}