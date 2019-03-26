#include"Solutions.h"
class p345::Solution {
public:
	string reverseVowels(string s) {
		//vector<pair<int, char>> vowel; // index:char
		if (s.size() == 0) return "";
		vector<int> index;
		vector<char> vowels;
		set<char> vset{ 'a', 'e', 'i','o','u', 'A', 'E', 'I','O','U' };
		int i = 0;
		for (auto const & c : s) {
			if (vset.count(c) != 0) {
				vowels.push_back(c);
				index.push_back(i);
			}
			i++;
		}
		reverse(vowels.begin(), vowels.end());
		for (auto const & i : index) {
			s[i] = vowels[i];
		}
		return s;
	}
};

// use two pointers method
string p345::reverseVowels(string s)
{
	string vowels = "aeiou";

	auto is_vowel = [vowels](auto letter) { return vowels.find(tolower(letter)) != string::npos; };

	int i = 0, j = size(s) - 1;

	while (i < j)
	{
		auto is_i_vowel = is_vowel(s[i]);
		auto is_j_vowel = is_vowel(s[j]);

		if (is_i_vowel && is_j_vowel)
		{
			swap(s[i], s[j]);
			++i;
			--j;
			continue;
		}

		if (!is_i_vowel)
		{
			++i;
		}
		if (!is_j_vowel)
		{
			--j;
		}
	}

	return s;
}