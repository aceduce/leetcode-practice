#include"Solutions.h"
//#include"Helper.h"
vector<int> p210::findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<int> indegree(numCourses, 0);
	vector<int> ans;
	//this is essentially the graph
	unordered_map<int, vector<int>> pre; // record prerequisites: prerequisite-> course
	queue<int> q;
	// set up the graph and collect the indegree
	for (const auto & prereq : prerequisites) {
		pre[prereq.second].push_back(prereq.first);
		indegree[prereq.first]++;
	}
	for (int i = 0; i < indegree.size(); i++) {
		if (indegree[i] == 0) {
			q.push(i);
			//ans.push_back(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front(); // studied the course q
		ans.push_back(cur);
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
			return {};
	}
	//return {};
	return ans;
}

void p210::test() {
	vector<pair<int, int>> inp{ make_pair(1,0), make_pair(1,0), {2,0},{3,1}, {3,2} };
	vector<int> ans = findOrder(4, inp);
	cout << "[ ";
	for (auto const & a : ans) {
		cout << a << ' ';
	}
	cout << " ]" << endl;
	system("pause");
}