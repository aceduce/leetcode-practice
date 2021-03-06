#include"Solutions.h"
//#include"Helper.h"
void p73::setZeroes(vector<vector<int>>& matrix) {
	if (matrix.size() == 0) return;
	int row = matrix.size();
	int col = matrix[0].size();
	// first row and column marker
	bool firstRow = false;
	bool firstCol = false;
	// first col:
	for (int i = 0; i < row; i++) {
		if (matrix[i][0] == 0)
			firstCol = true;
	}
	for (int i = 0; i < col; i++) {
		if (matrix[0][i] == 0)
			firstRow = true;
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (matrix[i][j] == 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}
	for (int i = 1; i < row; i++) {
		if (matrix[i][0] == 0) {
			for (int j = 1; j < col; j++)
				matrix[i][j] = 0;
		}
	}
	for (int i = 1; i < col; i++) {
		if (matrix[0][i] == 0) {
			for (int j = 1; j < row; j++)
				matrix[j][i] = 0;
		}
	}
	if (firstRow) for (int i = 0; i < col; i++) matrix[0][i] = 0;
	if (firstCol) for (int i = 0; i < row; i++) matrix[i][0] = 0;
}

void p73::test() {
	vector<vector<int>> input = {
								{ 1,1,1 },
								{ 1,0,1 },
								{ 1,1,1 }
	};
	setZeroes(input);
	//Print2D(input);

}