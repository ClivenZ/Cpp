#include<iostream>
#include<cstdio>
#include<string>
#include<vector>


using namespace std;

struct TreeNode{
	char value;
	struct TreeNode* left;
	struct TreeNode* right;
};


TreeNode* CreatTree(TreeNode* root, string& str, int num) {
	TreeNode* ret = nullptr;
	TreeNode* ptr = nullptr;
	


}

//Ç°Ðò±éÀú
void perorder(TreeNode* root) {
	if (root == nullptr)
		return;
	perorder(root->left);
	cout << root->value << endl;
	perorder(root->right);
}
int main() {
	int num = 0;
	cin >> num;
	string str;
	for (int i = 0; i < num; ++i) {
		char n;
		cin >> n;
		str.push_back(n);
	}
	TreeNode* root = new TreeNode;
	root->value = str[0];
	root = CreatTree(root, str, num);
	perorder(root);

	return 0;
}