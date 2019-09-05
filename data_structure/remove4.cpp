#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	list<int> coll;

	for(int i=1; i<=6; ++i){
		coll.push_front(i);
		coll.push_back(i);
	}

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl; 

	// poor performance by using algorithm
	coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());
	// good performance by using member func in <list>
	coll.remove(4);

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl;
}