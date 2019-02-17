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

void operInIF() {
	int i = -1;
	for (int k = 0; k < 10; k++) {
		cout << " in the loop " << k << endl;
		if (i++ > 0) // shows in k = 2 loop
		// if (++i > 0) shows in k = 1 loop
			cout << "a line" << endl;
	}

	// every time evalues the if statement, i decreaments
	for (int k = 0; k < 10; k++) {
		cout << " in the loop " << k << endl;
		if (i-- > 0)
			cout << "a line" << endl;
		cout << "i = " << i << endl;
	}

	cout << i << endl;
}
