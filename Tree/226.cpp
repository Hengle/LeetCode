#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

TreeNode* invertTree(TreeNode* root)
{
    if (!root)
        return NULL;
    if (root->left && root->right) {
        TreeNode* t = root->right;
        root->right = root->left;
        root->left = t;
    }
    if (root->left)
        invertTree(root->left);
    if (root->right)
        invertTree(root->right);
    return root;
}
void LMR(TreeNode* root)
{
    if (!root)
        return;
    LMR(root->left);
    cout << root->val << endl;
    LMR(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    LMR(root);

    invertTree(root);
    cout << "invert" << endl;
    LMR(root);

    return 0;
}
