#include"Solutions.h"

// Clone from Basket Wang
// clone the nodes
// clone the relationships

// C++ 11 

NodeP133* p133::cloneGraph(NodeP133* node) {
	if (node == NULL) return NULL;
	queue<NodeP133*> q; // use queue and map to reduce duplicates...
	unordered_map<NodeP133 *, NodeP133*> map;
	// use BFS traverse
	q.push(node);
	while (!q.empty()) {
		for (int i = q.size(); i > 0; i--) {
			NodeP133 * tmp = q.front();
			q.pop();
			map[tmp] = new NodeP133;
			map[tmp]->val = tmp->val; // just copy values
			for (const auto & n : tmp->neighbors) {
				if (map.count(n) == 0) {
					map[n] = NULL; // to avoid duplicates
					q.push(n); // very easy to forget, but very critial
				}
			}
		}
	}
	// build the connections (neighbors)
	for (const auto & kv : map) {
		for (const auto & n : (kv.first->neighbors)) {
			kv.second->neighbors.push_back(map[n]);
		}
	}
	return map[node];
}