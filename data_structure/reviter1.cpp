#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include "print.hpp"
using namespace std;

int main(){

	vector<int> coll;
	vector<int> coll2;

	for(int i=1; i <= 9; ++i){
		coll.push_back(i);
	}

	copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout," "));
	cout << endl;
	copy(coll.crbegin(), coll.crend(), back_inserter(coll2));
	PRINT_ELEMENTS(coll2, "all elements: ");
}