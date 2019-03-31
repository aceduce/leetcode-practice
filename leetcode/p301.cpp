#include"Solutions.h"
class p301::Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		// Statistics for ( and ) in the string!
		int l = 0;
		int r = 0;
		for (const char ch : s) {
			l += (ch == '(');
			if (l == 0)
				r += (ch == ')');
			else
				l -= (ch == ')');
		}
		vector<string> ans;
		dfs(s, 0, l, r, ans);
		return ans;
	}

private:
	// count number of ( and ) would be great!
	bool isValid(const string & s) {
		int count = 0;
		for (const char ch : s) {
			if (ch == '(') ++count;
			if (ch == ')') --count;
			if (count < 0) return false;
		}
		return count == 0;
	}
	// l/r number of left/right parentheses to remove
	void dfs(const string & s, int start, int l, int r, vector<string> & ans) {
		// nothing to remove:
		if (l == 0 && r == 0) {
			if (isValid(s)) ans.push_back(s);
			return;
		}

		for (int i = start; i < s.length(); i++) {
			// only remove the first parenthess if consecutives
			if (i != start && s[i] == s[i - 1]) continue;

			/*
			if (s[i] == '(' || s[i] == ')') {
				// this is copy, not using reference
				string curr = s;
				curr.erase(i, 1);
				if (r > 0 && s[i] == ')') // need to remove a right bracket
					dfs(curr, i, l, r - 1, ans);
				else if (l > 0 && s[i] == '(') // recursively remove the left bracket
					dfs(curr, i, l - 1,r, ans);
			}
			*/
			if (s[i] == ')' && r > 0) { // erase left first (pruning)
				string curr = s;
				curr.erase(i, 1);
				dfs(curr, i, l, r - 1, ans);
			} 
			else if (s[i] == '(' && l > 0) {
				string curr = s;
				curr.erase(i, 1);
				dfs(curr, i, l - 1, r, ans);
			}		
		}
	}
};