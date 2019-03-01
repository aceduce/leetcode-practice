#include"Solutions.h"

// use Merge sort method (bottom up simulations)

// method 1: top-down merge sort
// T: O(nlogn); space: O(N)
// merge functoins
ListNode * p148::merge(ListNode * h1, ListNode * h2) {
	// a smart way of writing the merge function:
	ListNode dummy(0);
	ListNode * tail = &dummy; // tail to attach next node
	while (h1 && h2) {
		if (h1->val > h2->val) {
			swap(h1, h2); // swap pointer
		}
		tail->next = h1;
		h1 = h1->next;
		tail = tail->next;
	}
	if (h1) tail->next = h1;
	if (h2) tail->next = h2;
	return dummy.next;
}

ListNode* p148::sortList_merge(ListNode* head) {
	// is pretty intuitive
	if (!head || !head->next) return head;
	ListNode * fast = head, *slow = head;
	while (!fast && !fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// mid node should be one after slow
	ListNode * mid = slow->next;
	slow->next = NULL;
	return merge(sortList(head), sortList(mid));
}

// Method 2: bottom up simulations:
ListNode * p148::split(ListNode * head, int n) {
	while (--n && head) 
		head = head->next;
	ListNode * rest = head ? head->next : NULL;
	if (head) head->next = NULL;
	return rest;
}

pair<ListNode *, ListNode *> p148::merge_2(ListNode * l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode * tail = &dummy;
	while (l1 && l2) {
		if (l1->val > l2->val) swap(l1, l2);
		tail->next = l1;
		l1 = l1->next;
		tail = tail->next;
	}
	tail->next = l1 ? l1 : l2;
	while (tail->next) tail = tail->next;
	return { dummy.next, tail }; // pair
}
ListNode * p148::sortList(ListNode* head) {
	if (!head || !head->next) return head;
	int len = 1;
	ListNode * cur = head;
	while (cur = cur->next) ++len;
	ListNode dummy(0); // put it on the stack
	dummy.next = head;
	ListNode *left, *right, *tail;
	// n-logn approach
	// logn loop, each loop n operations
	for (int n = 1; n < len; n <<= 1) { // x2 --> logN loop
		cur = dummy.next; 
		tail = &dummy;
		while (cur) {
			left = cur;
			right = split(left, n);
			cur = split(right, n);
			auto merged = merge_2(left, right);
			tail->next = merged.first; // connection point
			tail = merged.second; // real tail
		}
	}
	return dummy.next;
}



void p148::test() {

}