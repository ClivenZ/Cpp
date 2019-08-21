#pragma once
#include<iostream>
#include<deque>
using namespace std;

namespace My {
	template<class T,class Con = deque<T>>
	class Queue {
	public:
		Queue(){}
		bool Empty() const {
			return _c.empty();
		}
		size_t Size() const {
			return _c.size();
		}
		T& Front() {
			return _c.front();
		}
		const T& Front() cosnt {
			return _c.front();
		}
		T& back() {
			return _c.back();
		}
		const T& back() cosnt {
			return _c.back();
		}
		void Pop() {
			_c.pop_front();
		}
		void Push(const T& x) {
			_c.push_back(x);
		}
	private:
		Con _c;
	};
}