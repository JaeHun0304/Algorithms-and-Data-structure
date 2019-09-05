#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <int theValue>
void add (int& elem){
	elem += theValue;
}

int main(){

	vector<int> coll = {1, 2, 3, 4, 5};

	for_each(coll.begin(), coll.end(), add<10>);

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl;
}