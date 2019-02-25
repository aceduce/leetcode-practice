#include"Solutions.h"
//#include"Helper.h"
// find the alive nodes and traverse through them
// DFS: in loops, the key is to push into the stack/queue there!!!
void p130::solve(vector<vector<char>>& board) {
	int n = board.size();
	if (n == 0) return;
	int m = board[0].size();
	if (n == 0 || m == 0) return;
	//vector<vector<bool>> alive(n, vector<bool>(m, 0)); --> not a good strucure
	// use a map data structure ==> keep track of all the pairs
	stack<pair<int, int>> alive; // need a queue for DFS;  ==> stack is ok to remove O(1);
	// but set is not good...
	vector<vector<bool>> mask(n, vector<bool>(m, false));
	// find the border for index
	for (int i = 0; i < n; i++) {
		if (board[i][0] == 'O') {
			alive.push(make_pair(i, 0));
			mask[i][0] = true;
		}
		if (board[i][m - 1] == 'O') {
			alive.push(make_pair(i, m - 1));
			mask[i][m - 1] = true;
		}
	}
	for (int j = 0; j < m; j++) {
		if (board[0][j] == 'O') {
			alive.push(make_pair(0, j));
			mask[0][j] = true;
		}
		if (board[n - 1][j] == 'O') {
			alive.push(make_pair(n - 1, j));
			mask[n - 1][j] = true;
		}
	}
	// move for the alive dots
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	while (!alive.empty()) { // DFS
		pair<int, int> dot = alive.top();
		alive.pop();
		int x0 = dot.first;
		int y0 = dot.second;
		for (int i = 0; i < 4; i++) {
			int x = x0 + dx[i]; // need to keep track of both initial x and adapted x
			int y = y0 + dy[i];
			if (x >= 0 && x < n && y < m && y > 0 && mask[x][y] == false) {
				if (board[x][y] == 'O') {
					mask[x][y] = true;
					alive.push(make_pair(x, y));
				}
			}
		}
	}
	
	// mark down already
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mask[i][j])	board[i][j] = 'O';
			else board[i][j] = 'X';
		}
	}

}

void p130::test() {
	//vector<vector<char>> board = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
	vector<vector<char>> board = {};
	solve(board);
	//Print2D(board);
}