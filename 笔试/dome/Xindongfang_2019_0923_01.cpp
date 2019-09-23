#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string strin;
	getline(cin, strin);
	int lenin = strin.size();
	cout << '{' << endl;
	int num = 0;
	int count = 0;
	for (int i = lenin - 1; i > 0; --i) {
		if (strin[i] >= '0' && strin[i] <= '9') {
			if (count == 0) {
				cout << "\"id\": " << strin[i] << "," << endl;
				count = 1;
			}
			else if (count == 1) {
				cout << "\"pid\": " << strin[i] << "," << endl;
				count = 2;
			}
			else if (count == 2) {
				cout << "\"data\": " << strin[i] << "," << endl;
				count = 3;
				if (count == 3) {
					cout << "\"children\"" << ": [" << endl;
					cout << "{" << endl;
					num += 1;
					count = 0;
				}
			}
		}
	}
	for (int i = 1; i < num; ++i) {
		cout << "}" << endl;
		cout << "]" << endl;
	}
	cout << '}' << endl;
	return 0;
}