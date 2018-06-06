struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
    TreeNode* merge(TreeNode *t1, TreeNode *t2) {

    }
};
int main(int argc, char *argv[])
{
    return 0;
}
