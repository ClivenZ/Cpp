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
����һ���������Ӽ��˳��������������ʽ(��������)����1+2*3/4��
�ڱ��������˳�򲻱������£�
��������Խ������ɴ����²���������������ڵ������������ʽֵ���䣬��ô��Ϳ��Խ�������������
��������Խ�������β�����ʹ����ʽ�����������ֵ�����С��
Ȼ��������������֮����ֵ�����Ϊ��a<b��a���ֵ���С��b��

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
������A��B�������У��������ж���ӵ��n��Ԫ�أ��������ֲ�����
1. ��A������ѡ��һ���ǿ�ǰ׺���ٴ�B������ѡ��һ���ǿ�ǰ׺��
	Ҫ��ѡ���������ǰ׺��ĩβԪ����ȡ���������ǰ׺�Ƴ���
	�������������Cost���ۣ����������������ʹ��õ�һ�ű�ʯ��

2. �������ظ���1���Ĳ��������գ�����Ҫ������������ʣ��Ԫ������֮�ʹ�С�Ĵ��ۣ�
	�Ƴ�����������ʣ�µ�����Ԫ�أ������һ����û�б�ʯ�ģ�����ʱ��Ϸ������

Ҫ���ܴ��۲�����Total���������в�����ʣ�࣬��ô�����Ի�ö��ٱ�ʯ��


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