#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> v1, v2;

void MLR(TreeNode *node, vector<int> &v)
{
	if (node) {
		v.push_back(node->val);
	}
	if (node->left)
		MLR(node->left, v);
	if (node->right)
		MLR(node->right, v);
}
bool isSameTree(TreeNode* p, TreeNode* q) {
	MLR(p, v1);
	MLR(q, v2);
	return v1 == v2 ;
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(3);
	root2->right = new TreeNode(3);

	if (isSameTree(root, root2)==true)
		cout<<true;
	else
		cout<<false;
	return 0;
}

