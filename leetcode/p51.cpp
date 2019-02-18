#include"Solutions.h"
// clear abstraction for data structures
// in java uses string builder
// position storage: use vector with size n:
// each represents the i th row which column the queen is

bool isValid(vector<int> &q, int value, int pos) { // just check till pos row, as the rest of the rows are not filled
	for (int i = 0; i < pos; i++) {
		if (q[i] == value) // same column 
			return false;
		if (abs(q[i] - value) == (abs(i - pos))) return false; // diagonally aligned
		// abs was firstly aligned wrong...
	}
	return true;
}

void subNQ(vector<int> &q, vector<vector<string>> &ans, int n, int pos) {
	if (pos == n) { // problem solved
		// add into / could be written as a separate helper function
		vector<string> tmp; // create the solution
		for (int i = 0; i < n; i++) {
			string s = ""; // value copy for string
			for (int j = 0; j < n; j++) {
				if (q[i] == j)	s += 'Q';
				else s += '.';
			}
			tmp.push_back(s);
		}
		ans.push_back(tmp);
		return;
	} // only one dimensional traverasl would be enough!
	for (int i = 0; i < n; i++) {
		if (isValid(q, i, pos)) {
			q[pos] = i;
			subNQ(q, ans, n, pos + 1); // pos is valid, move to next row (pos++)
		    //q[pos] = -1; // still need it;
			// seems okay not to moving it back to -1
		} // else continue as it's not valide
	}
}

vector<vector<string>> p51::solveNQueens(int n) {
	vector<vector<string>> ans;
	if (n <= 0) return ans;
	vector<int> q(n, -1);
	subNQ(q, ans, n, 0);
	return ans;
}

void p51::test() {
	// test it on the website!
}