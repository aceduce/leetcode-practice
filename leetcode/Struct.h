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

