#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "print.hpp"

int square(int value){
	return value*value;
}

int main(){

	std::set<int> coll1;
	std::vector<int> coll2;

	for(int i=1; i<=9; ++i){
		coll1.insert(i);
	}

	PRINT_ELEMENTS(coll1, "initialized: ");

	//Transform each element from coll1 to coll2
	std::transform(coll1.cbegin(), coll1.cend(), //source range
					std::back_inserter(coll2), 	//destination
					square);	//operation
	PRINT_ELEMENTS(coll2, "squared: ");
	
}