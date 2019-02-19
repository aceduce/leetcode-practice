#include"Solutions.h"

// use 2-D binary search:

bool p74::searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return false;
	int Rstart = 0;
	int Rend = matrix.size() - 1;
	int n = matrix[0].size();
	int row = 0;
	while (Rstart + 1 < Rend) {
		int mid = Rstart + (Rend - Rstart) / 2; // avoid overflow
		if (matrix[mid][n - 1] == target) return true;
		else if (matrix[mid][n - 1] < target) {
			Rstart = mid;
		}
		else {
			Rend = mid;
		}
	}
	// the change happens here
	if (matrix[Rstart][n - 1] >= target) row = Rstart;
	else if (matrix[Rend][n - 1] >= target) row = Rend;
	else return false;
	// find out the corresponding row
	int col = 0;
	int Cstart = 0, Cend = n - 1;
	while (Cstart < Cend - 1) {
		int mid = Cstart + (Cend - Cstart) / 2;
		if (matrix[row][mid] < target) Cstart = mid;
		else if (matrix[row][mid] == target) return true;
		else Cend = mid;
	}
	if (matrix[row][Cstart] == target || matrix[row][Cend] == target) return true;
	else return false;
}

void p74::test() {
	vector<vector<int>> input = { {} }; // { {1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
	cout << searchMatrix(input, 1) << endl;
	
}