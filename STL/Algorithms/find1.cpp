#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main(){

	list<int> coll;

	for(int i=20; i <=40; ++i){
		coll.push_back(i);
	}

	// This will return coll.end()
	auto pos3 = find(coll.begin(), coll.end(), 3);
	// It will reversed empty range -> no effect
	reverse(pos3, coll.end());

	list<int>::iterator pos25, pos35;
	pos25 = find(coll.begin(), coll.end(), 25);
	pos35 = find(coll.begin(), coll.end(), 35);

	cout << "max: " << *max_element(pos25, pos35) << endl;

	cout << "max: " << *max_element(pos25, ++pos35) << endl;
}