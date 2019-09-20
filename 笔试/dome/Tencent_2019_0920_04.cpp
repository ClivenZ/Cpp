#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
void Test(int len,vector<T>& s) {
	int sumq = 0;
	int sumh = 0;
	int min = 0;
	for (int i = 0; i < len; ++i) {
		sumq = sumq + s[i];
		for (int j = i + 1; j < len; ++j) {
			sumh = sumh + s[j];
		}
	}
}

int main() {
	int t = 0;
	cin >> t;
	int num = 0;
	vector<int> s;
	for (int i = 0; i < t; ++i) {
		cin >> num;
		int n = 0;
		cin >> n;
		s.push_back(n);

	}
	return 0;
}