#include"Solutions.h"
#include"Helper.h"
// my attemp: backtracking

// write an is pen function + backtracking
bool p131::isPen(string & s) {
	int n = s.size();
	int i = 0, j = n - 1;
	while (i < j) {
		if (!isalnum(s[i])) {
			i++;
			continue;
		}
		if (!isalnum(s[j])) {
			j--;
			continue;
		}
		if (tolower(s[i]) != tolower(s[j])) {
			return false;
		}
		i++, j--; // easily forgettable 
	}
	return true;	
}

void p131::helper(string s, int index, vector<vector<string>> &ans, vector<string> &tmp) {
	if (index == s.size()) {
		ans.push_back(tmp);
		return;
	}
	if (index > s.size()) return;
	for (int i = 1; i <= s.size() - index; i++) { // wasted loops --> totla length changes 
		// substring: from index to [index + 1, s.size())
			string sub = s.substr(index, i);
			if (isPen(sub)) {
				tmp.push_back(sub);
				helper(s, index + i, ans, tmp);
				tmp.pop_back();
			}
			else continue; // not a pen, then continue a different length
		}
	}


vector<vector<string>> p131::partition_backtrackings(string s) {
	vector<vector<string>> ans;
	vector<string> tmp;
	helper(s, 0, ans, tmp);
	return ans;
}

// refer to https://www.youtube.com/watch?v=WPr1jDh3bUQ 
// backtracing + DP

void p131::helper_DP(vector<vector<bool>> &DP, const string s, int index, vector<vector<string>> &ans, vector<string> &tmp) {
	if (index == s.size()) {
		ans.push_back(tmp);
		return;
	}
	for (int i = index; i < s.size(); i++) {
		if (DP[index][i]) { // from index to i substring ==> DP matrix is for trimming
			string sub = s.substr(index, i - index + 1);
			tmp.push_back(sub);
			helper_DP(DP, s, i + 1, ans, tmp);
			tmp.pop_back();
		}
		
	}
}

//http://bangbingsyb.blogspot.com/2014/11/leetcode-palindrome-partitioning-i-ii.html
vector<vector<string>> p131::partition(string s) {
	int n = s.size();
	vector<vector<bool>> DP(n, vector<bool>(n, false));
	// prep the DP matrix:
	// initilazaiton is done:
	for (int i = 0; i < n; i++) { // diagnoal , one character
		DP[i][i] = true;
	}
	for (int i = 1; i < n; i++) { // for the length of two characters
		if (s[i] == s[i - 1]) {
			DP[i - 1][i] = true;
		}
	}
	for (int len = 3; len <= n; len++) {
		for (int i = n - len; i >= 0; i--) { // loop over the rows
			int j = i + len - 1;
			if (s[i] == s[j] && DP[i + 1][j - 1]) {
				DP[i][j] = true;
			}
		}
	}
	// DP matrix is done
	// need backtracking..
	vector<vector<string>> ans;
	vector<string> tmp;
	helper_DP(DP, s, 0, ans, tmp);
	return ans;
	
}

void p131::test() {
	string s = "aab";
	//cout << isPen(s) << endl;
	vector<vector<string>> ans;
	ans = partition(s);
	Print2D(ans);

}