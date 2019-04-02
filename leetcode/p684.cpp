#include"Solutions.h"
class p684::Solution_DFS {
	// O(n^2) method: pretty slow
	// Union-find method
	// https://www.youtube.com/watch?v=4hJ721ce010

public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		unordered_map<int, vector<int>> graph;
		for (const auto & edge : edges) {
			int u = edge[0];
			int v = edge[1];
			unordered_set<int> visited;
			// before adding, check if there's connection already
			if (hasPath(u, v, graph, visited)) {
				return edge;// need to delete this edge
			}
			//un-directional
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		return {}; // no need to delete any
	}

private:
	bool hasPath(int curr,
		int goal, const unordered_map<int, vector<int>> & graph, 
		unordered_set<int> & visited) {
		if (curr == goal) return true;
		visited.insert(curr);
		if (!graph.count(curr) || !graph.count(goal)) 
			return false; // no beginning/ending node
		for (int next : graph.at(curr)) {
			if (visited.count(next)) return false;
			// recursively calls...
			if (hasPath(next, goal, graph, visited)) return true;
		}
		return false;
	}
};

class UnionFindSet {
public:
	UnionFindSet(int n) {
		ranks_ = vector<int>(n + 1, 0); // n elements
		parents_ = vector<int>(n + 1, 0);
		for (int i = 0; i < parents_.size(); i++) {
			parents_[i] = i;  // initially, each one has it's own parents
		}
	}
	// Merge sets that contains u and v
	// return True if merged, falsse if u and v are in one set already
	bool Union(int u, int v) {
		int pu = Find(u); // get the root of node u and v
		int pv = Find(v);
		if (pu == pv) return false;
		// parents_ is actually store the root the that child node
		// merge low rank tree into high rank tree
		if (ranks_[pv] > ranks_[pu])
			parents_[pu] = pv;
		else if (ranks_[pu] > ranks_[pv])
			parents_[pv] = pu;
		else {
			parents_[pv] = pu;
			ranks_[pv] += 1; // previous case no additional length increase
		}
		return true;
	}
	// Get the root of u
	int Find(int u) {
		// compress the path during traverasal
		if (u != parents_[u]) // not the true root!
			parents_[u] = Find(parents_[u]); // store the root
		return parents_[u];
	}
	/*
	int find(int node, vector<int> & parents){
	while(parents[node]!= node){
	parents[node] = parents[parents[node]];
	node = parents[node];
	}
	return node;
	}
	*/
private:
	vector<int> parents_;
	vector<int> ranks_;
};
class Solution_uf {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		UnionFindSet s(edges.size());

	}
};