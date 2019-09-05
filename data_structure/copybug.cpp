#include <algorithm>
#include <list>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

int main(){

	list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> coll2;

	//Resize desination for preparing copy
	coll2.resize(coll1.size());

	//Copy all elements of coll1 to coll2
	copy(coll1.cbegin(), coll1.cend(), coll2.begin());

	//Create deque with initial size coll1.size()
	deque<int> coll3(coll1.size());

	//Copy coll1 to coll3
	copy(coll1.cbegin(), coll1.cend(), coll3.begin());

	for(auto elem: coll2){
		cout << elem << " ";
	}
	cout << endl;

	for(auto elem: coll3){
		cout << elem << " ";
	}
	cout << endl;

}