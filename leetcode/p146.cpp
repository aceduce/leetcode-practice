#include"Solutions.h"
class p146::LRUCache {
public:
	LRUCache(int capacity) {
		capacity_ = capacity;
	}

	int get(int key) {
		const auto it = m_.find(key);
		if (it == m_.cend()) return -1;
		// has this key, then cache it
		// recency... move from list iterator position at it->second from cache_ to cache_.begin position
		cache_.splice(cache_.begin(), cache_, it->second); // O(1)
		// http://www.cplusplus.com/reference/list/list/splice/ ==> splice particular funcionality
		return it->second->second; // corresponding iterator for the list ->value
	}

	// for unordered_map: first --> key, last --> value
	void put(int key, int value) {
		// key already exist, just want to update
		const auto it = m_.find(key);
		if (it != m_.cend()) { // has such a key already, just need to update its recency
			it->second->second = value;
				// it->second : reaches this key value
			// move the key to the front of the list
			cache_.splice(cache_.begin(), cache_, it->second); //it: an iterator for the list
			return;
		}
		// key doesn't exist

		// reached capacity, remove the oldest
		if (cache_.size() == capacity_) {
			const auto & node = cache_.back(); // the last one
			m_.erase(node.first); // m_ removes by key
			cache_.pop_back();
		}
		// insertion actions
		cache_.emplace_front(key, value); // this is O(1) quickest to the front
		m_[key] = cache_.begin();
	}

private:
	int capacity_;
	// two key data structure!!
	list<pair<int, int>> cache_; // first int is the key, second int is the value
	unordered_map<int, list<pair<int, int>>::iterator> m_; // iterator ~ pointer
};

void p146::test() {
	int capacity = 2;
	LRUCache * obj = new LRUCache(capacity);
	obj->put(1, 1);
	int val = obj->get(1);
}