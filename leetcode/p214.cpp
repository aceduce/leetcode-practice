#include "Solutions.h"
// O(n2)
// TLE
string p214::shortestPalindrome_reverse(string s) {
	int n = s.size();
	string rev(s);
	reverse(rev.begin(), rev.end());
	// actual comparisons
	// revese the vector from the start and loop with ending pointer!
	for (int i = 0; i < n; i++) {
		// substring: s[0, n - 1 - i] == > length = n - i
		// reversed -string: rev[i to end
		if (rev.substr(i) == s.substr(0, n - i)) {
			return rev.substr(0, i) + s;
		}
	}
	return "";
}

string p214::shortestPalindrome_superset(string s) {
	int n = s.size();
	int i = 0;
	for (int j = n - 1; j >= 0; j--) {
		if (s[i] == s[j])
			i++; // i times: remaining index is i (not i + 1)
	}
	if (n == i) return s; // key recursive exit condition: perfect palindrome
	string rev = s.substr(i); 
	reverse(rev.begin(), rev.end());
	return rev + shortestPalindrome_superset(s.substr(0, i)) + s.substr(i);
}