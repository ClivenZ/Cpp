#pragma once
#include<iostream>
#include<deque>
using namespace std;

namespace My {
	template<class T,class Con = deque<T>>
	class Stack {
	public:
		Stack(){}
		void push(const T& x) {
			_c.push_back(x);
		}
		void pop() {
			_c.pop_back();
		}
		T& Top{
			return _c.back();
		}
		const T& Top() const {
			return _c.back();
		}
		size_t Size() const {
			return _c.size();
		}
		bool Empty() const {
			return _c.empty();
		}
	private:
		Con _c;
	};
}