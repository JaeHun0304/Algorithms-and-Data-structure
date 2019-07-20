/*
1. sequence containers (array and linked list)
	- vector, deque, list, forward list, array
2. Associative Containers (binary tree)
	-set, multiset,
	-map, multimap
3. Unordered Containers (hash table)
	-Unordered set/lmultiset;
	-Unordered map/multimap

Headers are as follows
<vector>, <deque>, <list>, <set>, <map>, <unordered_set>, <unordered_map>, <iterator>
<algorithm>, <numeric>, <functional>

vector: dynamic array (undefined length) to one direction.
*/

#include<vector>
#include <iostream>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	cout << vec[2];	//no range check
	cout << vec.at(2);	//throw range_error if out of range

	for(int i; i < vec.size(); i++)	//possible, but not recommended 1. it is slow 2. Not a standard way
		cout << vec[i] << " ";
	cout << endl;

	for(auto itr = vec.begin(); itr != vec.end(); itr++)	//recommended way for traversing, faster and standard for container
		cout << *itr << " ";
	cout << endl;

	for(auto it: vec)	//new way of traversing container since C++11
		cout << it << " ";
	cout << endl;

	//Vector is dynamically allocated continuous array in memory!
	int* p = &vec[0];
	p[2] = 6;

	// common member functions for all containers
	if(vec.empty()) 
		cout << "the container is empty" << endl;

	cout << vec.size() << endl;

	vector<int> vec2(vec); // Copy constructor, vec2: {4, 1, 8}

	vec.clear(); // Remove all items(elements) vec.size() = 0

	vec2.swap(vec); // vec2 becomes empty, and vec has 3 items

	// There is no penalty for abstraction of these member functions

	/* Properties of Vector
		1. fast insert/remove at the end: O(1)
		2. slow insert/remove at the beginning or in the middle: O(n)
		3. slow search: O(n)
	*/

	cout << "start dec exmaple from here" << endl;

	deque<int> deq = {4, 6, 7};
	deq.push_front(2);	// {2, 4, 6, 7}
	deq.push_back(3);	// {2, 4, 6, 7, 3}

	cout <<deq[1] << endl;

	for(auto it: deq)
		cout << it << " ";
	cout << endl;

	for(auto itr = deq.begin(); itr != deq.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	//Still, slow insert/delete in the middle and search O(n)

	cout << "start List example from here" << endl;
		//List: fast insert and remove in any part of the container

	list<int> mylist = {5, 2, 9};
	mylist.push_back(6);	//mylist: {5, 2, 9, 6}
	mylist.push_front(4);	//mylist: {4, 5, 2, 9, 6}

	for(auto it: mylist)
		cout << it << " ";
	cout << endl;

	auto itr_a= find(mylist.begin(), mylist.end(), 2); //itr_a -> 2
	mylist.insert(itr_a, 8); //mylist, {4, 5, 8, 2, 9, 6}, O(1) insert

	for(auto it: mylist)
		cout << it << " ";
	cout << endl;

	itr_a++;
	mylist.erase(itr_a);	//mylist: {4, 5, 8, 9, 6} O(1) delete

	for(auto it: mylist)
		cout << it << " ";
	cout << endl;
	// Still O(n) search!, cannot access by [] operator (no indexing)
	// However, Cache Hit possibility: Vector > Deque > List(lots of cache misses) = slow down program, more memory due to pointers

	// But, we can use killer function of insertion with list
	list<int> mylist1 = {1, 2, 3};
	list<int> mylist2 = {4, 5, 6};
	auto itr_b = mylist1.begin();
	auto itr_c = mylist1.end();
	auto itr_d = mylist2.begin();
	itr_d++;
	mylist2.splice(itr_d, mylist1, itr_b, itr_c);

	for(auto it: mylist2)
		cout << it << " ";
	cout << endl;

	cout << "Forward_list Example Here" << endl;

	forward_list<int> fl1 = {1, 100, 200, 3, 4, 500};

	fl1.remove(100);
	for(auto it: fl1)
		cout << it << " ";
	cout << endl;

	fl1.remove_if([](int n){return n>50;});	//[] stands for "capture" for the lamda experssion in C++

	fl1.remove(100);
	for(auto it: fl1)
		cout << it << " ";
	cout << endl;


	/*
		Array: size cannot be changed
			size of the array will be considered as type! ex. array<int, 3> and array<int, 4> are different.
			However, you can use member functions by defining array with array<data_type, # of elements> format.
	*/

	array<int, 3> a = {3, 4, 5};
	a.begin();
	a.end();
	a.size();

	return 0;
}
