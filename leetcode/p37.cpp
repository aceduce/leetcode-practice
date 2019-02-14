# include"Solutions.h"
// depth first visit algorithm (recursive)

bool isValid(int row, int col, vector<vector<char>>& board, int num) { // much more simplifed as just need to check THAT VALUE!
	// check row and column valid
	// just the corresponding row and column, no need to check all the column and rows
	//vector<int> taken(9, false);
	for (int i = 0; i < 9; i++) { // this is assume not filled already
		if (board[row][i] == num + '1' || board[i][col] == num + '1') return false;
	}
		// the trickest case, just check the box where this positon sit
	int r = 3 * (row / 3);
	int c = 3 * (col / 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i + r][j + c] == num + '1')
				return false;
		}
	}
	return true;
}

// no need to loop over all the matrix: just need to focus on the first unfilled '.'
bool subsolveSudoku(int r, int c, vector<vector<char>> & board) {
	while (r < 9 && c < 9) {
		if (board[r][c] == '.') {
			break;
		} 
		r = (c + 1) / 9 + r;
		c = (c + 1) % 9; // sequence is very important!!
		
	}
	if (r >= 9) return true; // successfully finished
	// obtain the position to change
	int row = r, col = c;
	for (int i = 0; i < 9; i++) { // try all the numbers
		if (isValid(row, col, board, i)) {
			board[row][col] = i + '1'; // try i element 
			int newRow = (col + 1) / 9 + row;  // fill horizontally
			int newCol = (col + 1) % 9; // seuqence is very imporant!
			if (subsolveSudoku(newRow, newCol, board) == true) return true; // solve the problem
			board[row][col] = '.'; // get back and try another value
		}
		// no need : board[row][col] = '.'; // need to make sure the last 9 doesn't stay here!
	}
	return false; // none of the 9 number works! earlier end!

}

void p37::solveSudoku(vector<vector<char>>& board) {
	subsolveSudoku(0, 0, board);
}