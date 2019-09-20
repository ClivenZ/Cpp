#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main1() {
	int t = 0;
	cin >> t;
	vector<int> v;
	vector<string> str;
	for (int i = 0; i < t; ++i) {
		int n = 0;
		string arr;
		cin >> n;
		v.push_back(n);
		cin >> arr;
		str.push_back(arr);
	}
	for (int i = 0; i < t; ++i) {
		if (v[i] < 11) {
			cout << "NO" << endl;
		}
		else if (v[i] == 11) {
			string arr = str[i];
			if (arr[0] == '8')
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(v[i] > 11){
			string arr = str[i];
			int len = arr.size();
			for (int j = 0; j < len; ++j) {
				if (arr[j] == '8') {
					if (len - j >= 11) {
						cout << "YES" << endl;
						j = len;
					}
					else {
						cout << "NO" << endl;
						j = len;
					}
				}
				if (j == len - 1)
					cout << "NO" << endl;
			}
		}
	}
	return 0;
}