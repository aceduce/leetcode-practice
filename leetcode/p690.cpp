#include"Solutions.h"

/*
// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};
*/
// Actually, No need to use set (seen)
// no duplicates (loop)
class p690::Solution {
	//friend class Employee;

public:
	void dfs(Employee * e, unordered_map<int, Employee*> & cor, int & sum, unordered_set<int> & seen) {
		if (e->subordinates.size() == 0) { // reach the deepest level
			if (seen.count(e->id) == 0) {
				sum += e->importance;
				seen.insert(e->id);
			}
			return;
		}

		// easily forget to add this employee
		for (auto const & em : e->subordinates) {
			dfs(cor[em], cor, sum, seen);
		}
		sum += e->importance;
	}
	// graph, direct subordinates
	int getImportance(vector<Employee*> employees, int id) {
		//unordered_map<int, vector<int>> map; // manager and managee
		unordered_set<int> added;
		unordered_map<int, Employee *> correlate; // id to employee subject mapping
		int imp = 0;
		for (auto const & e : employees) {
			correlate[e->id] = e;
			//map[e->id] = e->subordinates;
		}
		// like an DFS visit
		dfs(correlate[id], correlate, imp, added);
		return imp;
	}
/*

public: // simplify version
		int dfs(int eid) {
		Employee employee = emap.get(eid);
		int ans = employee.importance;
		for (Integer subid : employee.subordinates)
			ans += dfs(subid);
		return ans;
	}

*/

};
