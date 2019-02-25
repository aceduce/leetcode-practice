#pragma once
//# include "Solutions.h"
# include<vector>
# include<cstdlib> // for null
# include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct LinkedNodes {
public:
	vector<int> vec;
	LinkedNodes(vector<int> input);
	LinkedNodes(ListNode * h);
	void SetHead(ListNode * h);
	ListNode * const GetHead();
	void PrintListNode();

private:
	ListNode * head;
	ListNode * InsertNodes();
};


struct Interval { // used for p56
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class NodeP133 {
public:
	int val;
	vector<NodeP133*> neighbors;

	NodeP133() {}

	NodeP133(int _val, vector<NodeP133*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};