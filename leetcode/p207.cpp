#include"Solutions.h"
// basketwang method
// build up a graph with in
// use queue for BFS
bool p207::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> indegree(numCourses, 0);
	//this is essentially the graph
	unordered_map<int, vector<int>> pre; // record prerequisites: prerequisite-> course
	queue<int> q;
	// set up the graph and collect the indegree
	for (const auto & prereq : prerequisites) {
		pre[prereq.second].push_back(prereq.first);
		indegree[prereq.first]++;
	}
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); // studied the course q
		q.pop();
		for (auto const & c : pre[cur]) {
			indegree[c]--;
			if (indegree[c] == 0)
				q.push(c);
		}
	}

	// final test
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] != 0)
			return false;
	}
	return true;
}


class p207::Solution_top_search {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// using a vector<vector> for map
		graph = vector<vector<int>>(numCourses); // initializing the size
		for (int i = 0; i < prerequisites.size(); i++) {
			for (auto const & p : prerequisites)
				graph[p.second].push_back(p.first);
		}
		vector<int> v(numCourses);
		// states: 0- unknown; 1- visited; 2- visiting;
		// states: true -- cycle, false -- not cycle
		for (int i = 0; i < numCourses; i++) {
			if (topsearch(v, i)) return false;
		}
		return true;
	}
	bool topsearch(vector<int>& v, int i) {
		if (v[i] == 1) return false;
		if (v[i] == 2) return true;
		// label current as visiting -2
		v[i] = 2;
		for (const auto & neig : graph[i]) {
			if (topsearch(v, neig)) return true;;
		}
		v[i] = 1;
		return false;
	}
private:
	vector<vector<int>> graph;
};
void p207::test() {
	vector<pair<int, int>> inp{ make_pair(1,0), make_pair(0,1) };
	cout << canFinish(2, inp) << endl;
}