#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main2() {
	int N = 0;
	cin >> N;
	vector<int> arr;
	vector<int> s;
	vector<int> ret;
	for (int i = 0; i < (2 * N); ++i) {
		int num = 0;
		cin >> num;
		arr.push_back(num);
	}
	//1、计算面积
	for (int i = 1; i < (2 * N); i += 2) {
		int j = i - 1;
		int sq = arr[i] * arr[j];
		s.push_back(sq);
	}
	sort(s.begin(), s.end());
	int num = 0;
	while (ret.size() != arr.size()) {
		for (int i = 1; i < (2 * N); i += 2) {
			int j = i - 1;
			int sq = arr[i] * arr[j];
			if (sq == s[num]) {
				ret.push_back(arr[j]);
				ret.push_back(arr[i]);
				arr[j] = 0;
				arr[i] = 0;
				num++;
				i = (2 * N) + 1;
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		int j = i - 1;
		int reth = 0;
		int retw = 0;
		if (s[i] == s[j]) {
			//2、计算宽高比
			double cur1 = min(ret[2 * i] / ret[2 * i + 1], ret[2 * i + 1] / ret[2 * i]);
			double cur2 = min(ret[2 * j] / ret[2 * j + 1], ret[2 * j + 1] / ret[2 * j]);
			if (cur1 > cur2) {
				retw = ret[2 * i];
				ret[2 * i] = ret[2 * j];
				ret[2 * j] = retw;
				reth = ret[2 * i + 1];
				ret[2 * i + 1] = ret[2 * j + 1];
				ret[2 * j + 1] = reth;
			}
			else if (cur1 == cur2) {
				//比较宽度
				if (ret[2 * i] < ret[2 * j]) {
					retw = ret[2 * i];
					ret[2 * i] = ret[2 * j];
					ret[2 * j] = retw;
					reth = ret[2 * i + 1];
					ret[2 * i + 1] = ret[2 * j + 1];
					ret[2 * j + 1] = reth;
				}
			}
		}
	}
	for (int i = 2; i < (2 * N); i += 2) {
		int j = i - 2;
		if (s[i / 2] == s[j / 2]) {
			if (min(ret[i] / ret[i + 1], ret[i + 1] / ret[i])
				>= min(ret[j] / ret[j + 1], ret[j + 1] / ret[j])) {
				if (ret[i] < ret[j]) {
					int reth = 0;
					int retw = 0;
					retw = ret[i];
					ret[i] = ret[j];
					ret[j] = retw;
					reth = ret[i + 1];
					ret[i + 1] = ret[j + 1];
					ret[j + 1] = reth;
				}
			}
		}
	}
	for (int i = 1; i < (2 * N); i += 2) {
		int j = i - 1;
		cout << ret[j] << ' ' << ret[i] << ' ';
	}
	cout << endl;
	return 0;
}
