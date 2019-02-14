# include"Solutions.h"

// looks like a recursive call that I can handle:

void subspiral(vector<vector<int>> & matrix, vector<int> & ans, int m) {
	// m stands for the layers into the matrix, starting point is 0
	int row_size = matrix.size();
	int col_size = matrix[0].size();
	
	int r = row_size - 2 * m;
	int c = col_size - 2 * m; // # of print elemnt
	if (r == 1) { // just one row element
		for (int i = m; i <= col_size - 1 - m; i++) {
			ans.push_back(matrix[m][i]);
		}
		return;
	}
	if (c == 1) {
		for (int i = m; i <= row_size - 1 - m; i++) {
			ans.push_back(matrix[i][m]);
		}
		return;
	}
	if (r == 0 || c == 0) { return; }

	// avoid last element duplicate
	for (int i = m; i < col_size -1 - m; i++) {
		ans.push_back(matrix[m][i]);
	}
	for (int i = m; i < row_size -1 -m ; i++) {
		ans.push_back(matrix[i][col_size - m - 1]);
	}
	for (int i = col_size - m - 1; i > m; i--) {
		ans.push_back(matrix[row_size - 1 - m][i]);
	}
	for (int i = row_size - 1- m; i > m; i--) {
		ans.push_back(matrix[i][m]);
	}
	subspiral(matrix, ans, m + 1);
	return;
}

vector<int> p54::spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	if (matrix.empty()) return ans;;
	subspiral(matrix, ans, 0);
	return ans;
}

void p54::test() {
	/*
	vector<vector<int>> matrix{ { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	vector<int> ans = spiralOrder(matrix);
	for (int i = 0; i < ans.size(); i++) {
	cout << ans[i] << " ";
	}
	*/

	cout << "-------------------------------" << endl;
	vector<vector<int>> matrix2{ { 1, 2, 3, 4 },{ 5, 6, 7, 8},{ 9, 10, 11, 12}, {13, 14, 15, 16} };
	//vector<vector<int>> matrix2;
	vector<int> ans = spiralOrder(matrix2);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}