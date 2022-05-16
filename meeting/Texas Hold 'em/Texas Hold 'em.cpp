#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

std::map<std::string, int> mapinit(){
	std::map<std::string, int> m;
	m.insert(std::pair<std::string, int>("ROYAL FLUSH", 0));			//皇家同花顺
	m.insert(std::pair<std::string, int>("STRAIGHT FLUSH", 1));			//同花顺
	m.insert(std::pair<std::string, int>("FOUR OF A KIND", 2));			//四条
	m.insert(std::pair<std::string, int>("FULL HOUSE", 3));				//葫芦
	m.insert(std::pair<std::string, int>("FLUSH", 4));					//同花
	m.insert(std::pair<std::string, int>("STRAIGHT", 5));				//顺子
	m.insert(std::pair<std::string, int>("THREE OF A KIND", 6));		//三条
	m.insert(std::pair<std::string, int>("TWO PAIR", 7));				//两对
	m.insert(std::pair<std::string, int>("ONE PAIR", 8));				//一对
	m.insert(std::pair<std::string, int>("HIGH CARD", 9));				//高牌
	return m;
}

std::string deter_res(int num1, int num2) {
	std::string str;
	if (num1 == 0) {
		if (num2 == 1) {
			str = "ROYAL FLUSH";
		}
		else if (num2 == 2) {
			str = "STRAIGHT FLUSH";
		}
		else if(num2 == 8){
			str = "FLUSH";
		}
	}
	else {
		if (num2 == 1 || num2 == 2) {
			str = "STRAIGHT";
		}
		else if (num2 == 3) {
			str = "FOUR OF A KIND";
		}
		else if (num2 == 4) {
			str = "FULL HOUSE";
		}
		else if (num2 == 5) {
			str = "THREE OF A KIND";
		}
		else if (num2 == 6) {
			str = "TWO PAIR";
		}
		else if (num2 == 7) {
			str = "ONE PAIR";
		}
		else if (num2 == 8) {
			str == "HIGH CARD";
		}
	}
	return str;
}

int rules(std::string &s) {
	int ret = 0;
	std::map<std::string, int> m = mapinit();
	std::map<std::string, int>::const_iterator it= m.begin();
	it = m.find(s);
	if (it != m.end()) {
		ret = it->second;
	}	
	return ret;
}

int in_array(std::vector<char> &v, char c) {
	int ret = 0;
	std::vector<char>::iterator it = v.begin();
	while (it != v.end()) {
		if (*it == c) {
			ret = 1;
			break;
		}
		++it;
	}
	return ret;
}

std::string modify_head(std::string& str) {
	std::string ret_str;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] != '1') {
			ret_str += str[i];
		}
		else
		{
			ret_str += 'T';   //用T来代表十
			i += 1;
		}
	}
	return ret_str;
}

int num_modify(char c) { 
	int ret = 0;
	if (c != 'T' && c != 'J' && c!= 'Q' && c != 'K' && c != 'A') {
		ret = c - 48;
	}
	else {
		if (c == 'T') {
			ret = 10;
		}
		else if(c == 'J'){
			ret = 11;
		}
		else if (c == 'Q') {
			ret = 12;
		}
		else if (c == 'K') {
			ret = 13;
		}
		else if (c == 'A') {
			ret = 14;
		}
	}
	return ret;
}

