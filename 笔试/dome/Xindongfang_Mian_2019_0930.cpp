#include<iostream>
#include<vector>

using namespace std;

int BinarySearch(vector<int>& v, int size, int value) {
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) / 2;
		if (v[mid] < value) {
			left = mid + 1;
		}
		else if (v[mid] > value) {
			right = mid - 1;
		}
		else {
			break;
		}
	}
	if (left <= right) {
		cout << mid << endl;
	}
	else {
		cout << "Not find!" << endl;
	}
	return 1;
}

int main() {
	vector<int> v;
	int to_find = 0;
	int num = 0;
	while (cin >> num) {
		v.push_back(num);
	}
	cout << "Putin find_num:" << endl;
	cin >> to_find;
	int len = v.size();
	BinarySearch(v, len, to_find);
	return 0;
}