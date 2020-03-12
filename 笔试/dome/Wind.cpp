#if 0
#include<iostream>
using namespace std;
struct ListNode {
	int value;
	ListNode* next;
};
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pNode = pHead;  
	ListNode* pPrev = nullptr;
	ListNode* pNext = nullptr;
	ListNode* pReverseHead = nullptr;
		while (pNode != nullptr)
		{
			pNext = pNode->next;
			if (pNext == NULL)
				pReverseHead = pNode;
		    pNode->next = pPrev; 
		    pPrev = pNode;
		    pNode = pNext;
		}
	return pReverseHead;
}

ListNode* MergeListNode(ListNode* pHead1,ListNode* pHead2) {
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	if (pHead1 == nullptr && pHead2 == nullptr)
		return nullptr;
	
	ListNode* Ret_pHead = nullptr;
	ListNode* Ret_Next = nullptr;
	ListNode* pList1 = nullptr;
	ListNode* pList2 = nullptr;
	if (pHead1->value < pHead2->value) {
		Ret_pHead = pHead1;
		pList1 = pHead1->next;
		pList2 = pHead2;
	}
	else {
		Ret_pHead = pHead2;
		pList2 = pHead2->next;
		pList1 = pHead1;
	}
	Ret_pHead->next = Ret_Next;
	while (pList1 != nullptr && pList2 != nullptr) {
		if (pList1->value < pList2->value) {
			Ret_Next = pList1;
			pList1 = pList1->next;
			Ret_Next = Ret_Next->next;
		}
		else{
			Ret_Next = pList2;
			pList2 = pList2->next;
			Ret_Next = Ret_Next->next;
		}
	}
	if (pList1 == nullptr && pList2 != nullptr) {
		while (pList2 != nullptr) {
			Ret_Next = pList2;
			pList2 = pList2->next;
			Ret_Next = Ret_Next->next;
		}
	}
	else if (pList1 != nullptr && pList2 == nullptr) {
		while (pList1 != nullptr) {
			pList1 = pList1->next;
			Ret_Next = Ret_Next->next;
		}
	}
	return Ret_pHead;
}
int main() {
	ListNode* pHead1 = nullptr;
	ListNode* pHead2 = nullptr;
	ListNode* Ret_pHead = nullptr;
	Ret_pHead = MergeListNode(pHead1, pHead2);
	Ret_pHead = ReverseList(Ret_pHead);
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;

int main() {
	int x = 2;
	int y = 3;
	int z = 4;
	int Cout = x < z ? y : z;
	cout << Cout << endl;
	return 0;
}
#endif


#if 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, x;
	int max = 1;
	int count = 1;
	int ret1 = 1;
	cin >> n >> x;
	if (n == 0) {
		cout << max << endl;
		return 0;
	}
	vector<int> v;
	vector<int> v1;
	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; ++i) {
		int count = 1;
		for (int j = (i + 1); j < n; ++j) {
			if ( v[i]== v[j]) {
				count++;
			}
		}
		if (count > ret1) {
			ret1 = count;
		}
		else {
			count = 1;
		}
		if ((n - i) < ret1) {
			i = n;
		}
	}
	for (int i = 0; i < n; ++i) {
		int num = 0;
		num = (v[i] | x);
		v1.push_back(num);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = (i + 1); j < n; ++j) {
			if (v1[i] == v1[j]) {
				count++;
				i = j;
			}
		}
		if (count > max) {
			max = count;
		}
		else {
			count = 1;
		}
		if ((n - i) < max) {
			i = n;
		}
	}
	if (ret1 < max) {
		cout << max << endl;
	}
	else {
		cout << ret1 << endl;
	}
	return 0;
}

#endif


#if 0

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, k, l, r;
	cin >> n >> k >> l >> r;
	int count = 0;
	vector<int> v;

	cout << count << endl;
	return 0;
}

#endif