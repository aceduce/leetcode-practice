#include"Solutions.h"
class p488::Solution {
public:
	// update the board
	// YWWRRRWWYY ==> YWWWWYY ==> YYY --> 0
	string update(string board) {
		bool done = false;
		int i = 0;
		while (i < board.size()) {
			int j = i;
			while (j < board.size() && board[i] == board[j]) j++;
			if (j - i >= 3) { // remove
				board = board.substr(0, i) + board.substr(j);
				i = 0;
			}
			else {
				i++;
			}
		}
		return board;
	}
	// return the min #  of balls needed in hand to clear the board
	// return -1 if it's impossible
	int dfs(string & board, vector<int> & hand) {
		if (board.empty())
			return 0;
		int ans = INT_MAX;
		int i = 0;
		int j = 0;
		while (i < board.size()) {
			while (j < board.size() && board[i] == board[j]) ++j;
			// board[i] ~ board[j - 1] has same color
			const char color = board[i];
			// number of balls needed to clear
			const int b = 3 - (j - i);
			// sufficent balls at hand
			if (hand[color] >= b) {
				// remove board[i] ~ board[j - 1] 
				// and update the board 
				string nb = update(board.substr(0, i) + board.substr(j));
				// find the solution on new board with updated hand
				hand[color] -= b;
				int r = dfs(nb, hand);
				if (r >= 0) ans = min(ans, r + b);
				// recover the balls in hand
				hand[color] += b;
			}
			i = j;
		}
		return ans == INT_MAX ? -1 : ans;
	}

	int findMinStep(string board, string hand) {
		// 'a' --> 97
		vector<int> h(128, 0);
		for (char color : hand) h[color]++;
		return dfs(board, h);
	}
};