#include"Solutions.h"
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (magazine.size() < ransomNote.size())
			return false;
		unordered_map<char, int> map;
		for (auto const & c : magazine)
			map[c]++;
		for (auto const & n : ransomNote) {
			if (map.count(n) == 0 || map[n] == 0)
				return false;
			else map[n]--;
		}
		return true;
	}
};