#include"Solutions.h"
// better encoding?? https://leetcode.com/problems/repeated-dna-sequences/discuss/249503/C%2B%2B-44ms-beats-94.5
// Time O(n)
vector<string> p187::findRepeatedDnaSequences(string s) {
	// use a hashmap
	// faster if it's encoded into a 10 digits number
	unordered_map<string, int> mp;
	vector<string> ans;
	// cannot do i + 9 <= s.size() -1
	for (int i = 0; i + 10 <= s.size() ; i++) { // starting index number
		string sub = s.substr(i, 10);
		if (mp[sub] == 1) { // this is okay, even w.o this element!
			ans.push_back(sub);
			//continue;
		}
		mp[sub]++;
	}
	return ans;
}

// use a vector is much faster!!
// from Q
int p187::calc(char a) {
	if (a == 'A') return 0;
	if (a == 'C') return 1;
	if (a == 'G') return 2;
	if (a == 'T') return 3;
	return 0;
}

//use vector is smart... 
vector<string> p187::findRepeatedDnaSequences_bits_manipul(string s) {
	vector<string> ret;
	vector<int> appear((1 << 20) + 1, 0);
	int size = s.size();
	for (int l = 0, r = 9; r < size; l++, r++) {
		int value = 0;
		for (int i = l; i <= r; i++)
			value = (value << 2) + calc(s[i]); // use 2 bits to store the information
		appear[value]++;
		if (appear[value] == 2) ret.push_back(s.substr(l, 10));
	}
	return ret;
}

void p187::test() {
	vector<string> ans = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	cout << ans.size();
}