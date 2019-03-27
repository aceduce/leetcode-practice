#include"Solutions.h"
// Brutal force but with pre-compute SPIRITs (frequentyly observed)
class p363::Solution_BF {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		if (n == 0) return 0;
		int m = matrix[0].size();
		if (m == 0) return 0;
		vector<vector<int>> sum(n, vector<int>(m, 0));
		int res = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// the 1st portion is to compute the 0,0--> i,j matrix
				int t = matrix[i][j];
				// pre-compute 
				if (i > 0) t += sum[i - 1][j];
				if (j > 0) t += sum[i][j - 1];
				if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
				sum[i][j] = t;

				// extract the all the inner rectangulars
				for (int r = 0; r <= i; r++) {
					for (int c = 0; c <= j; c++) {
						// calcualte area from rc-->ij
						int area = sum[i][j];
						if (r > 0) area -= sum[r - 1][j];
						if (c > 0) area -= sum[i][c - 1];
						if (r > 0 && c > 0) area += sum[r - 1][c - 1];
						if (area <= k) {// valid area  case
							res = (res > area) ? res : area;
						}
					}
				}
			}
		}
		return res;
	}
};


// Kadane's algorithms
class Solution_Opt {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		// this can be break down into two problems:
		// 2-D dimension reduction
		// BST add and lower-bound (sum of couple of elements <= k)
		// need to combine the 2nd half with P209

		// 1st Portion : squeeze dimensions
		int res = INT_MIN;
		int n = matrix.size();
		int m = matrix[0].size();
		// pay attentions: two loops
		for (int c = 0; c < m; c++) {
			// two loops in columns!
			vector<int> row(n, 0);
			for (int ci = c; ci < m; ci++) {
				for (int r = 0; r < n; r++) {
					row[r] += matrix[r][ci];
				}
				// get the corresponding row
			// 2nd Portion: BST like P209
				set<int> BST{ 0 };
				// needs to have zero, so itself will be in
				int curSum = 0;
				for (auto const & e : row) {
					curSum += e;
					auto it = BST.lower_bound(curSum - k); // is there already elements/partial sum good enough?
					if (it != BST.end())
						res = max(res, curSum - *it);
					BST.insert(curSum); // easily forget
				}
			}
		}
		return res;
	}
};