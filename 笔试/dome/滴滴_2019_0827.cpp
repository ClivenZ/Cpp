//#include<iostream>
//#include<string>
//using namespace std;
//int main() {
//	string str1;
//	string str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int len = str1.size();
//	for (int i = 0; i < len; ++i) {
//		if ((str1[i] <= 'z' && str1[i] >= 'a')
//			|| (str1[i] <= 'Z' && str1[i] >= 'A')
//			|| (str1[i] <= '9') && str1[i] >= '0') {
//			str1[i] = '1';
//		}
//		else {
//			str1[i] = '0';
//		}
//	}
//	int Issm = 0;
//	for (int i = 0; i < len; ++i) {
//		if (str1[i] == str2[i])
//			Issm++;
//	}
//	float ret = 0;
//	ret = Issm / (len - 1);
//	printf("%f%%\n", ret);
//	return 0;
//}

/*
给出一个仅包含加减乘除四种运算符的算式(不含括号)，如1+2*3/4，
在保持运算符顺序不变的情况下，
现在你可以进行若干次如下操作：如果交换相邻的两个数，表达式值不变，那么你就可以交换这两个数。
现在你可以进行任意次操作，使得算式的数字序列字典序最小，
然后输出结果，数字之间的字典序定义为若a<b则a的字典序小于b。

6
3 + 2 + 1 + -4 * -5 + 1

1 + 2 + 3 + -5 * -4 + 1
*/
//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stack>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int num = 0;
//	cin >> num;
//	string str1;
//	string str2;
//	stack<char> s;
//	vector<int> v;
//	getline(cin, str1);
//	int len = str1.size();
//	for (int i = 0; i < len; ++i) {
//		if (str1[i] == '*' || str1[i] == '/') {
//			s.pop();
//		}
//		else {
//			s.push(str1[i]);
//		}
//	}
//	cout << str2 << endl;
//	return 0;
//}





/*
现在有A，B两个序列，两个序列都是拥有n个元素，你有两种操作：
1. 从A序列中选择一个非空前缀，再从B序列中选择一个非空前缀，
	要求选择的这两个前缀的末尾元素相等。把这两个前缀移除，
	这个操作将花费Cost代价，但是这个操作可以使你得到一颗宝石。

2. 您可以重复第1步的操作；最终，您需要花费两个序列剩余元素数量之和大小的代价，
	移除两个序列中剩下的所有元素（这最后一步是没有宝石的），这时游戏结束。

要求总代价不超过Total，且序列中不得有剩余，那么最多可以获得多少宝石。


5 10000 1000
1 5 4 2 3
5 4 3 2 1

3
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n = 0;
	int Total = 0;
	int Cost = 0;
	cin >> n >> Total >> Cost;
	vector<int> v1;
	vector<int> v2;
	int num1 = 0;
	int num2 = 0;
	int Mod = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num1;
		v1.push_back(num1);
	}
	for (int i = 0; i < n; ++i) {
		cin >> num2;
		v2.push_back(num2);
	}

	for (int i = n; i > 0; --i) {
		for (int j = 0; j < n; ++j) {
			if (v1[i] == v2[j]) {
				Mod = 2;
			}
		}
	}
	Mod = Mod + 1;
	cout << Mod << endl;

	return 0;
}