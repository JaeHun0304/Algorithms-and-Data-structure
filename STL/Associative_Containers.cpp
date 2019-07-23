
/* Associative Continaers STL examples
	Always sorted, default criteria is <
*/


#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){

	// set/multiset's element value cannot be modified
	// set does not have any duplicates
	set<int> myset;
	myset.insert(3);	// {3}
	myset.insert(1);	// {1, 3}
	myset.insert(7);	// {1, 3, 7} automatically sorted when inserted O(log(n))

	set<int>::iterator it;
	it = myset.find(7);	// O(log(n)) cf. sequence containers don't even have find() member function

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3);	// since we already have 3, insertion failed
	if(ret.second == false)
		it = ret.first;		// iterator 'it' now points to element 3

	myset.insert(it, 9);	// {1, 3, 7, 9} inserted position cannot be determined by you
							// only fixed in sorted order 'it' reduce insertion time to O(1)
	myset.erase(it);	// {1, 7, 9}
	myset.erase(7);		// myset: {1, 9}, sequence continaers does not have erase function

	// multiset allowed duplicated items in the set
	multiset<int> myset2;
	// *it = 10;	// read-only, direct modification of the iterator pointer could corrupt Error!
				// the data structure!!
	
	/*
		1. O(log(n)) search time
		2. Traversing is slow  (compared to vector & deque)
		3. No random access, no [] operator
	*/

	/* map and multimap
		same with set/multiset but each element pair of key-value
		map -> no dulplicated key
		multimap -> can hvae duplicated key
	*/

	map<char, int> mymap;
	mymap.insert (pair<char, int>('a', 100)); // needs to be inserted as pair
	mymap.insert (make_pair('z', 200));	// typing saved by inferred parameters function 'make_pair'

	map<char, int>::iterator it2 = mymap.begin();
	mymap.insert(it2, pair<char,int>('b', 300));	//'it2' can be a hint for insert position O(1)

	it2 = mymap.find('z'); // find item based on the key(char) O(log(n))

	for (map<char,int>::iterator it=mymap.begin(); it != mymap.end(); it++ )
		cout << (*it).first << " => " << (*it).second << endl;

	cout << "print same thing with auto functionality" << endl;

	for (auto it: mymap)
		cout << (it).first << " => " << (it).second << endl;

	//multimap is a map that allows duplicated keys
	multimap<char,int> mymap2;

	// we can think *it as pair<const char, int> so key(char) must not be modified
	// (*it).first = 'd'; // Error! Attempt to modify the key!

}