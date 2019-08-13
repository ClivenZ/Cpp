#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*《剑指Offer》
	将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
	但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
	数值为0或者字符串不是一个合法的数值则返回0。
*/
class Solution1 {
public:
	int StrToInt(string str) {

	}
};

/*
	编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
	不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
	你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
*/
class Solution2 {
public:
	void reverseString(vector<char>& s) {
		int p1 = 0;
		int p2 = s.size() - 1;
		while (p1 < p2) {
			swap(s[p1], s[p2]);
			p1++;
			p2--;
		}
	}
};
/*
	给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/
class Solution3 {
public:
	int firstUniqChar(string s) {
		int length = s.size();
		int i = 0;
		for (; i < length; ++i) {
			for (int j = i + 1; j < length; ++j) {
				if (s[i] == s[j])
					break;
				if (j = length - 1)
					return i;
			}
		}
	}
};
int main() {
	Solution3 s;
	s.firstUniqChar("leetcode");
	return 0;
}