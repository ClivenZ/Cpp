#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
ʵ�ֺ���int f(int a,int b,int c),�����в���������κ�if,switch,for,while֮��Ĺؼ����Լ���Ŀ���������Ҫ��
a=1ʱ����b/c��
a=2ʱ����b-c��
a=3ʱ����b�Ľ׳˼���c�Ľ׳ˣ�
a=4ʱ����b+c��
a=5ʱ����b*c (���ÿ��Ǵ����a��b��c��ֵ����������µ��쳣������߱���)��
*/
void f0(int a, int b, int c)
{
	int sum;
	(!(a ^ 1) && printf("%d\n", b + c));
	(!(a ^ 2) && printf("%d\n", b - c));
	(!(a ^ 3) && printf("%d\n", b * c));
	(!(a ^ 4) && printf("%d\n", b / c));
}

int T(int num) {
	int ret = 0;
	(!(num ^ 0) && (ret = 0));
	return num = num * (num - 1);
}

int f(int a,int b,int c) {
	int ret;
	(!(a ^ 1) && (ret = b / c));
	(!(a ^ 2) && (ret = b - c));
	(!(a ^ 3) && (ret = (T(b)) + T(c)));
	(!(a ^ 4) && (ret = b + c));
	(!(a ^ 5) && (ret = b * c));

	return ret;
}

int main() {
	string str_in;
	getline(cin, str_in);
	int len = str_in.size();
	
	return 0;
}