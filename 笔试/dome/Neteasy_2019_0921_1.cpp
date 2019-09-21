#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void Find2(vector<int>& v, vector<int> b) {
	sort(v.begin(), v.end());
	v.push_back(0);
	int lenv = v.size();
	int lenb = b.size();
	map<int, int> my;
	int num = 0;
	for (int i = 1; i < lenv; ++i) {
		int j = i - 1;
		if (v[i] != v[j]) {
			num += 1;
			my.insert(pair<int, int>(v[j], num));
			num = 0;
		}
		else {
			num += 1;
		}
	}
	for (int i = 0; i < lenb; ++i) {
		int count = 0;
		int ret = 0;
		for (auto x : my) {
			if (x.first == b[i]) {
				cout << x.second << endl;
				ret = 1;
			}
		}
		if (ret == 1) {
			ret = 0;
		}
		else if (ret == 0) {
			cout << count << endl;
		}
	}
}

void Find(vector<int>& v, vector<int>& b) {
	int lenv = v.size();
	int lenb = b.size();
	for (int j = 0; j < lenb; ++j) {
		int count = 0;
		for (int i = 0; i < lenv; ++i) {
			if (v[i] == b[j]) {
				count += 1;
			}
		}
		cout << count << endl;
	}	
}
int main1() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < m; ++i) {
		int boss = 0;
		cin >> boss;
		b.push_back(boss);
	}
	Find2(v, b);
	return 0;
}