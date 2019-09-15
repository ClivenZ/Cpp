#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	vector<int> deadline;
	vector<int> cost;
	for (int i = 0; i < 3; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		deadline.push_back(num1);
		cost.push_back(num2);
	}
	int ret = 0;

	int len1 = deadline.size();
	int minline = 0;
	int used = 0;
	for (int i = 1; i < len1; ++i) {
		int count = 0;
		minline = deadline[0];
		if (deadline[i] < minline ) {
			minline = deadline[i];
			count = i;
		}
		if (deadline[i] == minline) {
			if (cost[i] < cost[count]) {
				minline = deadline[i];
				if (cost[i] > deadline[i]) {
					ret = cost[i] - deadline[i];
					used = cost[i];
					vector<int>::iterator itdead = deadline.begin() + i;
					vector<int>::iterator itcost = cost.begin() + i;
					deadline.erase(itdead);
					cost.erase(itcost);
				}
			}
		}
	}
	int len2 = cost.size();
	for (int i = 0; i < len2; ++i) {
		if (cost[i] >= deadline[i]) {
			if (deadline[i] - used <= 0) {
				ret = (deadline[i] - cost[i]) + used;
			}
		}
		else {
			ret = used + cost[i];
		}
	}
	cout << ret << endl;
	return 0;
}