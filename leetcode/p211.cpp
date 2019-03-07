#include"Solutions.h"
class p211::WordDictionary {
public:
	// with Trie Method
	// see from interview before
	/** Initialize your data structure here. */
	WordDictionary() :root_(new TrieNode) { // constructor	
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode * p = root_.get();
		for (auto const & ch : word) {
			if (!p->children[ch - 'a']) {
				p->children[ch - 'a'] = new TrieNode;
			}
			p = p->children[ch - 'a'];
		}
		p->isword = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		TrieNode * tmp = find(root_.get(), word, 0);
		if (tmp && tmp->isword) return true;
		else return false;
	}
private:
	// Need to use TrieNode datastructure!
	struct TrieNode {
		TrieNode() :isword(false), children(26, NULL) {};
		~TrieNode() {
			for (const auto & c : children) {
				if (c) delete c;
			}
		}
		bool isword;
		vector<TrieNode *> children;
	};

	TrieNode * find(TrieNode * r, const string & word, int index) {
		if (!r) return NULL;
		if (index == word.size()) return r;
		//for (int i = index; i < word.size(); i++) {
		if (word[index] != '.') {
			if (r->children[word[index] - 'a'])
				return find(r->children[word[index] - 'a'], word, index + 1);
			else
				return NULL;
		}
		else { // deal with '.' character
			for (auto const & child : r->children) { // search every letters
				TrieNode * t = find(child, word, index + 1);
				// NEED TO CHECK IF t is not NULL!!!
				if (child && t&& t->isword) // KEY NEED TO HAVE ISWORD!!!! OTHERWISE, adds is not found!!
					return t; // find that path..
			}
		}
		return NULL;
		//}
	}
	unique_ptr<TrieNode> root_;
};

void p211::test() {
	WordDictionary wd;
	wd.addWord("ran");
	wd.addWord("rune");
	wd.addWord("runner");
	wd.addWord("runs");
	wd.addWord("add");
	wd.addWord("adds");
	wd.addWord("adder");
	wd.addWord("addee");
	cout << wd.search("add") << endl;
	cout << wd.search("add.") << endl;
	//cout << wd.search(".ad") << endl;
	//cout << wd.search("b..") << endl;

	system("pause");
}