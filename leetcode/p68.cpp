#include"Solutions.h"
//#include"Helper.h"

//NEED TO DO MORE PRACTICEES

// brutal force 
// DP method https://www.youtube.com/watch?v=RORuwHiblPc and MIT open course
// You should pack your words in a greedy approach;

//Greedy Method
vector<string> p68::fullJustify(vector<string>& words, int maxWidth) {
	int index = 0;
	vector<string> ans;
	if (words.empty()) return ans;
	// while loop can do more things...
	while (index < words.size()) {
		int count = words[index].size();
		int last = index + 1;
		while (last < words.size() && words[last].size() + count + 1 <= maxWidth) {
			count = count + words[last].size() + 1; // don't forget the +1 here!!
			last++;
		} // the last words is too big to add into
		int diff = last - index - 1; // how many words inserted (how many btw)
		string tmp = words[index]; // every time, tmp will get initialized??
		if (diff == 0 || last == words.size()) { // diff = 0 means just insert one word
			for (int i = index + 1; i < last; i++) {
				tmp = tmp + " " + words[i];
			}
			for (int i = maxWidth - count; i > 0; i--) { // print left over spaces
				tmp += " ";
			}
		}
		else {
			//string tmp;
			// need to consider the intrinsic space
			int num_space = (maxWidth - count)/diff;
			int r = (maxWidth - count) % diff;
			for (int i = index + 1; i < last; i++) {
				for (int j = 0; j < num_space; j++) {
					tmp += " ";
				}
				/*
				// pretty smart way...
				while (r-- > 0) { // the key here is to use r directly, so only the first time it will get consuemd
				tmp += " ";
				}
				*/
				if (r > 0) {
					tmp += " ";
					r--; // evenly distribute the remainers!
				}
				tmp = tmp + " " + words[i]; // the needed space
			}
		}
		ans.push_back(tmp); // one loop done
		index = last;
	}
	return ans;
}

void p68::test() {
	vector<string> words{ "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> ans = fullJustify(words, 16);
	//Print(ans);

}