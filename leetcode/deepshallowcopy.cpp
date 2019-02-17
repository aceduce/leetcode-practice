// if member class has pointer, do not use shallow copy
// use delete constructors (to make deep copy)
// so that pass by values will not free up the memories
#include<string>
#include<iostream>
using namespace std;

// string is value copy
void t() { // test string assingment is value copy, not pointer copy!
	string a = "abc";
	string b = a;
	b = "def";
	cout << "String a: " << a << endl;
	cout << "String b: " << b << endl;
}