#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main1() {
	int N, M;
	cin >> N >> M;
	vector<int> h;
	for (int i = 0; i < N; ++i) {
		int num = 0;
		cin >> num;
		h.push_back(num);
	}
	int i = 0, j = N - 1;
	double sum = 0;
	double max = 0;
	while (j - i >= M) {
		double ret = 0;
		double m = 0;
		for (int n = i; n < j; ++n) {
			sum = sum + h[n];
			m++;
			if (m == M)
				n = j + 1;
		}
		ret = sum / m;
		if (ret > max)
			max = ret;
		i++;
		sum = 0;
	}
	printf("%.3f", max);
	return 0;
}

double Nd2_S(int a,int t,int v0) {
	double s = 0;
	s = v0 * t + 0.5 * a * t * t;
	return s;
	
}
double Nd2_V(int a, int t, int v0) {
	double vt = 0;
	vt = v0 + a * t;
	return vt;
}

int main2() {
	int n = 0;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		int a0, t0;
		cin >> a0 >> t0;
		m.insert(pair<int, int>(a0, t0));
	}
	
	
	return 0;
}