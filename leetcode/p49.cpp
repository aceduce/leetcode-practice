# include"Solutions.h"

//string to char array and then sort
// use a hashmap data structure ==> unorder map in C++
// the vector<string> piece is just inserting a new object?
vector<vector<string>> p49::groupAnagrams(vector<string>& strs) {
	vector<vector<string>> ans;
	unordered_map<string, vector<string> > map;
	for (int i = 0; i < strs.size(); i++) {
		string key = strs[i]; // need to make a duplicate, otherwise, the STL will sort the string itself!!
		sort(key.begin(), key.end());
		if (map.find(key) == map.end()) { // no such key, need insertion
			map.insert(make_pair(key, vector<string>{ strs[i] }));
		}
		else {
			map.at(key).push_back(strs[i]);
		}
	}
	for (unordered_map<string, vector<string> >::iterator i = map.begin();
		i != map.end(); i++) {
		ans.push_back(i->second);
	}
	return ans;
}

void p49::test() {
	vector<string> inp{ "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ans = groupAnagrams(inp);
	for (vector<vector<string>>::iterator i = ans.begin();
		i != ans.end(); i++) {
		cout << " [ ";
		for (int j = 0; j < (*i).size(); j++) {
			cout << (*i)[j] << " ";
		}
		cout << " ]" << endl;
	}
}