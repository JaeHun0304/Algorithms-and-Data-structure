#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main(){

	deque<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19};

	cout << "Initialzied: ";
	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;

	// change all elements into negative numbers
	transform(coll.cbegin(), coll.cend(), //first source
				coll.begin(), //destination
				negate<int>()); // operation

	cout << "After negate: ";
	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;

	transform(coll.cbegin(), coll.cend(), //first source
				coll.cbegin(), // second source
				coll.begin(), // destination
				multiplies<int>()); // operation

	cout << "After multiplies: ";
	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;

}