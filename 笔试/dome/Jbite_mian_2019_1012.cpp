#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//template<typename T>
//class A {
//public:
//	int a;
//	T t;
//};
//template<typename T>
//class B :public A<T> {
//public:
//	int b;
//};
//template<typename T>
//void proc(shared_ptr<A<T>> a) {
//	cout << a->a << endl;
//}

bool F()
{
	uint8_t a[] = {0x12,0x34,0x56,0x78};
	return  *(uint32_t*)a == 0x78563412;
}

struct Rect {
	int id;
	int w, h;
	bool operator<(const Rect& a)const {
		if (id == a.id) {
			if (w == a.w)
				return (h < a.h);
			else
				return (w < a.w);
		}
		else
			return (id < a.id);
	}
};
struct RectExt {
	int id;
	int w, h;
};
bool cmp(const RectExt &a,const RectExt &b) {
	if (a.id == b.id) {
		if (a.w == b.w)
			return (a.h > b.h);
		else
			return (a.w > b.w);
	}
	else {
		return (a.id > b.id);
	}
}



struct Node {
	int data;
	Node* next;
};
Node* Merge(Node* head1,Node* head2) {
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	Node* pNode = nullptr;
	if (head1->data < head2->data) {
		pNode = head1;
		pNode->next = Merge(head1->next, head2);
	}
	else {
		pNode = head2;
		pNode->next = Merge(head1, head2->next);
	}
	return pNode;
}
struct BNode {
	int value;
	BNode* left;
	BNode* right;
};

BNode* FindMin(BNode* root) {
	int min = root->value;
	BNode* pNode = root;
	if (root->left->value < min) {
		min = root->left->value;
		pNode = root->left;
	}
	else if(root->right->value < min) {
		min = root->right->value;
		pNode = root->right;
	}
	FindMin(root->left);
	FindMin(root->right);
	return pNode;
}
BNode* FindMax(BNode* root) {
	int max = root->value;
	BNode* pNode = root;

	return pNode;
}




int main2() {
	/*auto b = make_shared<B<string>>();
	shared_ptr<A<string>> a = b;
	proc<string>(a);
	proc<string>(b);*/

	//F();
/*
	vector<Rect> rec = { {2,1,3},{3,2,1},{1,4,2},{3,2,2},{1,4,1} };
	vector<RectExt> rec_ext = { {2,1,3},{3,2,1},{1,4,2} };
	sort(rec_ext.begin(),rec_ext.end(),cmp);
	sort(rec.begin(), rec.end());
	for_each(rec.begin(), rec.end(), [](Rect & a) {cout << a.id << "," << a.w << "," << a.h << endl; });
	cout << endl << endl;
	for_each(rec_ext.begin(), rec_ext.end(), [](RectExt & a) {cout << a.id << "," << a.w << "," << a.h << endl; });
	cout << endl << endl;*/

	cout << F() << endl;
	
	return 0;
}