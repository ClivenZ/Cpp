#include<iostream>
#include<vector>
using namespace std;
void TestFun(vector<int>& v, int n);
int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n = 0;
		vector<int> v;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int num = 0;
			cin >> num;
			v.push_back(num);
		}
		TestFun(v, n);
	}
	return 0;
}
void TestFun(vector<int>& v, int n) {
	int sum = 0;
	int len = 0;
	int mlen = 0;
	if (v[1] >= v[0]) {
		sum = v[0] + v[1];
		len = 2;
	}
	else {
		sum = v[1];
		len = 1;
	}
	for (int i = 2; i < n; ++i) {
		if (v[i] >= sum) {
			len += 1;
			sum = sum + v[i];
		}
		else {
			mlen = len;
			len = 1;
			sum = v[i];
		}
	}
	if (len >= mlen) {
		cout << len << endl;
	}
	else {
		cout << mlen << endl;
	}
}