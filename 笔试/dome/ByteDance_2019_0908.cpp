/*

*/
#include<iostream>
#include<vector>
using namespace std;

int main1() {
	int limit = 0;
	vector<int> v;
	cin >> limit;
	int num = 0;
	for (int i = 0; i < limit; ++i) {
		cin >> num;
		v.push_back(num);
	}
	if (limit == 0 || v.empty())
		return -1;
	int pos = 0;
	int count = 0;
	int begin = 0;
	int end = v.size() - 1;
	while (end != 0) {
		for (int i = end - 1; i >= 0; --i) {
			if (v[end] <= v[i]) {
				pos = i;
				count += 1;
				break;
				
			}
		}
		end -= 1;
		if (end == pos) {
			cout << v[pos] << endl;
			break;
		}
		else if(count == 0) {
			cout << count << endl;
			break;
		}
	}
	return 0;
}


