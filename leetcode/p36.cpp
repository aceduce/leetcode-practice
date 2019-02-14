# include "Solutions.h"

bool p36::isValidSudoku(vector<vector<char>>& board) {
	// check the row and columns for unique 1-9
	// the answer use a taken table to make sure the unique values are picked up 
	// each just move by 3 x 3, write a function to check within 3x3
	// deep copy or shallow copy if declare a new vector and assign
	vector<bool> values(9, false);
	// check each row 
	for (int row = 0; row < 9; row++) {
		fill(values.begin(), values.end(), false);
		for (int i = 0; i < 9; i++) {
			if (board[row][i] != '.') {
				if (values[board[row][i] - '1']) return false; // double counting
				values[board[row][i] - '1'] = true;
			}
		}
	}
	// check each column
	for (int col = 0; col < 9; col++) {
		fill(values.begin(), values.end(), false);
		for (int i = 0; i < 9; i++) {
			if (board[i][col] != '.') {
				if (values[board[i][col] - '1']) return false;
				values[board[i][col] - '1'] = true;
			}
		}
	}
	// check each sub-box 3x3 --> 9 x9 / (3 x 3) = 9 boxes
		for (int box = 0; box < 9; box++) {
			fill(values.begin(), values.end(), false);
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					int row = (box / 3) * 3 + j;
					int col = (box % 3) * 3 + i;
					if (board[row][col] != '.') { // easily forget from - '1' to convert to index
						if (values[board[row][col] - '1']) return false;
						values[board[row][col] - '1'] = true; // easily forget from - '1' to convert to index
					}
				}
			}	
		}
		return true;
}