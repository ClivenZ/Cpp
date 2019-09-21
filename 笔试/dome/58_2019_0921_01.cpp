#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;


int main() {
	int num = 0;
	cin >> num;
	vector<string> tab =
	{ "`","!","@","#","$","%","^","&","*","(",")","{","}","\\","<",">","?" };
	if (num < 27) {
		cout << to_string(num) << endl;
	}
	else {
		string str;
		int rum = num / 27;
		str = str + to_string(rum);
		int n = num - (rum * 27);
		if (n <= 10) {
			str = str + to_string(n);
		}
		else {
			n = n - 10;
			str = str + tab[n];
		}
		cout << str <<endl;
	}
	return 0;
}




int main3() {
	string user;
	string v = "MASK";
	string ret;
	getline(cin, user);
	int len = user.size();
	int rum = 0;
	for (int i = 0; i < len; ++i) {
		if (user[i + 1] != '@') {
			ret.push_back(user[i]);
			if (rum < 4) {
				ret.push_back(v[rum]);
				rum++;
			}
			else {
				rum = 0; 
				ret.push_back(v[rum]);
				rum++;
			}
		}
		else {
			ret.push_back(user[i]);
			i = len;
		}
	}
	int mun = len;
	for (int i = 0; i < len; ++i) {
		if (user[i] == '@')
			mun = i;
		if (i >= mun) {
			ret.push_back(user[i]);
		}
	}
	cout << ret << endl;
	return 0;
}