#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	if (pushV.size() != popV.size()) {
		return false;
	}

	int OutIdx = 0;
	int InIdx = 0;
	stack<int> s;

	while (OutIdx < popV.size()) {
		while (s.empty() || s.top() != popV[OutIdx]) {
			if (InIdx < pushV.size())
				s.push(pushV[InIdx++]);
			else
				return false;
		}
		s.pop();
		OutIdx++;
	}
	return true;
}

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int num = s1.top();
		s1.pop();
		return num;
	}

	/** Get the front element. */
	int peek() {
		return s1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (s1.empty())
			return true;
		return false;
	}
private:
	stack<int> s1;
	stack<int> s2;
};

int main() {
	/*vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,3,2,1 };

	IsPopOrder(v1, v2);*/

	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);

	q.pop();
	q.pop();

	return 0;
}