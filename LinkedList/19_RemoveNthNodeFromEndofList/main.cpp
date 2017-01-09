#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *t, *p, *q;
		t = p = q = head;
		while (n-- != 1) {
			q = q->next;
		}
		while (q->next != NULL) {
			t = p;
			p = p->next;
			q = q->next;
		}
		if (t == p)
			return head->next;

		t->next = p->next;
		return head;
	}
};
using namespace std;

int main()
{
	Solution slo;
	ListNode *root = new ListNode(1);
		root->next = new ListNode(2);
	//	root->next->next = new ListNode(3);
	//	root->next->next->next = new ListNode(4);
	//	root->next->next->next->next = new ListNode(5);
	root = slo.removeNthFromEnd(root, 2);
	do {
		cout << root->val<<endl;
		root = root->next;
	} while(root);
	return 0;
}

