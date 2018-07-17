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
private:
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int, int> iMap;
        for (int i = 0; i < inorder.size(); ++i) {
            iMap[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, iMap);
    }
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, const unordered_map<int, int>& iMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[preStart]);
        // int index = inStart;
        // for (; index <= inEnd; ++index) {
        //     if (inorder[index] == node->val) {
        //         break;
        //     }
        // }
        int index = iMap.at(node->val);
        node->left = build(preorder, inorder, preStart + 1, preStart + (index - inStart), inStart, index - 1, iMap);
        node->right = build(preorder, inorder, preStart + (index - inStart) + 1, preEnd, index + 1, inEnd, iMap);
        return node;
    }
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    // {
    //     return build(preorder, inorder, 0, 0, inorder.size() - 1);
    // }
    // TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int preLeft, int left, int right)
    // {
    //     if (preLeft >= preorder.size() || left > right) {
    //         return nullptr;
    //     }
    //     int v = preorder[preLeft];
    //     TreeNode* node = new TreeNode(v);

    //     int index = 0;
    //     for (index = left; index <= right; ++index) {
    //         if (inorder[index] == v) {
    //             break;
    //         }
    //     }

    //     node->left = build(preorder, inorder, preLeft + 1, left, index - 1);

    //     node->right = build(preorder, inorder, preLeft + 1 + index - left, index + 1, right);
    //     return node;
    // }
};
int main()
{
    vector<int> pre{ 3, 9, 20, 15, 7 };
    vector<int> ino{ 9, 3, 15, 20, 7 };
    Solution s;
    auto tree = s.buildTree(pre, ino);

    LMR(tree);
    cout << endl;

    MLR(tree);
    cout << endl;
    return 0;
}