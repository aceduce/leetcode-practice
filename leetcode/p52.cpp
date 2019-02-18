#include"Solutions.h"

bool p52::isValid(vector<int> &q, int value, int pos) { // just check till pos row, as the rest of the rows are not filled
	for (int i = 0; i < pos; i++) {
		if (q[i] == value) // same column 
			return false;
		if (abs(q[i] - value) == (abs(i - pos))) return false; // diagonally aligned
															   // abs was firstly aligned wrong...
	}
	return true;
}

void p52::subNQ(vector<int> &q, int &ans, int n, int pos) {
	if (pos == n) { // problem solved
					// add into / could be written as a separate helper function
		ans++;
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
int p52::totalNQueens(int n) {
	int ans;
	if (n <= 0) return 0;
	vector<int> q(n, 0);
	subNQ(q, ans, n, 0);
	return ans;
}

void p52::test() {

}