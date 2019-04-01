#include"Solutions.h"

// the way to set up DFS
class p886::Solution {
public:
	bool dfs(int node, int c) {
		if (color.count(node) != 0) // has such element already
			return color[node] == c;
		// insert it and color the other ones
		color.insert({ node, c });
		for (int neigh : graph[node]) {
			if (!dfs(neigh, c ^ 1)) { // invert the color here! -- XOR logic here
				return false;
			}
		}
		return true;
	}
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		// 1st dim: N, 2nd dim: edges (how many)
		graph = vector<vector<int>>(N + 1);
		// data structure for a graph
		// connected...
		for (auto const & edge : dislikes) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		// node map to different colors: 0, 1
		//unordered_map<int, int> color;
		// the above will overwrite the global variable
		for (int node = 1; node <= N; node++) {
			if (color.count(node) == 0 && !dfs(node, 0))
				// if color has this node already, no need to do DFS anymore!
				return false;
		}
		return true;
	}

private:
	vector<vector<int>> graph;
	unordered_map<int, int> color;
};