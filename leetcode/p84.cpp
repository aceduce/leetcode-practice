#include"Solutions.h"
// O(n^2)
/*
int p84::largestRectangleArea(vector<int>& heights) {

}
*/

// O(n) stack  method
// notations: left, indx, right ==> left is the left boundary for indx, right is the right boundary
// these are all from the indices, not from the heights matrix
int p84::largestRectangleArea(vector<int>& heights) {
	if (heights.size() == 0) return 0;
	int size = heights.size();
	stack<int> stack;
	int ans = 0;
	// 1. push to stack ; 2. calculations; 3. deal with the rest of the stack
	for (int cur = 0; cur < size; cur++) { // each node has to be push into stack at some point!
		if (stack.empty() || heights[cur] >= heights[stack.top()]) {
			stack.push(cur);
			//cur++;
		}
		else {
			int right = cur;
			int indx = stack.top(); // center point decided
			stack.pop();
			// pop the indx not popping the left to find!!
			while (!stack.empty() && heights[indx] == heights[stack.top()]) {
				indx = stack.top();
				stack.pop();
			} // indx is changing , but the the left, right doesn't change
			int left = stack.empty() ? -1 : stack.top();
			ans = max(ans, heights[indx] * (right - left - 1));
			cur--;
		}

	}// deal with the rest of the stack
	int right = stack.top()+ 1;  // should be able to use cur+1
	while (!stack.empty()) {
		int indx = stack.top();
		stack.pop();
		int left = stack.empty() ? -1 : stack.top();
		ans = max(ans, heights[indx] * (right - left - 1));		
	}
	return ans;
}

void p84::test() {
	vector<int> heights{ 2,1,5,6,2,3 };
	cout << largestRectangleArea(heights) << endl;
}