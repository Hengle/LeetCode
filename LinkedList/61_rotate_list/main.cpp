#include <iostream>

using namespace std;

struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k <=0)
            return head;
        int len = 1;
        ListNode *newH, *tail;
        newH = tail = head;
        while(tail->next) {
            tail=tail->next;
            len++;
        }
        tail->next = head;
        if (k %= len) {
            for (auto i = 0; i < len - k; i++)
                tail = tail->next;
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;

    }
};
int main(int argc, char *argv[])
{
    Solution slo;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    //    root->next->next = new ListNode(3);
    //    root->next->next->next = new ListNode(4);
    //    root->next->next->next->next = new ListNode(5);

    root = slo.rotateRight(root, 1);
    do {
        cout << root->val<<endl;
        root = root->next;
    } while(root);

    return 0;
}
