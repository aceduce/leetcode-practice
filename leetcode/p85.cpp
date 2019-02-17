#include"Solutions.h"

// a re-write of the code from preivous questions:
int submax(vector<int> heights) {
	int size = heights.size();
	int ret = 0;
	stack<int> stack;
	for (int i = 0; i < size; i++) {
		if (stack.empty() || heights[i] >= heights[stack.top()]) {
			stack.push(i);
		}
		else {
			int right = i;
			int ind = stack.top();
			stack.pop();
			while (!stack.empty() && heights[stack.top()] == heights[ind]) {
				ind = stack.top();
				stack.pop();
			}
			int left = stack.empty() ? -1 : stack.top();
			ret = max(ret, (right - left - 1) * heights[ind]);
			i--;
		}
	}
	int right = stack.top() + 1;
	while (!stack.empty()) {
		int ind = stack.top();
		stack.pop();
		int left = (stack.empty()) ? -1 : stack.top();
		ret = max(ret, (right - left - 1) * heights[ind]);
	}
	return ret;
}

int p85::maximalRectangle(vector<vector<char>>& matrix) {
	// conversion matrix
	int row = matrix.size();
	if (row == 0) return 0;
	int col = matrix[0].size();
	int ans = 0;
	vector<int> heights(col, 0);
	for (int i = 0; i < row; i++) { // O(mn)
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == '0') heights[j] = 0;
			else {
				heights[j]++;
			}
		}
	 // the height matrix is prepared for p84
		ans = max(ans, submax(heights));
	}
	return ans;
}

void p85::test() {
	vector<vector<char>> matrix{
								{ '1','0','1','0','0' },
								{ '1','0','1','1','1' },
								{ '1','1','1','1','1' },
								{ '1','0','0','1','0' }
	};
	vector<vector<char>> m;
	cout << maximalRectangle(m) << endl;
}