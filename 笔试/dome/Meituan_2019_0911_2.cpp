#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	string s = "ABAC";
	
	while (num != 0) {
		if (num < 4) {
			for (int i = 0; i < num; ++i) {
				cout << s[i];
			}
			cout << endl;
			num = 0;
		}
		else {
			for (int i = 0; i < 4; ++i) {
				cout << s[i];
			}
			cout << endl;
			num = num - 4;
		}
	}
}