#include <set>
#include <iostream>

int main(){
	typedef std::set<int> IntSet;
	IntSet coll;

	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(7);
	coll.insert(9); // or, coll.insert({3, 1, 5, 7, 9})

	std::set<int>::const_iterator pos;
	for(pos = coll.begin(); pos != coll.end(); ++pos){
		std::cout << *pos << " ";
	}
	std::cout << std::endl;
}