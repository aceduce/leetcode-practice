#include"Solutions.h"

// quick solution from link
bool p205::isIsomorphic(string s, string t) {
	int m1[256] = { 0 }, m2[256] = { 0 }, n = s.size();
	for (int i = 0; i < n; ++i) {
		if (m1[s[i]] != m2[t[i]]) return false;
		m1[s[i]] = i + 1;
		m2[t[i]] = i + 1;
	}
	return true;
}

bool p205::isIsomorphic_my(string s, string t) {
	unordered_map<char, char> map;
	set<char> set;
	if (s.size() != t.size()) return false;
	for (int i = 0; i < s.size(); i++) {
		if (map.count(s[i]) != 0) { // has index
			if (map[s[i]] != t[i])
				return false;
			continue;
		}
		map[s[i]] = t[i];
		if (set.count(t[i]) != 0) return false; // prevent both map to same letter
		set.insert(t[i]);
	}
	return true;
}


void p205::test() {
	cout << isIsomorphic("paper", "title") << endl;
	system("pause");
}