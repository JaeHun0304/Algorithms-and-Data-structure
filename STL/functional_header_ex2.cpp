#include <iostream>
#include <set>
#include <functional>
using namespace std;

int main(){

	set<int, greater<int>> coll;

	coll.insert({1, 2, 3, 4, 5});

	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;
}