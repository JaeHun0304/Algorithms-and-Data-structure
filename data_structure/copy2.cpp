#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>
using namespace std;

int main(){

	list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	//back_inserter is appending iterator, back_inserter()
	vector<int> coll2;
	copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));

	//Inserter inserts at front (front_inserter)
	deque<int> coll3;
	copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));

	set<int> coll4;
	copy(coll1.cbegin(), coll1.cend(), inserter(coll4, coll4.end()));

	for(auto elem: coll2){
		cout << elem << " ";
	}
	cout << endl;

	for(auto elem: coll3){
		cout << elem << " ";
	}
	cout << endl;

	for(auto elem: coll4){
		cout << elem << " ";
	}
	cout << endl;
}