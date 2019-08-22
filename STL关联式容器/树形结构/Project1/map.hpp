#pragma once
#include<iostream>
#include<map>
using namespace std;

void MapTest() {

	map<string, string> m;

	//插入数据
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(make_pair("banana","香蕉"));
	m["apple"] = "苹果";

	cout << m.size() << endl;
	//用迭代器去遍历 map 中的元素，可以得到一个按照 key 排列的序列
	for (auto x : m)
		cout << x.first << "--->" << x.second << endl;
	cout << endl;

	//map 中的键值对 key 是唯一的，如果 key 存在将插入失败
	auto ret = m.insert(make_pair("peach","桃子"));
	if (ret.second)
		cout << "<peach,桃子>不在map中，以及插入" << endl;
	else
		cout << "已存在，插入失败" << ret.first->first << "--->"
		<< ret.first->second << "failed" << endl;

	//删除 key 为"apple"的元素
	m.erase("apple");

	if (m.count("apple") == 1) {
		cout << "Have" << endl;
	}
	else
		cout << "Nohave" << endl;
}

