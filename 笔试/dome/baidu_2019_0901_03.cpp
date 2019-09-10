#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Used(int num) {
	if (num == 1)
		return 2;
	else if (num == 2 || num == 3 || num == 5)
		return 5;
	else if (num == 4)
		return 4;
	else if (num == 6)
		return 6;
	else if (num == 7)
		return 3;
	else if (num == 8)
		return 7;
	else if (num == 9)
		return 9;
	else
		return -1;
}

int main() {
	int  n, m;
	vector<int> arr;
	vector<int> ret;
	cin >> n >> m;
	int array[] = { 1,7,4,2,3,5,6,8,9 };
	for (int i = 0; i < m; ++i) {
		int num = 0;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int len = arr.size() - 1;
	for (int i = len; i >= 0; --i) {
		if (arr[i] == 7) {
			int num = arr[i];
			num = Used(num);
			n = n - num;
			if (n >= 0) {
				ret.push_back(num);
			}
		}
	}
	while (n > 0 ) {
		ret.push_back(1);
		n = n - 1;
	}
	for (auto x : ret)
		cout << x;
	cout << endl;
	return 0;
}