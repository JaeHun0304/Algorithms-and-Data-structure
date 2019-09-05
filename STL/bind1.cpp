#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
using namespace std;
using namespace std::placeholders;

int main(){

	set<int,greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> coll2;

	cout << "Initialzied: ";
	for(const auto& elem: coll1)
		cout << elem << " ";
	cout << endl;

	transform(coll1.cbegin(), coll1.cend(), // range
				back_inserter(coll2), // destination
				bind(multiplies<int>(), _1, 10)); //operation

	cout << "Transformed: ";
	for(const auto& elem: coll2)
		cout << elem << " ";
	cout << endl;

	replace_if(coll2.begin(), coll2.end(), //range
				bind(equal_to<int>(),_1,70), //replace criterion
				42); // new value
	cout << "Replaced: ";
	for(const auto& elem: coll2)
		cout << elem << " ";
	cout << endl;

	coll2.erase(remove_if(coll2.begin(), coll2.end(), // remove_if only returns new logical end
						  bind(logical_and<bool>(),	  // erase() actually erase values matched with the criterion
						  	bind(greater_equal<int>(),_1,50),
						  	bind(less_equal<int>(),_1,80))),
							coll2.end());
	cout << "Removed: ";
	for(const auto& elem: coll2)
		cout << elem << " ";
	cout << endl;

}