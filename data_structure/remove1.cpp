#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
using namespace std;

int main(){

	list<int> coll;

	for(int i=1; i<=6; i++){
		coll.push_front(i);
		coll.push_back(i);
	}

	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
	cout << endl;

	// remove func returns logical end position iterator
	list<int>::iterator end = remove(coll.begin(), coll.end(), 3);
	copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "Number of removed elements: " << distance(end, coll.end()) << endl;

	// It will permanently remove elements
	coll.erase(end, coll.end());

	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
	cout<< endl;

}