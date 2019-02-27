#include"Solutions.h"
/*
The insight here: once negative, the proceedings ones cannot be starting point!!!
ii)if(current_amount_of_fuel < 0)//i.e the fuel isnt enough for the journey then none of the preceeding stations can be starting points. 
This is because the current_fuel_amount was initially positive and on account of some stations after the previously chosen start point, 
the current_fuel_amount became negative. 
These stations can anyways not be starting points. Thus we set current_amount_of_fuel = 0 and the next index(i.e i+1) as the start index.
*/
int p134::canCompleteCircuit_vect(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	if (n == 0) return -1;
	int sumgas = 0, sumcost = 0;
	for (auto const & g : gas) {
		sumgas += g;
	}
	for (auto const & c : cost) {
		sumcost += c;
	}
	if (sumgas < sumcost) return -1;
	int ans = 0;
	int remain = 0, check = 0; // check is to figure out the starting point
	for (int i = 0; i < n; i++) {
		remain += gas[i] - cost[i];
		check += gas[i] - cost[i];
		if (check < 0) {
			// i = i + 1;  // move forward
			ans = i + 1;
			check = 0; // reset to zero RESET
		}
	}
	if (remain < 0) return -1; // no valid answer --> as accumulated gas is enough to travel
	// as long as net sum > 0, there must be one solution!
	return ans;
}


// a solution based on deque concept
// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

int p134::canCompleteCircuit(vector<int> & gas, vector<int> & cost) {
	deque<pair<int, int>> dq; // first is index, second is value
	int ans = 0;
	int size = gas.size();
	if (size == 1) return (gas[0] >= cost[0]) ? 0 : -1;
	// this way, has to have at least two elements
	int st = 0, end = 1; // end is a moving pointer to the end index in the deque
	dq.push_back(make_pair(st, gas[st] - cost[st])); // add a new cost
	long long net = gas[st] - cost[st];
	while (end!= st || net < 0) { // not looping already
		// reverse means a successful configuration is made!
		//int net = gas[end] - cost[end] + dq.back().second;
		while (net < 0 && !dq.empty()) { // pop the front till positive
			net -= dq.front().second;
			dq.pop_front();
			st = (st + 1) % size; // move forward the start!
			// has to have it!
			if (st == 0) return -1; // starting point begin to loop, fail [key]
		}
		if (!dq.empty())
			net = gas[end] - cost[end] + dq.back().second; // when dq is emtpy
		else
			net = gas[end] - cost[end];
		pair<int, int> val{ end, net }; // accumulated
		dq.push_back(val);
		end = (end + 1) % size;
	}
	return st;
}

void p134::test() {
	vector<int> gas{ 5 };// { 3, 1, 1 };//{ 1,2,3,4,5 };
	vector<int> cost{ 4 };// { 1, 2, 2 };// { 3, 4, 5, 1, 2 };
	cout << canCompleteCircuit(gas, cost) << endl;
}