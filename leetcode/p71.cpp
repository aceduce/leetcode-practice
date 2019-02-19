#include"Solutions.h"
// understand the stack structure!!
// need to be able to use getline functions!
string p71::simplifyPath(string path) {
	if (path.size() <= 1) return path;
	stack<string> stack;
	// partition the string path and push it into stack:
	string res, s;
	stringstream ss(path);
	while (getline(ss, s, '/')) {
		if (s == "..") {
			if (!stack.empty()) stack.pop();
		}
		else if (s != "." && !s.empty()) {
			stack.push(s);
		}
	}
	string result = "";
	if (stack.empty()) return "/";
	while (!stack.empty()) {
		result = "/" +stack.top() + result; // left side store popped element
		stack.pop();
	}
	return result;
}

void p71::test() {
	cout<<simplifyPath("/a/./b/../../c/");
}
