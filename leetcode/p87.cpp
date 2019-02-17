#include"Solutions.h"
// divide and conquer
// with iterative method!!
// a typical !!
bool p87::isScramble(string s1, string s2) { 
	// when divide, we avoid the empty cases
	if (s1.size() != s2.size() || s1.empty() || s2.empty()) return false; 
	//if (s1 == s2 && s1.size() == 1) return true; // same individual string // can take out the length??
	if (s1 == s2) return true; // essential exit condition
	string a = s1;
	string b = s2;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a != b) return false; // speed up the performance!!

	// key divide and conquer piece:
	for (int s1_len = 1; s1_len < s1.size(); s1_len++) { // make sure non-zero division on left and right
		// s1: s1_len
		string s1_l = s1.substr(0, s1_len);
		string s1_r = s1.substr(s1_len, s1.size() - s1_len); 
		// a bit complicated in s2:
		string s2_l = s2.substr(0, s1_len);
		string s2_r = s2.substr(s1_len, s2.size() - s1_len);
		// considering conunting on the right: like a eat, tae case
		string s2_ll = s2.substr(0, s2.size() - s1_len);
		string s2_rr = s2.substr(s2.size() - s1_len, s1_len);

		if ((isScramble(s1_l, s2_l) && isScramble(s1_r, s2_r)) ||
			isScramble(s1_r, s2_ll) && isScramble(s1_l, s2_rr))
			return true;
	}
	return false;
}


void p87::test() {
	//t();
	cout << isScramble("great", "rgeat") << endl;
	cout << isScramble("great", "rgtae") << endl;
	cout << isScramble("abcde", "caebd") << endl;
}