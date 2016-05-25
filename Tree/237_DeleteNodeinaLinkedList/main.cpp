#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val)
{
	ListNode root(0);
	root.next = head;
	ListNode *p, *q;
	p = &root;
	q = head;
	while(q) {
		if (q->val == val) {
			p->next = q->next;
			q = q->next;
		} else {
			p = q;
			q = q->next;
		}
	}
	return root.next;
}

using namespace std;

int main()
{
	ListNode *head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);

	head = deleteNode(head, 1);
	while(head) {
		cout<<head->val<<endl;
		head = head->next;
	}
	return 0;
}

