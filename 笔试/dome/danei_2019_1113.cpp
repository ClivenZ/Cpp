#include<stdio.h>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

float oper(float f1, float f2, char op)
{
	if (op == '+')
		return f1 + f2;
	else if (op == '-')
		return f1 - f2;
	else if (op == '*')
		return f1 * f2 * 1.0;
	else if (op == '/')
		return f1 * 1.0 / f2;
}
int main()
{
	stack<float> s;
	string prefixExp;
	getline(cin, prefixExp);

	int strLen = prefixExp.length();
	int temp, i, j;
	int t1, t2;
	for (i = strLen - 1; i >= 0; i--)
	{
		string digitStr = "";

		if (prefixExp[i] == '+' || prefixExp[i] == '-' || prefixExp[i] == '*' || prefixExp[i] == '/') //运算符
		{
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			if (t2 == 0 && prefixExp[i] == '/')
			{
				printf("ERROR\n");
				return 0;
			}
			s.push(oper(t1, t2, prefixExp[i]));
			// printf("%f\n",s.top());	
			i--;//下一位肯定是空格
		}
		else  //运算数
		{
			while (i >= 0 && prefixExp[i] != ' ') //不要漏掉i>=0条件
			{
				digitStr = prefixExp[i] + digitStr;
				i--;
			}
			//printf("atof:%f\n",atof(digitStr.c_str()));	
			s.push(atof(digitStr.c_str()));
		}

	}
	if (s.size() == 1)
		printf("%0.1f\n", s.top());
	else
		printf("ERROR\n");
	return 0;
}