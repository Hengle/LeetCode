#include <QCoreApplication>
#include <vector>
#include <QDebug>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructSubTree(nums, 0, nums.size() - 1);
    }
    TreeNode * constructSubTree(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int maxPos = left;
        for (auto i = maxPos + 1; i <= right; ++i) {
            if (nums[i] > nums[maxPos]) {
                maxPos = i;
            }
        }
        TreeNode *node = new TreeNode(nums[maxPos]);
        node->left = constructSubTree(nums, left, maxPos - 1);
        node->right = constructSubTree(nums, maxPos + 1, right);
        return node;
    }
};
void printTree(TreeNode *root) {
    if (!root) {
        qWarning() << "NULL";
        return;
    }
    qWarning() <<  root->val;
    printTree(root->left);
    printTree(root->right);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(5);

    Solution s;
    auto root = s.constructMaximumBinaryTree(nums);
    printTree(root);
    return a.exec();
}
