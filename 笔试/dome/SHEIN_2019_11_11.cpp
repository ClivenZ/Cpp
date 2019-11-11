#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
实现函数int f(int a,int b,int c),编码中不允许出现任何if,switch,for,while之类的关键词以及三目运算符，并要求：
a=1时返回b/c；
a=2时返回b-c；
a=3时返回b的阶乘加上c的阶乘；
a=4时返回b+c；
a=5时返回b*c (不用考虑传入的a，b，c的值域错误所导致的异常结果或者崩溃)。
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