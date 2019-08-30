#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){

	vector<int> coll = {2, 5, 4, 1, 6, 3};

	// print max and min element
	auto minpos = min_element(coll.cbegin(), coll.cend());
	cout << "min: " << *minpos << endl;
	auto maxpos = max_element(coll.cbegin(), coll.cend());
	cout << "max: " << *maxpos << endl;

	// sort all elements
	sort(coll.begin(), coll.end());

	//find the first element with value 3
	auto pos3 = find(coll.begin(), coll.end(), 3);

	//reverse the order of the found element value 3 and all following elements
	reverse(pos3, coll.end());

	for(auto elem: coll){
		cout << elem << " ";
	}
	cout << endl;

}