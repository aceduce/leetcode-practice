#include"Solutions.h"
//#include"Helper.h"
// if use reference, cannot pass parameter in function with indx+1
void subRestore(string &s, vector<string> &ans, string tmp, int field, int indx) {
	if (indx == s.size() && field == 4) { // a vlaid answer
		ans.push_back(tmp.substr(1,tmp.size()-1));
		return;
	}
	else if (indx == s.size() || field == 4) return; // not valid answer
	// normal setup: the for loop is not necessary, usually as long as it moves forward...!
	/*
	for (int i = indx; i < s.size(); i++) {
	if (s[i] == '0') continue; // start with zero
	tmp = tmp + s[i]; // push in just one char
	}
	*/
	
	// one character
	subRestore(s, ans, (tmp + "." + s[indx]), field + 1, indx + 1); // just one char
	// two character
	if (s[indx] != '0' && s.size() - 1 - indx >= 1) { // has one more character to add
		subRestore(s, ans, (tmp + "." + s.substr(indx, 2)), field + 1, indx + 2);
	}
	string sub = s.substr(indx, 3);
	if (s[indx] != '0' && s.size() - 1 - indx >= 2 && (stoi(sub) <= 255)) {
		subRestore(s, ans, (tmp + "." + s.substr(indx, 3)), field + 1, indx + 3);
	}
}

vector<string> p93::restoreIpAddresses(string s) {
	vector<string> ans;
	string tmp = "";
	int field = 0;
	subRestore(s, ans, tmp, field, 0);
	return ans;
}

void p93::test() {
	string s = "25525511135";
	vector<string> result = restoreIpAddresses(s);
	//Print<string>(result);
}