#include"Solutions.h"

void p344::reverseString(vector<char>& s) {
	for (int i = 0; i < s.size() / 2; i++) {
		char ch = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = ch;
	}
}


