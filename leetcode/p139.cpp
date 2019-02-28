#include"Solutions.h"
bool p139::wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	// speed up the find/search process with an unordered_map
	unordered_set<string> hset{ wordDict.begin(), wordDict.end() };
	// DP vector
	vector<bool> DP(n + 1, false);
	DP[0] = true;
	for (int i = 1; i <= n; i++) { // i stands for length
		for (int j = i; j >= 1; j--) { // j is the sub-string 
			// separate the string [0, i] into [0, i - j - 1],  [ i - j, i]
			// limit is [0, i -1],   [i , i]
			string w = s.substr(i - j, j);  // sub string: index [i - j] --> [i - 1] total length: i - 1- (i - j) + 1 = j 
			if (hset.count(w) != 0) { // word contains...
				if (DP[i - j]) {
					DP[i] = true;
					break;
				}
			}
		}		
	}
	return DP[n];
}


//"dogs"
//["dog", "s", "gs"]
void p139::test() {
	vector<string> wordDict{ "dog", "s", "gs" };
	string s = "dogs";
	//vector<string> wordDict{ "leet", "code" };
	//string s = "leetcode";
	cout << wordBreak(s, wordDict) << endl;
}