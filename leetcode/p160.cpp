#include"Solutions.h"
// Second solution is much smarter!!
/*
Time complexity : O(m+n)O(m+n).

Space complexity : O(m)O(m) or O(n)O(n). 

*/

// using a hashtable
ListNode * p160::getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (!headA || !headB) return NULL;
	unordered_set<ListNode *> set;
	// traverse through one of the list
	while (headA) {
		set.insert(headA);
		headA = headA->next;
	}
	while (headB) {
		if (set.count(headB)!= 0) return headB;
		headB = headB->next;
	}
	return NULL;
}

void p160::test() {

}