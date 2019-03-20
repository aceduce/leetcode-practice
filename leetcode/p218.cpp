#include"Solutions.h"
// https://www.youtube.com/watch?v=8Kd-Tn_Rz7s

// sweep line method
// Only need the highest building
class p218::Solution { // using heap
	// heap implentations
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

	}
};

// output data format: (x, y)
// input data format: [left, right, height]
// method #2 with Balanced Binary Search Tree
class p218::Solution_BST {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		typedef pair<int, int> Event; // this is like a structure/ synonym
		vector<Event> es;
		hs_.clear();
		vector<pair<int, int>> ans;
		for (const auto & b : buildings) {
			es.emplace_back(b[0], b[2]); // entering event; left, height
			es.emplace_back(b[1], -b[2]); // exiting event; right, height
		}
		// Sort events by x
		// lambda function for sorting...
		sort(es.begin(), es.end(), [](const Event & e1, const Event &e2) {
			if (e1.first == e2.first) return e1.second > e2.second; // same enterting, rank by height ==> this is necessary for entering & leaving..
			// leaving always comes later (height < 0)
			// leaving ranks from lower --> higher
			return e1.first < e2.first;
		});

		// process all the events
		for (const auto & e : es) {
			int x = e.first;
			bool entering = e.second > 0;
			int h = abs(e.second);
			if (entering) {
				if (h > maxHeight())
					ans.emplace_back(x, h);
				hs_.insert(h);
			}
			else { // leaving case
				hs_.erase(hs_.equal_range(h).first); // mutiset could have mutliple same values, equal range just shows the iterators!
				if (h > maxHeight())
					ans.emplace_back(x, maxHeight());
			}
		}
		return ans;
	}
private: // event data structure
	int maxHeight() const {
		if (hs_.empty()) return 0;
		else return *hs_.rbegin();
	}
	multiset<int> hs_; // BST just store the heights
	// BST
};
	