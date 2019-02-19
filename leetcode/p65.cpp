#include"Solutions.h"

// corner cases...
// could be ignored...
bool p65::isNumber(string s) {
	int i = 0; // start and moving forward
	int len = s.size();
	bool digit = false; // has to have some numbers to qualify as digits

	while (i < len && s[i] == ' ') { // skip all the white spaces
		i++;
	}
	if (s[i] == '+' || s[i] == '-') i++; // no need to do anything here
	while (i < len && isdigit(s[i])) {
		i++;
		digit = true;
	}
	// could encounter '.' or 'e'
	if (s[i] == '.') {
		i++;
		while (i < len && isdigit(s[i])) {
			i++;
			digit = true;
		}
	}
	// numbers like 3. is okay
	
	if (s[i] == 'e' && digit == true) { // has to have number comes before e ==> missing
		digit = false; // after e must have numbers
		i++;
		// need to have a positive or negative check: ==> missing
		if (i < len && (s[i] == '+' || s[i] == '-')) i++;
		while (i < len && isdigit(s[i])) {
			i++;
			digit = true;
		}
	}

	// need to hanle the left spaces ==> missing 
	while (i < len && s[i] == ' ') i++;
	if (i == s.size() && digit) return true;
	return false;
}


void p65::test() {
	cout << isNumber("0");

}