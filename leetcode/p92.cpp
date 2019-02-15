#include"Solutions.h"

//looks like a similar question from before... [pre, tail, cur, tmp] pointers
// need to use tmp to keep track of cur->next rather than current
ListNode* p92::reverseBetween(ListNode* head, int m, int n) {

	if (head == NULL) return NULL;
	if (m == n) return head;
	ListNode * pre = new ListNode{ 0 };
	ListNode * ans = pre;
	pre->next = head;
	for (int i = 0; i < m - 1; i++) { // find the pre, tail and cur nodes
		pre = pre->next;
	}
	ListNode * tail{ pre->next};
	ListNode * cur{ pre->next->next };
	for (int i = 0; i < n - m; i++) { // actually rotating
		//ListNode * tmp{ cur };
		ListNode * tmp = new ListNode{ 0 }; // need to use this? 
		tmp = cur->next;
		cur->next = pre->next; // this can be eaisly confused with tail
		pre->next = cur;
		tail->next = tmp;
		cur = tmp;
	}
	return ans->next;
}

void p92::test() {
	vector<int> input{ 1,2,3,4,5 };
	LinkedNodes * ln = new LinkedNodes(input);
	ln->PrintListNode();
	cout << "After Rotating" << endl;
	ListNode * p = ln->GetHead();
	ln->SetHead(reverseBetween(p, 2, 5));
	ln->PrintListNode();
	delete ln;

}