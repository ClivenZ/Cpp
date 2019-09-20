#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main5() {
	int num = 0;
	cin >> num;
	vector<int> Q;
	vector<int> N;
	for (int i = 0; i < num;++i) {
		int n = 0;
		cin >> n;
		Q.push_back(n);
	}
	for (int i = 0; i < num; ++i) {
		int n = 0;
		cin >> n;
		N.push_back(n);
	}
	int sum = 0;
	int count = (Q[0]+N[0])^(Q[0]+N[1]);
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			sum = Q[i] + N[j];
			if (j < 2) {
				if (i > 0) {
					count = count ^ sum;
				}
			}
			else {
				count = count ^ sum;
			}
		}
	}
	cout << count << endl;
}