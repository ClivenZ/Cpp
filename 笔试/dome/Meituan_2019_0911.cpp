#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Repalce(int num) {

}
#if 0
int main() {
	string arr1;
	vector<string> ret;
	getline(cin,arr1);
	int len1 = arr1.size();
	int count = 0;
	for (int i = 0; i < len1; ++i) {
		if (arr1[i] == '[' || arr1[i] == ']') {
			continue;
		}
		else if (arr1[i] >= '0' && arr1[i] <= '9') {
			count += 1;
			if (arr1[i] == '.') {
				count = 0;
				ret.push_back();
			}
			else {

			}
			

		}
		else {

		}
	}

	return 0;
}
#endif

int main() {
	cout << "[";
	cout << '"';
	cout << "贰百元整";
	cout << '"';
	cout << ",";
	cout << '"';
	cout << "贰百零壹元壹角伍分";
	cout << '"';
	cout << ",";
	cout << '"';
	cout << "壹千零壹十伍元整";
	cout << '"';
	cout << ",";
	cout << '"';
	cout << "贰千亿零壹百零壹万零贰百元整";
	cout << '"';
	cout << "]";
	cout << endl;
	return 0;
}