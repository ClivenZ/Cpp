#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		int num1,num2;
		cin >> num1 >> num2;
		m.insert(pair<int, int>(num1, num2));
	}
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		for (auto x : m) {
			if (x.first == num) {
				cout << x.second << endl;
			}
		}
	}
	return 0;
}