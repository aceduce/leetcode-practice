#include"Solutions.h"
//#include"Helper.h"

// BFS finding the path and DFS search thorugh 
// inspired by HuaHua
// an Helper funct
// comes with Solution A (working with queue)
void p126::buildback_BFSDFS(const string &beginWord,
	const string &EndWord,
	const unordered_map<string, vector<string>> &parents,
	const string parent,
	vector<string> &curr, // remmber to push back
	vector<vector<string>> &ans)
{
	if (parent == beginWord) { // find the answer already
		// need to make a copy
		// should not reverese it directly
		ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
		return;
	}
	for (auto & p : parents.at(parent)) { // Given we use const reference, it won't create ..
		curr.push_back(p);
		buildback_BFSDFS(beginWord, EndWord, parents, p, curr, ans);
		curr.pop_back();
	}
}
// use a queue based data structure for BFS
// BFS with quque
// Solution A:
vector<vector<string>> p126::findLadders_BFSDFS(string beginWord, string endWord, vector<string>& wordList) {
	int l = beginWord.size();
	vector<vector<string>> ans;
	unordered_set<string> dict{ wordList.begin(), wordList.end() };
	if (!dict.count(endWord)) return ans;
	dict.erase(beginWord);
	dict.erase(endWord); // should not derive back
	unordered_map<string, int> steps; // record how many steps to derive to this word
	//steps[beginWord] = 0;
	unordered_map<string, vector<string>> parents; // record the parents for derived data
	queue<string> q;
	q.push(beginWord);
	int step = 0;
	bool found = false;
	while (!q.empty() && (!found)) {
		step++; // step for each level needs to ++
		for (int i = q.size(); i > 0; i--) {
			string p = q.front(); q.pop();
			string w = p; // p needs to be alive

			for (int j = 0; j < l; j++) {
				char ch = w[j];
				for (int k = 'a'; k <= 'z'; k++) {
					w[j] = k;
					if (w == endWord) {
						found = true; // not quit immediately
						parents[w].push_back(p);
						steps[w] = steps[p] + 1;
					}
					else {
						// not the end word, but an existing one, and valid one at this layer
						if (steps.count(w) && (step + 1 == steps.at(w))) { // need to check the # of steps
							parents[w].push_back(p); // current step = steps[q] = steps[w] -1;
						}
					}
					// w[j] = ch; too early!
					if (!dict.count(w))  continue; //erase strategy doesn't change; so if w found before, it will not process futher
					// a w not found before and in the dic
					dict.erase(w);
					steps[w] = step + 1;
					parents[w].push_back(p);
					q.push(w); // need to put into q for BFS next level/step
					//w[j] = ch;	 // this is too late!		
				}
				w[j] = ch;	 // this is the right place
			}
		}  // this is the end of the layer, if found , no need to pursue further
		// we keep the parents in the hashmap, so only need to trace back after finish the whole lvel
		if (found) {
			vector<string> curr{ endWord }; // this is for trace back
			buildback_BFSDFS(beginWord, endWord, parents, endWord, curr, ans);
		}
	}
	//cout << "Find it? " << found << endl;
	return ans;
}

// Solutiion B:
// use two hashset --> needed for BFS
// another change is on the childen data structure (parents's childen in the vector>
// DFS is more intuive? 
// the thinking is to clear up the this layer's words in the dict!!!!


void p126::build_forward(const string & begin, const string & end,
	vector<string> &tmp,
	const string cur,
	const unordered_map<string, vector<string>> &childtree,
	vector<vector<string>> &ans) {

	if (cur == end) { // found an answer already
		//tmp.push_back(cur);
		ans.push_back(tmp);
		return;
	}
	// need to take special care if 
	if (childtree.find(cur) == childtree.end())  // no such element (this will happen at the end
		return;
	for (auto const & ch : childtree.at(cur)) {
		tmp.push_back(ch);
		build_forward(begin, end, tmp, ch, childtree, ans);
		tmp.pop_back();
	}

}

