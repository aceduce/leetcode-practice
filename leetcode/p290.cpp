#include"Solutions.h"
// Need to make sure two-side not dpulicates
	// abba --> dog dog dog dog
	// abba --> dog fish fish bird
bool p290::wordPattern(string pattern, string str) {
	string s;
	stringstream strf(str);
	strf << str;
	unordered_map<char, string> wmap;
	set<string> wd;
	//vector<string> wd;
	int i = 0;
	while (getline(strf, s, ' ')) {
		if (i >= pattern.size())
			return false;
		if (wmap.count(pattern[i]) == 0) {
			if (wd.count(s))
				return false;
			wmap[pattern[i]] = s;
			wd.insert(s);
		}
		else {
			if (wmap[pattern[i]] != s)
				return false;
		}
		i++;
	}
	// need to examine the length
	if (i == pattern.size())
		return true;
	else
		return false;
}