#include"Solutions.h"
#include "p310.h"
// Method 1: peeling the leaves! ==> BFS
// Method 2: DFS/BFS
vector<int> p310::findMinHeightTrees_my_peel(int n, vector<pair<int, int>>& edges) {
	// use hashmap, a 2-D vector can do the same...
	unordered_map<int, vector<int>> map; // node, and its neighbors
	if (n == 1) return { 0 };
	vector<int> indegree(n, 0);
	for (auto const & e : edges) {
		// no duplicates since it's undirected!
		map[e.first].push_back(e.second);
		map[e.second].push_back(e.first);
		indegree[e.first]++;
		indegree[e.second]++;
	}
	queue<int> q;
	int m = n;
	while (n > 2) { // remove the leaves
		for (int i = 0; i < m; i++) {
			if (indegree[i] == 1) {
				q.push(i);
				indegree[i] = -1; // not to push into the queue again
			}
		}
		while (!q.empty()) {
			int tmp = q.front(); q.pop();// effectively remove the node!
			n--;
			for (auto const & node : map[tmp]) {
				indegree[node]--;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		if (indegree[i] >= 0) ans.push_back(i);
	}
	return ans;
}

// Below code is very neatly put!!
vector<int> p310::findMinHeightTrees_simpler_peel(int n, vector<pair<int, int> >& edges) {
	if (n == 1) return { 0 };
	vector<int> res;
	vector<unordered_set<int>> adj(n);
	queue<int> q;
	for (auto edge : edges) {
		adj[edge.first].insert(edge.second);
		adj[edge.second].insert(edge.first);
	}
	for (int i = 0; i < n; ++i) {
		if (adj[i].size() == 1) q.push(i);
	}
	while (n > 2) {
		int size = q.size();
		n -= size;
		for (int i = 0; i < size; ++i) {
			int t = q.front(); q.pop();
			for (auto a : adj[t]) {
				adj[a].erase(t);
				if (adj[a].size() == 1) q.push(a);
			}
		}
	}
	while (!q.empty()) {
		res.push_back(q.front()); q.pop();
	}
	return res;
}

void p310::test() {

}