#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int>> v;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int num = 0;
			cin >> num;
			v[i][j] = num;
		}
	}
	int count = v[0][0];
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (v[i][j + 1] > v[i + 1][j]) {
			count = count + v[i][j + 1];
			j = j + 1;
		}
		else if(v[i][j + 1] < v[i + 1][j]) {
			count = count + v[i + 1][j];
			i = i + 1;
		}
	}
	cout << count << endl;
}