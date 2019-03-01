#include"Solutions.h"
// https://leetcode.com/problems/reverse-words-in-a-string/discuss/47729/C%2B%2B-O(1)-space
string p151::reverseWords_inplace(string s) {
	// Reverse string
	reverse(s.begin(), s.end());
	// Reverse every word
	int i = 0, j = 0;
	while (i != s.size()) {
		while (j < s.size() && s[j] != ' ') j++;
		reverse(s.begin() + i, s.begin() + j);
		i = j;
		while (i < s.size() && s[i] == ' ') i++, j++;
	}
	// Remove extra ' '
	i = 0, j = 0;
	while (j < s.size()) {
		bool new_word = false;
		while (j < s.size() && s[j] == ' ') {
			new_word = true;
			j++;
		}
		if (j == s.size()) break;
		if (new_word && i > 0) s[i++] = ' ';
		s[i++] = s[j++];
	}
	s = s.substr(0, i);
	return s;
}


// use two pointer and extra space
string p151::reverseWords(string s) {
	string word = "";
	string res = "";
	int n = s.size();
	for (int i = 0; i < n; i++) {
		while(s[i] == ' ') i++;
		// i start with real word
		int j = i; // j pointer begin to count
		while (j < n && s[j] != ' ') j++; // if ending doesn't have ' '. this will not work
		word = s.substr(i, j - i);
		i = j;
		// in Java, needs string builders
		// very smart way!
		if(word!= "" && res!= "") word = word + " "; // except initial state!
		res = word + res;
	}
	return res;
}

void p151::test() {
	string s = "  hello world!  ";
	cout << reverseWords_inplace(s) << endl;
}