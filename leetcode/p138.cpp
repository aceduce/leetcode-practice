#include"Solutions.h"
/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/

// Use Hashmap: (like the previous graph deep copy example
NodeP138* p138::copyRandomList_my(NodeP138* head) {
	if (head == NULL) return NULL;
	//list<Node*> l;
	//NodeP138 * dummy = new NodeP138;
	unordered_map<NodeP138 *, NodeP138*> map;
	//dummy->next = head;
	queue<NodeP138 *> q;
	map[head] = new NodeP138{ head->val, NULL, NULL };
	q.push(head);
	//map[tmp]->val = tmp->val;
	while (!q.empty()) {
		NodeP138 * tmp = q.front();
		q.pop();
		// could not use the graph approach as left and right could not point to the same 
		if (tmp->next != NULL && map.count(tmp->next) == 0) { // add new node
			map[tmp->next] = new NodeP138{ tmp->next->val, NULL, NULL};
			q.push(tmp->next);
		}
		
		if (tmp->random != NULL && map.count(tmp->random) == 0) {	// add new node
			map[tmp->random] = new NodeP138{ tmp->random->val , NULL, NULL};
			q.push(tmp->random);
		}
		else if(tmp->random != NULL && tmp->random == tmp) { // random would lead to the node itself
			map[tmp->random] = map[tmp];
		}
			
		// connections
		map[tmp]->next = map[tmp->next];
		map[tmp]->random = map[tmp->random];
	}
	return map[head];
}

// solution from Lai offer, didn't really used a queue (a list rather)
// use HashMap to reduce duplicates!
// O(n)
NodeP138* p138::copyRandomList_Hashmap(NodeP138* head) {
	if (!head) return NULL;
	NodeP138 * dummy = new NodeP138{ 0, NULL, NULL };
	NodeP138 * curr = dummy;
	unordered_map<NodeP138*, NodeP138*> map;
	while (head != NULL) { // just go along the list 
		if (map.count(head) == 0) {
			map[head] = new NodeP138{ head->val, NULL, NULL };
		}
		
		curr->next = map[head]; // this is doing next copy
		if (head->random != NULL) { 
			if (map.count(head->random) == 0) { // if random node exist we don't need to do anything
				map[head->random] = new NodeP138{ head->random->val, NULL, NULL };
			}
			curr->next->random = map[head->random];
		} 
		head = head->next;
		curr = curr->next;
	}
	return dummy->next;
}

NodeP138* p138::copyRandomList(NodeP138* head) {
	// an implmentation for this solution without a hashtable
	return NULL;
}
void p138::test() {
	NodeP138 * t = new NodeP138{ 2, NULL, NULL};
	t->random = t;
	NodeP138 * h = new NodeP138{ 1, t, t };
	NodeP138 * ans = copyRandomList(h);
}