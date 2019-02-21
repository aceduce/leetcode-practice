#include"Solutions.h"
//#include"Helper.h"
vector<int> p119::getRow(int rowIndex) {
	vector<vector<int>> DP(rowIndex + 1, vector<int>(rowIndex + 1));  // here, rowIndex is true array index (include 0)
																	  // partial fill
	for (int i = 0; i <= rowIndex; i++) {
		DP[i][i] = 1;
		DP[i][0] = 1;
	}// fill the ones!
	for (int i = 2; i <= rowIndex; i++) {
		for (int j = 1; j <= i - 1; j++) {
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}
	return vector<int>(DP[rowIndex].begin(), DP[rowIndex].begin() + rowIndex + 1);
}

void p119::test() {
	vector<int> out = getRow(3);
	//Print(out);

}