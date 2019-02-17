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

template<class T>
void Print(vector<T> v) {
	cout << " [ ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << " ] " << endl;
}

template<class T>
void Print2D(vector <vector<T>> v) {
	cout << " [ " << endl;;
	for (int i = 0; i < v.size(); i++) {
		cout << "[ ";
		for(int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << " ]";
	}
	cout << endl<<" ] " << endl;
}
