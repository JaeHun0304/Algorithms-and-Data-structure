#include <set>
#include <iostream>
using namespace std;

int main(){

	auto cmp = [] (int elem1, int elem2){return elem1 > elem2;};

	set<int, decltype(cmp)> coll(cmp);

	coll.insert({1, 2, 3, 4, 5});

	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;
}