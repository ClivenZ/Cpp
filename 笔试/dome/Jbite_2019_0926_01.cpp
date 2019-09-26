#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	int left = 0;
	int right = 0;
	for (int i = num; i > 0; --i) {
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				break;
			}
			else if (j == (i - 1)) {
				left = i;
			}
		}
		if (left != 0)
			i = 0;
	}
	int i = num + 1;
	while( i != 0) {
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				break;
			}
			else if(j == (i -1 )){
				right = i;
			}
		}
		if (right != 0)
			i = 0;
		else
			++i;
	}
	int max = num - left;
	int ret = left;
	if ((right - num) > max) {
		max = right - num;
		ret = right;
	}
	cout << ret << endl;
	return 0;
}