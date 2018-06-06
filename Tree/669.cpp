#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) return NULL;
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
void outTree(TreeNode *node) {
    if (node){
        if (node->left)
            outTree(node->left);

        cout << node->val << endl;

        if (node->right)
            outTree(node->right);
    }
}
int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    TreeNode node(1);
    TreeNode node2(2);
    TreeNode node0(0);
    node.left = &node0;
    node.right = &node2
            ;
    Solution s;
    auto ans = s.trimBST(&node, 1, 2);
    outTree(ans);
    return 0;
}
