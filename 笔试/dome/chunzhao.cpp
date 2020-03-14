#if 1
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
	vector<int> v;
	int num = 0;
	int a = 0;
	while (1) {
		cin >> num;
		v.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	cin >> a;
	vector<int> vyu;
	//取余a&(b-1)
	for (int i = 0; i < v.size(); ++i) {
		int count = (int)fmod(v[i],a);
		vyu.push_back(count);
	}
	//记录余数相同的位置
	vector<int> ret;
	for (int i = 0; i < v.size();i += 2) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (vyu[i] == vyu[j]) {
				ret.push_back(v[i]);
				ret.push_back(v[j]);
			}
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < vyu.size(); ++i) {
		cout << vyu[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>

using namespace std;

struct Node
{
	int value;
	Node* next;
};

Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)return head;
	Node * fir = head;
	Node * sec = head->next;
	Node * thi = sec->next;
	while (1) {
		swap(sec->value, fir->value);
		if (thi == NULL || thi->next == NULL)return head;
		fir = thi;
		sec = thi->next;
		thi = thi->next->next;
	}
	return head;
}
int main() {
	vector<int> v;
	int num = 0;
	while (cin >> num && num != -1) {
		v.push_back(num);
	}
	Node* nodehead = new Node;
	nodehead->value = v[0];
	Node* pnode = new Node;
	nodehead->next = pnode;
	pnode->value = v[1];
	Node* curr = pnode;
	for (int i = 2; i < v.size(); ++i) {
		if (v[i] == -1) {
			pnode->next = NULL;
			i = v.size();
		}
		Node* pnnode = new Node;
		curr->next = pnnode;
		pnnode->value = v[i];
		curr = pnnode;
	}
	curr->next = NULL;
	reverse(nodehead);
	Node* cur = new Node;
	cur = nodehead;
	while (cur != NULL) {
		cout << cur->value << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}
#endif