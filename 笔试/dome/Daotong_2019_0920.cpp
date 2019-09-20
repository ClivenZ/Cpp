#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main1() {
	int num = 0;
	cin >> num;
	int ret = 0;
	if (num < 0) {
		num = num * (-1);
		while (num != 0) {
			num &= num - 1;
			ret++;
		}
		cout << ret + 1 << endl;
	}
	else {
		while (num != 0) {
			num &= num - 1;
			ret++;
		}
		cout << ret << endl;
	}
	
	return 0;
}

/*
in: abceefgQ12345hgderQ123hgnbeQ456ghyt
out:abceefgText1hgderText2hgnbeText3ghyt
in: abcQ123eefgQ12345a12334hgdedferQ123b234hgnbeQ456Q231ghytQ123fderQ456fedrQ789
out:abcText1eefgText2a12334hgdedferText1b234hgnbeText3Text4ghytText1fderText3fedrText5
*/


int main2() {
	string str;
	string ret;
	map<string, string> m;
	getline(cin, str);
	char t = '#';
	str.push_back(t);
	int len = str.size();
	char num = '0';
	for (int i = 0; i < len; ++i) {
		if (str[i] == 'Q') {
			string com;
			int beg = i;
			char a = 'T';
			char b = 'e';
			char c = 's';
			char d = 't';
			for (int j = i + 1; j <= len; ++j) {
				if (str[j] <= '9' && str[i] >= '0') {
					com.push_back(str[j]);
					i = j;
				}
				else {
					i = j - 1;
					num += 1;
					j = len;
				}
			}
			ret.push_back(a);
			ret.push_back(b);
			ret.push_back(c);
			ret.push_back(d);
			ret.push_back(num);
		}
		else if(str[i] != '#') {
			ret.push_back(str[i]);
		}
	}
	for (auto x : ret)
		cout << x;
	cout << endl;
	return 0;
}


