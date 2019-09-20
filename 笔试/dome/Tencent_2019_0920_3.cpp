#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main0() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	int count = 0;
	while (k != 0) {
		sort(v.begin(), v.end());
		if (v[n -1] == 0) {
			cout << 0 << endl;
		}
		else {
			for (int i = 0; i < n; ++i) {
				if (v[i] > 0) {
					cout << v[i] << endl;
					count = v[i];
					i = n;
				}
			}
			for (int i = 0; i < n; ++i) {
				if (v[i] > 0) {
					v[i] = v[i] - count;
				}
			}
		}
		k--;
	}
	return 0;
}