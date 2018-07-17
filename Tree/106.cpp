#include <algorithm>
#include <iostream>
#include <unordered_map>
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        unordered_map<int, int> iMap;
        for (int i = 0; i < inorder.size(); ++i) {
            iMap[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, iMap);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd, const unordered_map<int, int> iMap)
    {
        if (posStart > posEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[posEnd]);
        // int index = inStart;
        // for (; index < inEnd; ++index) {
        //     if (inorder[index] == node->val) {
        //         break;
        //     }
        // }
        int index = iMap.at(node->val);
        node->left = build(inorder, postorder, inStart, index - 1, posStart, posStart + (index - inStart) - 1, iMap);
        node->right = build(inorder, postorder, index + 1, inEnd, posEnd - (inEnd - index), posEnd - 1, iMap);
        return node;
    }
};
int main()
{
    vector<int> ino{ 9, 3, 15, 20, 7 };
    vector<int> post{ 9, 15, 7, 20, 3 };
    Solution s;
    auto tree = s.buildTree(ino, post);

    LMR(tree);
    cout << endl;

    LRM(tree);
    cout << endl;
    return 0;
}