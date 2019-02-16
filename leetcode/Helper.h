#pragma once
#include<vector>
#include<iostream>

using namespace std;

// print the vectors

void printVec(vector<int> &v) {
	cout << " [ ";
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << ' ';
	}
	cout << " ] " << endl;
}
