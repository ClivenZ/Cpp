#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*����ָOffer��
	��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�
	����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯����
	��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
*/
class Solution1 {
public:
	int StrToInt(string str) {

	}
};

/*
	��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
	��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
	����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
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
	����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
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