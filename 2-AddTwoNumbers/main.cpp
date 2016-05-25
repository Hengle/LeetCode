#include <iostream>

using namespace std;
//不用+ 运算符，用位运算实现加法
int add(int a, int b)
{
	int low = a^b;
	int high = a&b;
	while(high) {

		int t1 = low;
		int t2 = high<<1;
		low = t1 ^ t2;
		high = t1&t2;
	}
	return low;
}
//链表逆序
//ListNode * reverse(ListNode *head)
//{
//	ListNode *p = NULL;
//	ListNode *q = NULL;
//	while(head) {
//		q = head->next;
//		head->next= p;
//		p = head;
//		head = q;
//	}
//	return p;
//}
//ListNode *head = new ListNode(1);
//head->next = new ListNode(2);
//head->next->next = new ListNode(3);
//head = reverse(head);
//while(head){
//	cout <<head->val<<endl;
//	head = head->next;
//}
//
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *head = NULL;
	ListNode *p = NULL;
	int low = 0, high = 0;

	low = l1->val + l2->val;
	high = low / 10;
	low = low % 10;

	head = new ListNode(low);
	p = head;

	while(l1->next || l2->next) {
		int v1, v2;
		if (l1->next) {
			l1 = l1->next;
			v1 = l1->val;
		} else v1 = 0;
		if (l2->next) {
			l2 = l2->next;
			v2 = l2->val;
		} else v2 = 0;

		low = v1 + v2 + high ;
		high = low / 10;
		low = low % 10;

		ListNode *node = new ListNode(low);
		p->next = node;
		p = p->next;
	}
	if (high > 0) {
		p->next = new ListNode(high);
	}
	return head;
}

int main()
{
	ListNode *p = new ListNode(9);
	p->next = new ListNode(8);

	ListNode *q = new ListNode(1);

	ListNode *ret = addTwoNumbers(p, q);
	ListNode *iter = ret;

	while (iter) {
		cout<<iter->val;
		iter= iter->next;
	}
	return 0;
}

