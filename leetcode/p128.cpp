#include"Solutions.h"
// if sort, then O(nlogN)
int p128::longestConsecutive_my(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	unordered_map<int, int> hashmap; // store (key, len)
	for (int i = 0; i < nums.size(); i++) {
		if (hashmap.count(nums[i])) continue; // deal with duplicates
		if (hashmap.count(nums[i] - 1) == 0 && hashmap.count(nums[i] + 1) == 0) // a single node, w/o neighthobr
			hashmap.insert(make_pair(nums[i], 1));
		else if (hashmap.count(nums[i] - 1) != 0 && hashmap.count(nums[i] + 1) != 0) {
			// has two neighbors, a bridge
			int left = hashmap[nums[i] - 1], right = hashmap[nums[i] + 1];
			// pretty much well designed method!
			int l = nums[i] - 1 - left + 1; // starting index  ==> this piece is a bit redundant!
			int r = nums[i] + 1 + right - 1; // ending index  => this piece is a bit redundant!
			hashmap[l] = left + right + 1;
			hashmap[r] = left + right + 1;
			// still need to insert the corresponding elements, although not updated..
			hashmap[nums[i]] = 1;
		}
		else if (hashmap.count(nums[i] - 1) != 0) { // one-sided bridge, left
			int left = hashmap[nums[i] - 1];
			int l = nums[i] - 1 - left + 1;
			hashmap[l] = left + 1;
			hashmap[nums[i]] = left + 1;
		}
		else if (hashmap.count(nums[i] + 1) != 0) {
			int right = hashmap[nums[i] + 1];
			int r = nums[i] + 1 + right - 1;
			hashmap[r] = right + 1;
			hashmap[nums[i]] = right + 1;
		}
	}
	int ans = 0;
	for (auto & kv : hashmap) {
		ans = (ans > kv.second) ? ans : kv.second;
	}
	return ans;
}

int p128::longestConsecutive_concise(vector<int>& nums) { // much simpler with iterators
	unordered_map <int, int> hmap;
	for (int num : nums) {
		if (hmap.count(num)) continue;
		auto it_l = hmap.find(num - 1);
		auto it_r = hmap.find(num + 1);
		int l = it_l != hmap.end() ? it_l->second : 0;
		int r = it_r != hmap.end() ? it_r->second : 0; // right iterator find 
		if (l > 0 && r > 0) {
			hmap[num] = hmap[num - l] = l + r + 1;
			hmap[num] = hmap[num + r] = l + r + 1;
		}
		else if (l > 0)
			hmap[num] = hmap[num - l] = l + 1;
		else if (r > 0)
			hmap[num] = hmap[num + r] = r + 1;
		else
			hmap[num] = 1;		
	}
	int ans = 0;
	for (const auto & kv : hmap) {
		ans = max(ans, kv.second);
	}
	return ans;
}

// maximum visit time = 2
int p128::longestConsecutive(vector<int>& nums) { // a hashset method
	int n = nums.size();
	unordered_set<int> hset(nums.begin(), nums.end()); // put into hash set
	int ans = 0;
	for (auto num : nums) {
		if (hset.count(num - 1) == 0) { // not containing n - 1
			int l = 0;
			while(hset.count(num++)) l++;
			ans = max(ans, l);
		}
	}
	return ans;
}

void p128::test() {
	vector<int> input = vector<int>{ 100, 4, 200, 1, 3, 2, 2 };
	cout << longestConsecutive_my(input) << endl;

}