std::string play_compare(std::string& str) {
	int p1 = 0;  //用于标记花色   0-同花 1-非同花
	int p2 = 0;  //用户标记数字   1-皇家同花 2-顺子 3-4同 4-(3同&4同) 5-三同 6-两对 7-一对 8-无序
	std::string ret_str;
	std::vector<char> v1 = { 's', 'h', 'c', 'd' };
	std::stack<char> head_stk1;
	std::vector<int> head_v2;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] != ' ') {
			if (in_array(v1, str[i])) {
				head_stk1.push(str[i]);
			}
			else {
				head_v2.push_back(num_modify(str[i]));
			}
		}
	}
	//先处理花色
	char cur_c = head_stk1.top();
	head_stk1.pop();
	while (!head_stk1.empty()) {
		if (head_stk1.top() != cur_c) {
			p1 = 1;
			break;
		}
		else {
			head_stk1.pop();
		}
	}
	//处理数字
	sort(head_v2.begin(), head_v2.end());

	//判断是否为皇家顺
	std::vector<int> huangjia_v = { 10,11,12,13,14 };
	if (head_v2 == huangjia_v) {
		p2 = 1;
	}

	for (size_t i = 0; i < head_v2.size(); ++i) {
		if (head_v2[i] == 14) {
			head_v2[i] = 1;
			sort(head_v2.begin(), head_v2.end());
			break;
		}
	}

	//判断是否为顺子
	if (p2 == 0) {
		int cut_num = head_v2[0];
		for (size_t i = 1; i < head_v2.size(); ++i) {
			if (cut_num == (head_v2[i] - 1)) {
				cut_num = head_v2[i];
			}
			else {
				p2 = -1;
				break;
			}
		}
	}

	if (p2 < 0) {
		int cut_num = head_v2[0];
		//最多为两对 定义四个栈用于存储结果进行判断
		std::stack<int> s1;
		s1.push(cut_num);
		std::stack<int> s2;
		std::stack<int> s3;
		std::stack<int> s4;
		for (size_t i = 1; i < head_v2.size(); ++i) {
			if (head_v2[i] == s1.top()) {
				s1.push(head_v2[i]);
			}
			else {
				if (s2.empty()) {
					s2.push(head_v2[i]);
				}
				else {
					if (head_v2[i] == s2.top()) {
						s2.push(head_v2[i]);
					}
					else {
						if (s3.empty()) {
							s3.push(head_v2[i]);
						}
						else if(head_v2[i] == s3.top()){
							s3.push(head_v2[i]);
						}
						else {
							if (s4.empty()) {
								s4.push(head_v2[i]);
							}
							else if(head_v2[i] == s4.top()){
								s4.push(head_v2[i]);
							}
						}
					}
				}
			}
		}

		if (s1.size() == 4 || s2.size() == 4) {
			p2 = 3;
		}
		else if ((s1.size() == 2 && s2.size() == 3) || (s1.size() == 3 && s2.size() == 2)) {
			p2 = 4;
		}
		else if (s1.size() == 3 || s2.size() == 3 || s3.size() == 3){
			p2 = 5;
		}
		else if ((s1.size() == 2 && s2.size() == 2)
			|| (s1.size() == 2 && s3.size() == 2)
			|| (s2.size() == 2 && s3.size() == 2)) {
			p2 = 6;
		}
		else if (s1.size() == 2 || s2.size() == 2 || s3.size() == 2 || s4.size() == 2) {
			p2 = 7;
		}
		else {
			p2 = 8;
		}
	}
	else if( p2 != 1){
		p2 = 2;
	}
	ret_str = deter_res(p1, p2);
	return ret_str;
}

int compare_hands(const std::string &hand1, const std::string &hand2) {
	int ret = 0;
	if (hand1.compare(hand2) == 0) {
		return ret;
	}
	//参数处理
	std::string str1 = hand1;
	str1 = modify_head(str1);
	std::string str2 = hand2;
	str2 = modify_head(str2);

	//解析参数
	std::string ret_str_1 = play_compare(str1);
	std::string ret_str_2 = play_compare(str2);

	//结果比较
	int ret1 = rules(ret_str_1);
	int ret2 = rules(ret_str_2);

	if (ret1 < ret2) {
		ret =  1;
	}
	else if (ret1 > ret2) {
		ret = -1;
	}
	return ret;
}

int main()
{
	std::string s1 = "c2 c3 cA c5 c6";
	std::string s2 = "s2 d2 hQ sQ cQ";
	int ret = compare_hands(s1, s2);
	std::cout << ret << std::endl;
	return 0;
}
