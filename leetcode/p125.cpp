#include"Solutions.h"
// isalnum, isalpha, isdigit, ispunct are all valid C++ functions!
bool p125::isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (!isalnum(s[i])) {
			i++; continue;
		}
		if (!isalnum(s[j])) {
			j--; continue;
		}
		if (tolower(s[i]) != tolower(s[j])) return false;
		else {
			i++, j--;
		}
	}
	return true;
}

void p125::test() {
	cout << isPalindrome("0P") << endl;
}

