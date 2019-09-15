#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	vector<int> a;
	int count = 0;
	a.push_back(0);
	for (int i = 1; i <= N; ++i) {
		int num = 0;
		cin >> num;
		a.push_back(num);
	}
	count = count + A;
	int ptr = a[1];
	while (ptr != a[N]) {
		count = count + B;
		ptr = a[ptr - 1];
		if (a[ptr] < N) {
			count = count + B;
			a[ptr] += 1;
			count = count + A;
			ptr = a[a[ptr]];
		}
		else {
			count = count + B;
			a[ptr] -= 1;
			count = count + A;
			ptr = a[a[ptr]];
		}
	}
	cout << count << endl;
	return 0;
}
