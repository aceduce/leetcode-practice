# include "Solutions.h"
// difficult to observe the pattern!!
void p48::rotate(vector<vector<int>>& matrix) {
	// this is a n x n matrix (square)
	int top = 0, left = 0;
	int bottom = matrix.size() - 1, right = matrix[0].size() - 1;
	while (top < bottom && left < right) {
		int n = right - left;
		for (int i = 0; i < n; i++) {
			int tmp = matrix[top][left + i];
			matrix[top][left + i] = matrix[bottom - i][left];
			matrix[bottom - i][left] = matrix[bottom][right - i];
			matrix[bottom][right - i] = matrix[top + i][right];
			matrix[top + i][right] = tmp;
		}
		bottom--;
		right--;
		left++;
		top++;
	}
}

void p48::test() {
	vector < vector<int>> inp{ {1,2,3}, {4, 5, 6}, {7,8,9} };
	rotate(inp);
	for (int i = 0; i < inp.size(); i++) {
		cout << " [ ";
		for (int j = 0; j < inp.size(); j++)
			cout << inp[i][j] << " ";
		cout << " ] " << endl;
	}
}