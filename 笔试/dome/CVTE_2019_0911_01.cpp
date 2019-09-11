#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	string A;
	string B;
	vector<string> C;
	getline(cin, A);
	getline(cin, B);
	int lenA = A.size();
	int lenB = B.size();
	for (int i = 0; i < lenB; ++i) {
		for (int j = 0; j < lenA; ++j) {
			if (B[i] == A[j]) {
				char c = A[i];
				C.push_back(c);
				A.erase(i);
			}
		}
	}
	C.push_back(A);
	for (auto x : C)
		cour << x;
	cout << endl;
	return 0;
}