#include"Solutions.h"
class p208::Trie {
public:
	/** Initialize your data structure here. */
	Trie() : root_(new TrieNode()) {};

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode * p = root_.get(); // smart pointer needs to use get()
		for (auto const & w : word) {
			if (!p->children[w - 'a']) {
				p->children[w - 'a'] = new TrieNode();
			}
			p = p->children[w - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		const TrieNode * p = find(word);
		return p && p->is_word; // must be a word
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		const TrieNode * p = find(prefix);
		return p != NULL;
	}


private:
	struct TrieNode {
		TrieNode() : is_word(false), children(26, NULL) {};
		~TrieNode() {
			for (TrieNode * child : children) { // free the memory!
				if (child) delete child;
			}
		}
		bool is_word;
		vector<TrieNode*> children; // vector length of 26
	};
	const TrieNode* find(const string & prefix) const {
		const TrieNode * p = root_.get();
		for (const char c : prefix) {
			p = p->children[c - 'a']; // convert to index
			if (p == NULL) break;
		}
		return p; // could return a NULL if not exist!
	}
	unique_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */