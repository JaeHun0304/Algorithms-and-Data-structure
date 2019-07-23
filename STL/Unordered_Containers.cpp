

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


int main(){

	/* implemented with array of buckets
	   Hash function determines location of the bucket
	   fast and effective hash function (search very fast by hash table ~ O(1))
	*/

	// unordered set
	unordered_set<string> myset = {"red", "green", "blue"};
	unordered_set<string>::const_iterator itr = myset.find("green"); // O(1)
	if(itr != myset.end())	//important to check whether iterator points end()
		cout << *itr << endl;

	vector<string> vec = {"purple", "pink"};
	myset.insert(vec.begin(), vec.end());	// elements in the vector are inserted

	cout << "load factor = " << myset.load_factor() << endl; // ratio with total # of elements and buckets
	string x = "red";
	cout << x << " is in bucket #" << myset.bucket(x) << endl; // which bucket the x stored
	cout << "Total bucket #" << myset.bucket_count() << endl; // print total number of buckets

	// unordered multiset: allow duplicated elements
	// unordered map: unordered set of pairs
	// unordered multimap: unordered map that allows duplicated keys

	// watch out for hash collision (many items in same bucket) => performance degrade
	// could take O(n) in worst case

	/* compare the continaers
		1. Fastest search/insert for unordered continaers: O(1)
		2. Associative container takes O(log(n))
		3. vector, deque takes O(n)
		4. list takes O(1) to insert, O(n) for searching
		Unordered set/multiset: element value cannot be changed
		Unordered map/multimap: element key cannot be changed => corrupt data structure!
	*/

	unordered_map<char, string> day = {{'S', "Sunday"}, {'M', "Monday"}};

	cout << day['S'] << endl;
	cout << day.at('S') << endl;

	vector<int> vec2 = {1, 2, 3};
	vec2[5] = 5; //Error! out of index range

	day['W'] = "Wednesday"; // will insert {{'W', "Wednesday"}}
	day.insert(make_pair('F', "Friday")); //same effect as above line

	day.insert(make_pair('M', "Monday")); // Fail since it's already in the map
	day['M'] = "MONDAY";	// Possible, value will be modified

	auto itr2 = day.find('S');	//	Print should be done in this way!
	if (itr2 != day.end())		// cout << day['S'] this cause error! compiler will see it
		cout << itr2 -> second << endl;	// as attempt to write day['S']

	// Notes that multimap and unordered_multimap for hash table, they don't have [] operator
	// No unique key

	/* continaer adaptor
		interface to mmey special needs
		implemented with fundamental continaer classes

		1. stack: LIFO, push(), pop(), top()
		2. queue: FIFO, push(), pop(), front(), back()
		3. prioirty queue: first item always has the greatest priority
				push(), pop(), top()
	
		Categorizing continaers

		1. array based: vector, deque
		2. node based: list + associatvie + unordered continaers

		Array based containers invalidates pointers:
			- Native pointers, iterators, references
	*/


	vector<int> vec3 = {1, 2, 3, 4};
	int* p = &vec3[2];
	vec3.insert(vec3.begin(), 0);
	cout << *p << endl;	// print 2 or random number? program crash?, undefined behavior! 
						// You dont't have to worry about this scenario in node based containers!

	return 0;
}