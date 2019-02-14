#pragma once
# include "Solutions.h"
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct LinkedNodes {
	vector<int> vec;
private:
	ListNode * head;
public:
	LinkedNodes(vector<int> input) {
		vec = input;
		head = InsertNodes();
	}
	LinkedNodes(ListNode * h) {
		head = h;
		vec.push_back(INT_MAX);
	}

private:
	ListNode * InsertNodes() {
		head = new ListNode(vec[0]);
		ListNode * t = head;
		for (int i = 1; i < vec.size(); i++) {
		ListNode * tmp = new ListNode(vec[i]);
		t->next = tmp;
		t = t->next;
		}
		return head;
	}

public:
	// helper function to print out the ListNodes in the chain
	void PrintListNode() {
		ListNode * tmp = head;
		std::cout << " [ ";
		while (tmp != NULL) {
			cout << tmp->val;
			if(tmp->next != NULL) cout<< "->";
			tmp = tmp->next;
		}
		cout << " ] ";
	}

	ListNode * const GetHead() {
		return head;
	}
	void SetHead(ListNode * h) {
		if(h!= NULL) head = h;
	}
};


