#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<map>

using namespace std;

int main() {
	int num = 0;
	cin >> num;
	vector<int> kc;
	map<string,int> m;
	for (int i = 0; i < num; ++i) {
		int n = 0;
		cin >> n;
		kc.push_back(n);
		for (int j = 0; j < n; ++j) {
			string str;
			int s = 0;
			cin >> str >> s; 
			m.insert(pair<string, int>(str, s));
		}
	}
	int sum = 0;
	for (auto x : kc) {
		sum = sum + x;
	}
	cout << sum << endl;
	return 0;
}