#include"Solutions.h"
// use the depth search
// time complexity : O(4^l) l: len of words
// total (m*n*4^l)

// space: O(m*n + l) --> depth is l

bool subexit(vector<vector<char>>& board, string &word, int x, int y, int d) { // d means the length of the words
	if (d == word.length()) return true;
	// put out of bound hear is easier:
	if (x >= board.size() || y >= board[0].size()|| x <0 || y < 0) return false;
	// search for four directions
	if (board[x][y] == word[d]) {
		// little trick to avoid repeat 
		char cur = board[x][y];
		board[x][y]= 0;
		bool found = (subexit(board, word, x + 1, y, d + 1) ||
			subexit(board, word, x - 1, y, d + 1) ||
			subexit(board, word, x, y + 1, d + 1) ||
			subexit(board, word, x, y - 1, d + 1));
		board[x][y] = cur;
		return found;
	}
	else {
		return false;
	}
}

bool p79::exist(vector<vector<char>>& board, string word) {
	if (board.size() == 0 || word.size() == 0) return false;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (subexit(board, word, i, j, 0)) return true;
		}
	}
	return false;
}

void p79::test() {
	vector<vector<char>> board = {
		{ 'A','B','C','E' },
		{ 'S','F','C','S' },
		{ 'A','D','E','E' }};
	cout << exist(board, "SEE") << endl;
	cout << char(0) << endl;

}