#include <iostream>

using namespace std;
struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};
ListNode * reverse(ListNode * root)
{
	if (root == NULL || root->next == NULL) {
		return root;
	}
	ListNode *pre = NULL;
	ListNode *mid = root;
	ListNode *next = root->next;
	while(next){
		//下一个指针改成指向上一个
		mid->next = pre;
		//前一个 记录更新
		pre = mid;
		//当前节点 记录更新
		mid = next;
		//更新 下一个节点
		next = next->next;
	}
	mid->next = pre;
	return mid;
}

int main(int argc, char *argv[])
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    cout << "before:" << endl;
    ListNode *head = root;
    do {
        cout << head->val<<endl;
        head = head->next;
    } while(head);

    root = reverse(root);
    head = root;
    cout << "after:" << endl;
    do {
        cout << head->val<<endl;
        head = head->next;
    } while(head);


    return 0;
}
