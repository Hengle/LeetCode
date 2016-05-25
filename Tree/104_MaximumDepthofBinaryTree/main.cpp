#include <iostream>     // std::cout
#include <algorithm>    // std::max
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int depth (TreeNode *root) {
	if(root == NULL)
		return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}
int maxDepth(TreeNode* root) {
	return depth(root);
}


using namespace std;

int main()
{
	//	cout << "Hello World!" << endl;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(3);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);

	cout<<maxDepth(root);

	return 0;
}

