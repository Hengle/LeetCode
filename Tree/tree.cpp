#include <iostream>
#include <vector>
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

void MLR(TreeNode* node)
{
    if (node) {
        cout << node->val << " ";
        MLR(node->left);
        MLR(node->right);
    }
}
void LMR(TreeNode* node)
{
    if (node) {
        LMR(node->left);
        cout << node->val << " ";
        LMR(node->right);
    }
}
void LRM(TreeNode* node)
{
    if (node) {
        LRM(node->left);
        LRM(node->right);
        cout << node->val << " ";
    }
}
int main()
{
    TreeNode root(3), l1(9), r1(20), rl1(15), rr1(7);
    root.left = &l1;
    root.right = &r1;
    r1.left = &rl1;
    r1.right = &rr1;

    MLR(&root);
    cout << endl;
    LMR(&root);
    cout << endl;
    LRM(&root);
    cout << endl;

    return 0;
}