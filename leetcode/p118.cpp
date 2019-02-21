#include"Solutions.h"
//#include"Helper.h"

// Time: O(n^2) : two loops
//
vector<vector<int>> p118::generate_simple(int numRows) {
	vector<int> tmp (numRows, 0); // compute array (enough size)
	vector<vector<int>> ans;
	fill(tmp.begin(), tmp.begin() + 2, 1); // fill right size exclusive
	for (int i = 3; i <= numRows; i++) {
		vector<int> v;
		tmp.push_back(1);
		for (int j = 1; j <= i - 2; j++) {
			v.push_back(tmp[j] + tmp[j - 1]);
		}
		v.push_back(1);
		copy(v.begin(), v.end(), tmp.begin());
		ans.push_back(v);
	}
	return ans;
}

// an interesting case when calling the + in insert
// key is to create a 1, 1, 3, 3, 1 matrix
// calculate into     1, 4, 6, 4, 1
// then again         1, 1, 4, 6, 4, 1...
// calcualte into     1, 5, 10...

vector<vector<int>> p118::generate_clever(int numRows) {
	vector<int> tmp;
	vector<vector<int>>ans;
	for (int i = 0; i < numRows; i++) {
		tmp.insert(tmp.begin(), 1);
		for (int j = 1; j <tmp.size() - 1; j++) {
			tmp[j] = tmp[j] + tmp[j + 1];
		}
		ans.push_back(tmp);
	}
	return ans;
}

// using DP method:
vector<vector<int>> p118::generate(int numRows) {
	vector<vector<int>> DP(numRows, vector<int>(numRows, 0));
	vector<vector<int>> ans;
	// partial fill
	for (int i = 0; i < numRows; i++) {
		DP[i][i] = 1;
		DP[i][0] = 1;
	}// fill the ones!
	for (int i = 2; i < numRows; i++) {
		for (int j = 1; j <= i - 1; j++) {
			DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}
	for (int i = 0; i < numRows; i++) {
		ans.push_back(vector<int>(DP[i].begin(), DP[i].begin() + i + 1));
	}
	return ans;
}

void p118::test() {
	vector<vector<int>>ans = generate(5);
	///Print2D(ans);
}