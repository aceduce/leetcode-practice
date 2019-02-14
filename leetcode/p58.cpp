#include"Solutions.h"
int p58::lengthOfLastWord(string s) {
	if (s.size() == 0) return 0;
	if (s.size() == 1 && s!=" ") return 1;
	int end = s.size() - 1;
	while (s[end] == ' ' && end>=0) { end--; }

	//if (s == " ") return 0;
	int i = end;
	int count = 0;
	while (i >= 0 && s[i] != ' ') {
		count++;
		i--;
	}
	return count;
}

void p58::test() {
	cout << lengthOfLastWord("Hello World") << endl;
}