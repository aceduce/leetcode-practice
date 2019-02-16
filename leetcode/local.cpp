#include<iostream>
#include<vector>
using namespace std;

// a test for is it ok to return local vector variable
vector<int>* localreturn() {
	vector<int>* vect = new vector<int>;
	*vect = { 1,2,3 };
	vector<int> vect2{ 1,2,3,4 };
	vect = &vect2;
	return vect;
}

int* localreturn_var() {
	int x = 10;
	int * y = new int;
	*y = 0;
	return &x; // reutrn y;
}