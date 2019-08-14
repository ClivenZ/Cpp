#pragma once
#include<assert.h>
#include<string>
namespace My {  
	class String {
	public:
		//更夛
		String(const char* str = "") {
			if (str == nullptr) {
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str,str);
		}
		String(const String& s)
			: _str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{	
			strcpy(_str, s._str);
		}
		String& operator=(const String& s) {
			if (this != &s) {
				char* pStr = new char[s._capacity + 1];
				strcpy(pStr, s._str);

				delete[] _str;
				_str = pStr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~String() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
			}
		}
		//Iterators:begin、end
		typedef char* Interators;
		Interators Begin() {
			return _str;
		}
		Interators End() {
			return _str + _size;
		}
		//Capacity:size,length,
		void Reserve(size_t res_arg = 0) {
			if (_capacity >= res_arg)
				return;
			else
				_capacity = res_arg;
		}
		//Modify:operator+=、PushBack、Append、
		void PushBack(char c) {
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '/0';
		}
		void Append(size_t n,char c) {
			for (size_t i = 0; i < n; ++i) {
				PushBack(c);
			}
		}
		void Append(const char* str) {

		}
		String& operator+=(char c) {
			PushBack(c);
			return *this;
		}
		String& operator+=(const char* str) {

		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
