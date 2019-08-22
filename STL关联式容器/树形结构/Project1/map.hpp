#pragma once
#include<iostream>
#include<map>
using namespace std;

void MapTest() {

	map<string, string> m;

	//��������
	m.insert(pair<string, string>("peach", "����"));
	m.insert(make_pair("banana","�㽶"));
	m["apple"] = "ƻ��";

	cout << m.size() << endl;
	//�õ�����ȥ���� map �е�Ԫ�أ����Եõ�һ������ key ���е�����
	for (auto x : m)
		cout << x.first << "--->" << x.second << endl;
	cout << endl;

	//map �еļ�ֵ�� key ��Ψһ�ģ���� key ���ڽ�����ʧ��
	auto ret = m.insert(make_pair("peach","����"));
	if (ret.second)
		cout << "<peach,����>����map�У��Լ�����" << endl;
	else
		cout << "�Ѵ��ڣ�����ʧ��" << ret.first->first << "--->"
		<< ret.first->second << "failed" << endl;

	//ɾ�� key Ϊ"apple"��Ԫ��
	m.erase("apple");

	if (m.count("apple") == 1) {
		cout << "Have" << endl;
	}
	else
		cout << "Nohave" << endl;
}

