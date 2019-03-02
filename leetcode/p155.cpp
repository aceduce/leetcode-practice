#include"Solutions.h"
class p155::MinStack {
	// maintain the stack1 and stack2 at the same level!
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		stack1.push(x);
		if (stack2.empty()) stack2.push(x);
		else stack2.push(min(x, stack2.top()));
	}

	void pop() {
		stack2.pop();
		stack1.pop();
	}

	int top() {
		return stack1.top();
	}

	int getMin() {
		return stack2.top();
	}
private:
	stack<int> stack1; // normal stack
	stack<int> stack2; // keeps the minim
};