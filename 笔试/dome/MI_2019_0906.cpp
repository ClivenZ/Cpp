/*
1、在某个存储介质以如下形式保存一棵二叉树

1(2(3,4(,5)),6(7,))

上述序列表示的二叉树如下

观察后可以发现，每个节点的格式为

X，X可以为空

或者

X(Y, Z)，其中X不为空

请编写程序将以上述格式输入的二叉树输出为中序遍历顺序

入:1(2(3,4(,5)),6(7,))
出:3245176

*/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/


string solution(string input) {


}
/******************************结束写代码******************************/


int main() {
	string res;

	string _input;
	getline(cin, _input);

	res = solution(_input);
	cout << res << endl;

	return 0;

}



/*
2、小米之家有很多米粉喜欢的产品，产品种类很多，价格也不同。

比如某签字笔1元，某充电宝79元，某电池1元，某电视1999元等

假设库存不限，小明去小米之家买东西，要用光N元预算的钱，请问他最少能买几件产品？

输入:第1行为产品种类数

接下来的每行为每种产品的价格

最后一行为预算金额
2
500
1
1000

输出:2
*/