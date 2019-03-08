#include"Solutions.h"
void p237::deleteNode(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}