#include "P6.h"
#include <iostream>
#include <string>
namespace p6 {


P6::P6()
{
	
}


P6::~P6()
{
}


	int get_index(int n, int numRows) {
		int res = n % (2 * numRows - 2);
		if (res < numRows) { // vertial
			return res;
		}
		else { // zag
			res -= (numRows - 1);
			return numRows - res - 1;
		}

	}
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		int len = s.length();
		int unit_len = 2 * numRows - 2;
		//int unit = len / unit_len + (len / unit_len == 0) ? 0 : 1;
		string rev;
		// use array data structure
		// maybe can try linkedlist later or so on

		vector<vector<int> > vect(numRows, vector<int>()); //default values set to be -1
		for (int i = 0; i < len; i++) {
			vect[get_index(i, numRows)].push_back(i);
		}
		for (int i = 0; i < numRows; i++) {
			vector<int>::iterator it = vect[i].begin();
			while (it != vect[i].end()) {
				rev += s[*it];
				it++;
			}
		}
		return rev;
	}



	int get_bloc(int n, int numRows) {
		return n / (2 * n - 2);
	}


}
