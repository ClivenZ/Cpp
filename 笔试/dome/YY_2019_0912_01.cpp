#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void MinSum(vector<vector<int>>& v) {
	if (v.empty() || v[0].empty())
		return;
	int rows = v.size();
	int cols = v[0].size();
	
	vector<vector<int>> ret(rows,vector<int> (cols,0));
	vector<vector<int>> count;
 	ret[0][0] = v[0][0];
	
	for (int i = 1; i != rows; ++i) {
		ret[i][0] = v[i][0] + ret[i - 1][0];
	}
	for (int i = 1; i != cols; ++i) {
		ret[0][i] = v[0][i] + ret[0][i - 1];
	}
	vector<int> arr1;
	for (int i = 1; i < rows; ++i) {
		for (int j = 1; j < cols; ++j) {
			int num = min(ret[i - 1][j], ret[i][j - 1]);
			if (num == ret[i - 1][j]) {
				cout << i - 1 << j << endl;;
			}
			else {
				cout << i << j - 1 << endl;
			}
		}
	}
}

int main() {
	int numx, numy;
	cin >> numx >> numy;
	vector<vector<int>> v;
	vector<int> a;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	for (int j = 0; j < numx; ++j) {
		cin >> num1 >> num2 >> num3;
		a.clear();
		a.push_back(num1);
		a.push_back(num2);
		a.push_back(num3);
		v.push_back(a);
	}
	//MinSum(v);
	for (int i = 0; i < numx; ++i) {
		for (int j = 0; j < numy; ++j) {
			cout << v[i][j] ;
		}
		cout << endl;
	}
	return 0;
}