vector<vector<string>> p126::findLadders_BFSDFS_sets(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> ans;
	unordered_set<string> dict{ wordList.begin(), wordList.end() };
	if (!dict.count(endWord)) return ans;
	vector<string> tmp;
	dict.erase(beginWord);
	dict.erase(endWord);
	int l = beginWord.size();
	// BFS
	unordered_set<string> stack1{ beginWord };

	// keep track for DFS
	unordered_map<string, vector<string>> child; // collect the children
	bool found = false;
	// steps are not needed??
	// BFS starts
	while (!stack1.empty() && !found) {
		unordered_set<string> stack2; // facilliate the BFS stack (would need to swap)

		for (auto const & w : stack1) { // way to traverse stack
			dict.erase(w);
		}
		// child and parent should not have same elements [Erase intuition]

		for (auto const & p : stack1) {
			string w = p;
			for (int j = 0; j < l; j++) {
				char ch = w[j];
				for (int k = 'a'; k <= 'z'; k++) {
					w[j] = k;
					if (endWord == w) {
						child[p].push_back(w);
						found = true;
						// but no need to add into stack2
					}
					// ?? why need to add !found??
					else if (dict.count(w) && !found) { // a word found before
						child[p].push_back(w);
						stack2.insert(w); // need to visit next ==> this need to be not found, need need to add/visit next layer
						// could do multiple insetion, no duplicate issues
					}
				}
				w[j] = ch;
			}
		}
		swap(stack1, stack2);
		stack2.clear();
	}
	if (found) {
		vector<string> tmp{ beginWord };
		build_forward(beginWord, endWord, tmp, beginWord, child, ans);
	}
	return ans;
}

// Solution C:
vector<vector<string>> p126::findLadders(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> ans;
	unordered_set<string> dict{ wordList.begin(), wordList.end() };
	if (!dict.count(endWord)) return ans;
	vector<string> tmp;
	dict.erase(beginWord);
	dict.erase(endWord);
	int l = beginWord.size();
	// BFS
	unordered_set<string> stackb{ beginWord };
	unordered_set<string> stacke{ endWord };
	// keep track for DFS
	unordered_map<string, vector<string>> child; // collect the children
	bool found = false;
	bool forward = true;

	//Bi-BFS
	while (!stackb.empty() && !stacke.empty() && !found) {
		if (stackb.size() > stacke.size()) {
			swap(stackb, stacke);
			forward = !forward;
		}
		// at one level, clear up the dictionary
		for (const auto & w : stackb) {
			dict.erase(w);
		}
		// need to understand why clean up two togher
		for (const auto & w : stacke) {
			dict.erase(w);
		}
		unordered_set<string> tmp;
		for (auto const &p : stackb) {
			string w = p;

			for (int i = 0; i < l; i++) {
				char ch = w[i];
				for (int j = 'a'; j <= 'z'; j++) {
					w[i] = j;
					// consider bi-dirctional case
					if (stacke.count(w)) { // found a path already
						found = true;
						if (forward) {
							child[p].push_back(w);
						}
						else {
							child[w].push_back(p);
						}
					}
					else if (!found && dict.count(w)) { // the word exist
						tmp.insert(w);
						if (forward) {
							child[p].push_back(w);
						}
						else {
							child[w].push_back(p);
						}
					}
				}
				w[i] = ch;
			}
		}
		swap(stackb, tmp);
	}
	//cout << "find?? " << found << endl;
	if (found) {
		vector<string> tmp{ beginWord };
		string cur;
		build_forward(beginWord, endWord, tmp, beginWord, child, ans);
		//build_forward(beginWord, endWord, tmp, beginWord, child, ans);
	}
	return ans;
}
void p126::test() {
	vector<string> pool{ "hot","dot","dog","lot","log","cog" };
	string beg = "hit";
	string end = "cog";
	//vector<string> pool{ "a", "b", "c" };
	//string beg = "a";
	//string end = "c";
	findLadders(beg, end, pool);
	//Print2D(findLadders(beg, end, pool));

}