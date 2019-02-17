#include"Solutions.h"
string p76::minWindow(string s, string t) {
	// sliding window is very important!!
	int cnt[128] = { 0 };// very important, initalize to zero!
	for (char c : t) { // count the inital array
		cnt[c]++;
	}
	int total = t.size();
	int i = 0, j = 0;
	int min = INT_MAX;
	int from = 0;
	// the essential of using i, j pointer
	for (i = 0; i < s.size(); i++) {
		if (cnt[s[i]]-- > 0) {
			total--;
		}
		// moving j poiner if i has effective t: total = 0
		while (total == 0) {
			if (min > i - j + 1) {
				min = i - j + 1;
				from = j;
			}
			if (++cnt[s[j++]] > 0) total++;
		}
		// total not euqals to zero, begin to move i pointer
		// none key char will be min enough to compensate the +
	}
	return (min == INT_MAX) ? "" : s.substr(from, min);
}



void p76::test() {
	string input = "ADOBECODEBANC";
	string t = "ABC";
	cout << minWindow(input, t) << endl;;
}

