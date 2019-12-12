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
	while (pList1 != nullptr && pList1 != nullptr) {
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