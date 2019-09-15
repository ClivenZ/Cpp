#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double MinFun(double num,double count) {
	double FunRet = count / num;
	return FunRet;
}
int RetCount(int num) {
	int count = 1;
	for (int i = num - 1; i > 0; --i) {
		int cur = num % i;
		if (cur != 0 && abs(cur) == 1) {
			count += 1;
		}
	}
	return count;
}
int main23() {
	int num = 0;
	cin >> num;
	vector<int> y;
	vector<double> ret;
	y.push_back(1);
	for (int i = num - 1; i > 0; --i) {
		int cur = i % num;
		if (cur != 0 && abs(cur) == 1) {
			y.push_back(i);
		}
	}
	int len = y.size();
	for (int i = 0; i < len; ++i) {
		int count = 1;
		count = RetCount(y[i]);
		int n = y[i];
		double Funout = MinFun(n, count);
		ret.push_back(Funout);
	}
	double numret = MinFun(num, RetCount(num));
	ret.push_back(numret);
	sort(ret.begin(), ret.end());
	printf("%.6f",ret[0]);
	return 0;
}