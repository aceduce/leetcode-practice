#include"Solutions.h"
// use the stringsteam
vector<int> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<int> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(atoi(item.c_str()));
	}
	return elems;
}
int p165::compareVersion(string version1, string version2) {
	vector<int> v1 = split(version1, '.');
	vector<int> v2 = split(version2, '.');
	int size = max(v1.size(), v2.size());
	for (int i = 0; i < size; i++) {
		int num_v1 = (i < v1.size()) ? v1[i] : 0;
		int num_v2 = (i < v2.size()) ? v2[i] : 0;
		if (num_v1 < num_v2) return -1;
		if (num_v1 > num_v2) return 1;
	}
	return 0;
}

void p165::test() {
	
}