#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

int main(){

	set<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//remove all elements with value 3
	int num = coll.erase(3);
	cout << "Number of removed elements: " << num << endl;

	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;
}