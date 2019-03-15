#include"Solutions.h"
/** Initialize your data structure here. */
// other methods using two queues:
// https://leetcode.com/problems/implement-stack-using-queues/solution/
class p225::MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		int size = q.size();
		q.push(x);
		for (int i = 0; i < size; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = q.size();
		if (size > 0) {
			int tmp = q.front();
			q.pop();
			return tmp;
		}
		return -1;
	}

	/** Get the top element. */
	int top() {
		return q.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
private:
	queue<int> q;
};