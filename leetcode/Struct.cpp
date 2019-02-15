# include "Struct.h"

LinkedNodes::LinkedNodes(vector<int> input) {
	vec = input;
	head = InsertNodes();
}
LinkedNodes::LinkedNodes(ListNode * h) {
	head = h;
	vec.push_back(INT_MAX);
}

ListNode * LinkedNodes::InsertNodes() {
	head = new ListNode(vec[0]);
	ListNode * t = head;
	for (int i = 1; i < vec.size(); i++) {
		ListNode * tmp = new ListNode(vec[i]);
		t->next = tmp;
		t = t->next;
	}
	return head;
}


void LinkedNodes::PrintListNode() {
	ListNode * tmp = head;
	std::cout << " [ ";
	while (tmp != NULL) {
		cout << tmp->val;
		if (tmp->next != NULL) cout << "->";
		tmp = tmp->next;
	}
	cout << " ] ";
}

ListNode * const LinkedNodes::GetHead() {
	return head;
}
void LinkedNodes::SetHead(ListNode * h) {
	head = h;
}