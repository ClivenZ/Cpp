#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main2() {
	int num = 0;
	cin >> num;
	if (num == 0) {
		cout << 0 << endl;
		return 0;
	}else if(num == 1){
		cout << 1 << endl;
		return 0;
	}
	vector<int> v;
	for (int i = 0; i < num; ++i) {
		int cur = 0;
		cin >> cur;
		v.push_back(cur);
	}
	sort(v.begin(), v.end());
	int ret = 2;
	int cur = 1, ptr = 0,count = 0,mer = 0;
	int maxlen = ret;
	while (cur != (num - 1)) {
		count = v[1] - v[0];
		ptr = cur + 1;
		mer = v[ptr] - v[cur];
		if (mer == count) {
			ret += 1;
		}
		else {
			count = mer;
			if (ret > maxlen) {
				maxlen = ret;
			}
			ret = 2;
		}
		cur += 1;
	}
	if (maxlen > ret) {
		ret = maxlen;
	}
	cout << ret << endl;
	return 0;
}


vector<string> tab = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

void dfs(vector<string>& ret,string s,int len,string str) {
	if (len == s.size()) {
		ret.push_back(str);
	}
	else {
		int pos = s[len] - '0';
		for (int i = 0; i < tab[pos].size(); ++i) {
			str.push_back(tab[pos][i]);
			len++;
			dfs(ret,s,len,str);
			len--;
			str.pop_back();
		}
	}
}

int main() {
	string num;
	getline(cin, num);
	if (num.size() == 0)
		return 0;
	vector<string> ret;
	dfs(ret, num, 0, "");
	cout << "[";
	int leng = ret.size();
	for (int i = 0; i < leng; ++i) {
		cout << ret[i];
		if (i != (leng - 1))
			cout << ", ";
	}
	cout << "]" <<endl;
	return 0;
}