#include"Solutions.h"
//#include"Helper.h"
// trie-tree + BFS 
// combined toghether

//https://leetcode.com/problems/word-search-ii/discuss/59780/Java-15ms-Easiest-Solution-(100.00)
class TrieNode {
public:
	vector<TrieNode *> next = vector<TrieNode *>(26); // in-place initialization
	string word;
};

TrieNode * buildTrie(vector<string> words) {
	TrieNode * root = new TrieNode;
	for (auto word : words) {
		TrieNode * p = root;
		for (auto c : word) {
			int i = c - 'a';
			if (p->next[i] == NULL) {
				p->next[i] = new TrieNode;
			}
			p = p->next[i];
		}
		p->word = word;
	}
	return root;
}

// should not use & for TrieNode there! other wise wrong...
void dfs(vector<vector<char>>& board, int i, int j, TrieNode * p, vector<string> &ans) {
	// out of bound!
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
	char c = board[i][j];
	// visited before or word corresponding to a word start?
	if (c == '#' || p->next[c - 'a'] == NULL) return;
	p = p->next[c - 'a'];
	if (!p->word.empty()) { // end of word--> searched out already
		ans.push_back(p->word);
		p->word = ""; // de-duplicate
	}
	// back-tracking:
	board[i][j] = '#';
	if (i > 0) dfs(board, i - 1, j, p, ans);
	if (j > 0) dfs(board, i, j - 1, p, ans);
	if (i < board.size() - 1) dfs(board, i + 1, j, p, ans);
	if (j < board[0].size() - 1) dfs(board, i, j + 1, p, ans);
	board[i][j] = c; // visited already, put back
}

vector<string> p212::findWords(vector<vector<char>>& board, vector<string>& words) {
	// create trie-tree
	vector<string> ans;
	TrieNode * root = buildTrie(words);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			dfs(board, i, j, root, ans);
		}
	}
	return ans;
}

void p212::test() {
	vector <vector<char>> board = {{ 'o','a','a','n' },
									{ 'e','t','a','e' },
									{ 'i','h','k','r' },
									{ 'i','f','l','v' }};
	vector<string> word = vector<string>{ "oath", "pea", "eat", "rain" };
	//Print(findWords(board, word));
}