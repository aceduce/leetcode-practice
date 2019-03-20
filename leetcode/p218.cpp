#include"Solutions.h"
// https://www.youtube.com/watch?v=8Kd-Tn_Rz7s

// sweep line method
// Only need the highest building
class p218::Solution_Heap {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<Event> events;
		vector<pair<int, int>> ans;
		int idx = 0;
		for (auto const & b : buildings) {
			events.push_back(Event(idx, b[0], b[2]));
			events.push_back(Event(idx, b[1], -b[2]));
			idx++;
		}
		sort(events.begin(), events.end());
		// initialize maxheap:
		MaxHeap heap(buildings.size());
		// process the entering/exiting events
		for (const auto & e : events) {
			if (e.h > 0) { // entering
				// pair is {height, id}
				if (e.h > heap.getmax().first) {
					ans.emplace_back(e.x, e.h); // the beaty of emplace_back --> go through constructor!
				}
				heap.insert(e);
			}
			else { // leaving
				heap.remove(e);
				if (-e.h > heap.getmax().first) {
					ans.emplace_back(e.x, heap.getmax().first);
				}
			}
		}
		return ans;
	}

	struct Event {
		int id;
		int x;
		int h;
		Event(int id, int x, int h) :id(id), x(x), h(h) {};
		// sort by x and height
		bool operator<(const Event & e) const {
			if (x == e.x) {
				return h > e.h; // sign is implicitly included into x
			}
			else return x < e.x; // true then rank first
		}
	};

	class MaxHeap {
	public:
		MaxHeap(int max_items) : idx_(max_items, -1), vals_(max_items), size_(0) {} // construtor initialization by lists
		// add element
		void insert(const Event e) { // event id, key is the height
			// size means the size of the maxheap, this is next element, so no -1
			idx_[e.id] = size_; // add the new element to the end of the heap
			vals_[size_] = { e.h, e.id };
			HeaptifyUp(size_);
			size_++;
		}
		// remove element (the key is to find the index)
		void remove(const Event e) { // this is the event id
			// although the e is leaving event, but remove it by the entering from the heap!
			int idx_to_rm = idx_[e.id];
			swapNode(idx_to_rm, size_ - 1); // size means the size of the maxheap
			size_--;
			HeaptifyUp(idx_to_rm);
			HeaptifyDown(idx_to_rm);
		}
		// Obtain the max
		// In the Heap, the ranks is solely decided by height
		// return the max height attached with the event id...
		pair<int, int> getmax() {
			if (isemtpy()) return { 0, 0 };
			return vals_.front();
		}

		// is empty
		bool isemtpy() {
			return size_ == 0; // vals_.empty(); // need to use size_, not vals_.empty
		}

		// int is the index in vals_ vector
		void HeaptifyUp(int i) {
			while (i != 0) { // not at the root node yet
				int p = (i - 1) / 2;
				if (vals_[p] >= vals_[i]) return;
				swapNode(p, i);
				i = p;
			}
		}

		void HeaptifyDown(int i) {
			while (true) {
				int cL = 2 * i + 1;
				int cR = 2 * i + 2;
				if (cL >= size_) return;  // size_: keep count of the final index in the heap
				// the child that needs swap:
				int c = (cR >= size_ ||
					vals_[cL].first > vals_[cR].first) ? cL : cR; // compare the height to decide, the bigger one of the children
				if (vals_[c] <= vals_[i]) return;
				swapNode(c, i);
				i = c;
			}
		}

		// int i & j are the index in the heap (val_)
		void swapNode(int i, int j) {
			if (i == j) return;
			swap(idx_[vals_[i].second], idx_[vals_[j].second]);
			swap(vals_[i], vals_[j]);
		}
	private:
		vector<int> idx_; // natual index: event id, values: the position in the heap
		vector<pair<int, int>> vals_; // max-heap case: {event id, height}, indx is stored by idx_
		// what if we use hashmap? (unordered_map)
		int size_;
	};
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
	