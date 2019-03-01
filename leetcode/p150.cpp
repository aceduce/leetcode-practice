#include"Solutions.h"

// use stack method
int p150::evalRPN(vector<string>& tokens) {
	stack<int> stack; // use int it's all done
	for (auto const & s : tokens) {
		if (s.size() == 1 && !isdigit(s[0])) { // handle the operators
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			if (s == "+") stack.push(a + b);
			else if (s == "*") stack.push(a * b);
			else if (s == "/") stack.push(a / b);
			else if (s == "-") stack.push(a - b);
		}
		else { // push in regular numbers
			stack.push(stoi(s));
		}
	}
	return stack.top();
}

void p150::test() {

}