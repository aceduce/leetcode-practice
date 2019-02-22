#include"Solutions.h"

// this is a search quetions 
// using BFS 
// bi-directoinal and DFS
// Solutin A: one-directional BFS (w/o optimization) 
// Data Structure used:   // 104 ms
int p127::ladderLength_hashset_BFS(string beginWord, string endWord, vector<string>& wordList) {  
	// used HashSet in this case
	// typical maniupulation of HashSet
	unordered_set<string> dict{ wordList.begin(), wordList.end() };  // operating dictionary
	// unordered_set usually doesn't pop!
	if (!dict.count(endWord)) return 0; // not containing end word
	int l = beginWord.size();
	// order doesn't matter, I don't use queue (try queue later)
	unordered_set<string> w_set;
	w_set.insert(beginWord);
	int step = 0;
	while (!w_set.empty()) {  // BFS visit
		unordered_set<string> w_set_tmp;
		step++;
		for (auto w :w_set) { // travel all set values
			for (int i = 0; i < l; i++) {
				char c = w[i];
				for (int j = 'a'; j <= 'z'; j++) {
					w[i] = j;
					if (w == endWord) return ++step;
					if (dict.count(w) == 0) continue; // not in dict [* this is the KEY!!
					else {

						dict.erase(w); // don't want to have it any more
						w_set_tmp.insert(w); // for further look up 
					}
				}
				w[i] = c; // change back
			}
		}
		w_set.swap(w_set_tmp);
		w_set_tmp.clear(); // redues to 92 ms
	}
	return 0; // didn't find it!
}

// Solution A-1: change data structure, with one trimming : QUEUE 100 ms
int p127::ladderLength_queue_BFS(string beginWord, string endWord, vector<string>& wordList) {
	// used HashSet in this case
	// typical maniupulation of HashSet
	unordered_set<string> dict{ wordList.begin(), wordList.end() };  // operating dictionary
	// unordered_set usually doesn't pop!
	if (!dict.count(endWord)) return 0; // not containing end word
	int l = beginWord.size();
	// order doesn't matter, use queue here
	queue<string> q;
	q.push(beginWord);
	int step = 0;
	while (!q.empty()) {  // BFS visit
		step++;
		int size = q.size();
		for (int k = 0; k < size; k++) { // travel all set values
			// a smarter way for this loop is like this: for(int k = q.size(); k > 0; k--) ... avoid the q.size change
			string w = q.front();
			q.pop();
			for (int i = 0; i < l; i++) {
				char c = w[i];
				for (int j = 'a'; j <= 'z'; j++) {
					w[i] = j;
					if (w == endWord) return ++step;
					if (dict.count(w) == 0) continue; // not in dict [* this is the KEY!!
					else {
						dict.erase(w); // don't want to have it any more
						q.push(w); // for further look up 
					}
				}
				w[i] = c; // change back
			}
		}
	}
	return 0; // didn't find it!
}

// Solution A-2: change data structure, with one trimming : 104 ms
// a subtle optimizations, turns out its worst. As the diction is delte...
int p127::ladderLength_worse(string beginWord, string endWord, vector<string>& wordList) {
	// used HashSet in this case
	// typical maniupulation of HashSet
	unordered_set<string> dict{ wordList.begin(), wordList.end() };  // operating dictionary
	// unordered_set usually doesn't pop!
	if (!dict.count(endWord)) return 0; // not containing end word
	int l = beginWord.size();
	// order doesn't matter, I don't use queue (try queue later)
	unordered_map<string, int> w_map; // only for optimizatoin
	unordered_set<string> w_set;
	w_map[beginWord] = -1; // not swapping from any character
	w_set.insert(beginWord);
	int step = 0;
	while (!w_set.empty()) {  // BFS visit
		unordered_set<string> w_set_tmp;
		step++;
		for (auto w : w_set) { // travel all set values
			int loc = w_map[w]; // it convertes from here
			for (int i = 0; i < l; i++) {
				if (loc == i) continue;
				char c = w[i];
				for (int j = 'a'; j <= 'z'; j++) {
					w[i] = j;
					if (w == endWord) return ++step;
					if (dict.count(w) == 0) continue; // not in dict [* this is the KEY!! // this trimming is very powerful!
					// the optimization will be skipped as the dict erase the item already
					else {
						w_map[w] = i;
						dict.erase(w); // don't want to have it any more
						w_set_tmp.insert(w); // for further look up 
					}
				}
				w[i] = c; // change back
			}
		}
		w_set.swap(w_set_tmp);
		w_set_tmp.clear(); // redues to 92 ms
	}
	return 0; // didn't find it!
}

// Solution B: Bi-directional BFS
// use two hashsets
int p127::ladderLength(string beginWord, string endWord, vector<string>& wordList) {  //32ms
	unordered_set<string> dict{ wordList.begin(), wordList.end() };
	if (!dict.count(endWord)) return 0;
	unordered_set<string> set_begin{ beginWord };
	unordered_set<string> set_end{ endWord };
	int step = 0, l = beginWord.size();
	while (!set_begin.empty() && !set_end.empty()) {
		step++;
		if (set_begin.size() > set_end.size()) set_begin.swap(set_end); // always expand the shallow one
		unordered_set<string> set_tmp;
		for (auto w : set_begin) {
			for (int i = 0; i < l; i++) {
				char ch = w[i];
				for (int j = 'a'; j < 'z'; j++) {
					w[i] = j;
					// **** if (w == endWord) return ++step; // wrong!!
					if (set_end.count(w) != 0) return step + 1;
					if (!dict.count(w)) continue;
					else {
						dict.erase(w);
						set_tmp.insert(w);
					}
				}
				w[i] = ch;
			}
		}
		set_tmp.swap(set_begin);
		set_tmp.clear();
	}
	return 0;
}


void p127::test() {
	vector<string> input{ "hot","dot","dog","lot","log","cog" };
	cout << ladderLength("hit", "cog", input) << endl;
}