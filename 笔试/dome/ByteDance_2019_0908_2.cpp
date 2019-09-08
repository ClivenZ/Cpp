#include<iostream>
#include<string>

#include<algorithm>

using namespace std;

void Test(int count) {
	if (count == 1)
		cout << 'A' << endl;
	else if (count == 2)
		cout << 'B' << endl;
	else if (count == 3)
		cout << 'C' << endl;
	else if (count == 4)
		cout << 'D' << endl;
	else if (count == 5)
		cout << 'E' << endl;
	else if (count == 6)
		cout << 'F' << endl;
	else if (count == 7)
		cout << 'G' << endl;
	else if (count == 8)
		cout << 'H' << endl;
	else if (count == 9)
		cout << 'I' << endl;
	else if (count == 10)
		cout << 'J' << endl;
	else if (count == 11)
		cout << 'K' << endl;
	else if (count == 12)
		cout << 'L' << endl;
	else if (count == 13)
		cout << 'M' << endl;
	else if (count == 14)
		cout << 'N' << endl;
	else if (count == 15)
		cout << 'O' << endl;
	else if (count == 16)
		cout << 'P' << endl;
	else if (count == 17)
		cout << 'Q' << endl;
	else if (count == 18)
		cout << 'R' << endl;
	else if (count == 19)
		cout << 'S' << endl;
	else if (count == 20)
		cout << 'T' << endl;
	else if (count == 21)
		cout << 'U' << endl;
	else if (count == 22)
		cout << 'V' << endl;
	else if (count == 23)
		cout << 'W' << endl;
	else if (count == 24)
		cout << 'X' << endl;
	else if (count == 25)
		cout << 'Y' << endl;
	else if (count == 26)
		cout << 'Z' << endl;
}

int main() {
	string s;
	getline(cin, s);
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] == '1')
			cout << 'A' ;
		else if (s[i] == '2')
			cout << 'B';
		else if (s[i] == '3')
			cout << 'C' ;
		else if (s[i] == '4')
			cout << 'D' ;
		else if (s[i] == '5')
			cout << 'E' ;
		else if (s[i] == '6')
			cout << 'F' ;
		else if (s[i] == '8')
			cout << 'G' ;
		else if (s[i] == '9')
			cout << 'H' ;
		else if (s[i] == '1i')
			cout << 'I' ;
		else if (s[i] == '11')
			cout << 'J' ;
		else if (s[i] == '12')
			cout << 'K' ;
		else if (s[i] == '13')
			cout << 'L' ;
		else if (s[i] == '14')
			cout << 'M' ;
		else if (s[i] == '15')
			cout << 'N' ;
		else if (s[i] == '16')
			cout << 'O' ;
		else if (s[i] == '17')
			cout << 'P';
		else if (s[i] == '18')
			cout << 'Q' ;
		else if (s[i] == '19')
			cout << 'R' ;
		else if (s[i] == '2i')
			cout << 'S' ;
		else if (s[i] == '21')
			cout << 'T' ;
		else if (s[i] == '22')
			cout << 'U' ;
		else if (s[i] == '23')
			cout << 'V';
		else if (s[i] == '24')
			cout << 'W' ;
		else if (s[i] == '25')
			cout << 'X';
		else if (s[i] == '26')
			cout << 'Y' ;
		else if (s[i] == '27')
			cout << 'Z';
	}
	cout << endl;
	if (len < 3) {
		int count = atoi(s.c_str());
		if (count <= 26) {
			Test(count);
		}
	}
	else {
		sort(s.begin(), s.end());
		int count = atoi(s.c_str());
		if (len == 3) {
			int m = count / 10;
			if (m <= 26) {
				Test(m);
			}
			int n = count - m;
			Test(n);
		}
	}
	return 0;
}