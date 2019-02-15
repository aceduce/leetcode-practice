#include "Solutions.h"
// complication to move the first poiner (header)
ListNode* p82::deleteDuplicates(ListNode* head) {
	// totally delete all the duplicates (not leaving any)
	ListNode * pre = new ListNode{ 0 };
	// need to make sure first time move, ans keep
	ListNode * ans = pre;
	pre->next = head;
	ListNode * cur = pre->next;
	bool flag = false;
	while (cur != NULL) {
		flag = false;
		ListNode * tmp = cur->next;
		while ((tmp!= NULL && cur->val == tmp->val)) { //ending handling: when ending with duplicates
			tmp = tmp->next;
			flag = true;
		}
		// tmp now is the one to insert:
		if (tmp == NULL) // no more node to add
		{
			if (pre->next == head && flag == true) 
				return NULL; // if no different values available
			else if(flag == true){ // with duplicates
				pre->next = tmp;
				cur = tmp; // pre not moving
			}
			return ans->next;
		}

		if (!flag) { // no duplicates
			tmp = tmp->next;
			cur = cur->next;
			pre = pre->next;
		}
		else { // with duplicates
			pre->next = tmp;
			cur = tmp; // pre not moving
			tmp = tmp->next; //forgot...
		}
	}
	return ans->next; // cannot return head if the head node is not kept (duplicates)
}

void p82::test() {
	vector<int> input{0,  1, 1, 1, 2};
	LinkedNodes * LN = new LinkedNodes(input);
	LN->SetHead(deleteDuplicates(LN->GetHead()));
	LN->PrintListNode();
	delete LN;

}
