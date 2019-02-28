#include"Solutions.h"
#include"Helper.h"
// use backtracking method
// need memorization otherwise, TLE
void p140::subwordBreak(string &s, unordered_set<string> &set, int index, vector<string> &ans, string & tmp) {
	if (index >= s.size()) {
		ans.push_back(tmp.substr(0, tmp.size() - 1));
		return;
	}
	for (int i = index; i < s.size(); i++) {
		string sub = s.substr(index, i - index + 1);  // start: index, end: i
		if (set.count(sub) != 0) {
			string t = tmp;
			tmp = tmp + sub + ' ';
			subwordBreak(s, set, i + 1, ans, tmp);
			tmp = t;
		} 
	}
}


// need to change the structure
// need a copy for string s
// this new structure, return sub-string is tricky...
vector<string> p140::subwordBreak_w_Opt(string s, unordered_set<string> &set,
	unordered_map<string, vector<string>> & used) {
	vector<string> flag = {"!!" };
	if (used.count(s)) return used[s];
	if (s.length() == 0) return flag;// null vector in C++==> need a unique way
	// if no match, should return an empty list
	vector<string> res = {};
	for (int i = 1; i <= s.size(); i++) {
		string sub = s.substr(0, i); // different length, index from 0--> i
		
		vector<string> pres;
		if (set.count(sub)) {
			pres = subwordBreak_w_Opt(s.substr(i), set, used); // index from i  to the end
			// by default, all till the end!
			if (pres == flag) res.push_back(sub); // reaches the end already!
			else {
				for (auto const & str : pres) { // empty list won't get into this loop
					res.push_back(sub + " " + str);
				}
			}
		}
	}
	used.insert(make_pair(s, res));
	return res;
}

vector<string> p140::wordBreak(string s, vector<string>& wordDict) {
	vector<string> ans; 
	unordered_set<string> set{ wordDict.begin(), wordDict.end() };
	string tmp;
	// optimization with a used data-structure
	unordered_map<string, vector<string>> used;
	ans = subwordBreak_w_Opt(s, set, used);
	return ans;
}


/*
"catsandog"
["cats","dog","sand","and","cat"]
*/
void p140::test() {
	vector<string> ans;
	string s = "catsanddog";
	vector<string> wordDict = { "cats","dog","sand","and","cat" };
	ans = wordBreak(s, wordDict);
	Print(ans);
}