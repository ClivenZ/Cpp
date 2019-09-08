#if 0

#include<iostream>

using namespace std;
//RBTree
enum Color{RED, BLACK};

template<class V>
struct RBTreeNode {
	typedef V ValueType;
	RBTreeNode(const ValueType& value = ValueType(),Color color = RED)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_value(value)
		,_color(color)
	{}
	RBTreeNode<ValueType>* _left;
	RBTreeNode<ValueType>* _right;
	RBTreeNode<ValueType>* _parent;
	ValueType _value;
	Color _color;
};
template<class K,class ValueType,class V>
class RBTree {
	typedef RBTreeNode<ValueType> Node;
	typedef Node* pNode;

private:

};

template<class K,class V>
class MyMap {
	typedef pair<K, V> ValueType;

};

#endif

//AABB
#if 0

#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	int limit = 0;
	getline(cin, s);
	cin >> limit;
	if (limit == 0)
		return -1;
	int len = s.size();
	int first = 0;
	int second = 0;
	int count = 0;
	while (!s.empty()) {
		for (int i = 0; i < len; ++i) {
			first = i;
			second = i + 1;
			if (s[first] == s[second]) {
				cout << s[first] << first << endl;
				s.erase(first,1);
				s.erase(first, 1);
				break;
			}
		}
	}
	return 0;
}

#endif


#include<iostream>

using namespace std;


int main() {
	int k, line;
	cin >> k >> line;
	if (k == 0 || line == 0)
		return -1;
	for (int i = 0; i < line; ++i) {

	}


	return 0;
}




