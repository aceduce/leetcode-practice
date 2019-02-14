#include "Solutions.h"
// the map assignment part, is it deep copy or shallow copY?
// return a local vector!
vector<int> Solutions::p30::findSubstring(string s, vector<string>& words) {
	vector<int> ans; // return the local vector...
	if (words.size() == 0 || s.size() == 0) return ans;
	unordered_map<string, int> map_keep;
	unordered_map<string, int> map;
	for (auto const &w : words) map_keep[w]++; // easist way to initialize, easier than INSERT step by step
	int count = words.size();
	int n = s.size(); // otherwise, unsigned_int overflow
					  //int wsize = (int)words[0].length();
	int wsize = words[0].size(); // use size as it's not size_t (unsigned int)
	for (int i = 0; i < n - count * wsize + 1; i++) { //need + 1
		unordered_map<string, int> map = map_keep; // this is deep copy? 
		int j;
		// map = map_keep;
		for (j = 0; j < count; j++) {
			if (map.find(s.substr(j *wsize + i, wsize)) != map.end()) {
				if (map[s.substr(j*wsize + i, wsize)] > 0) {
					map[s.substr(j*wsize + i, wsize)]--;
				}
				else {
					break; // too many same words
				}
			}
			else { // no such word
				break;
			}
			// find all the words
		}
		if (j == count) {
			ans.push_back(i);
		}
	}
	return ans;
}