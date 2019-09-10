#include<iostream>
#include<vector>
using namespace std;
int main1() {
	int ret = 0;
	int count = 0;
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		arr.push_back(num);
	}
	while (k > 0) {
		for (int i = 0; i < n; ++i) {
			if (arr[i] == k) {
				ret++;
			}
		}
		if (ret % 2 != 0 && ret != 1) {
			ret = (ret - 1) / 2 + 1;
		}
		else if (ret == 1) {
			ret = 1;
		} 
		else{
			ret = ret / 2;
		}
		count = count + ret;
		ret = 0;
		k--;
	}
	cout << count << endl;
	return 0;
}