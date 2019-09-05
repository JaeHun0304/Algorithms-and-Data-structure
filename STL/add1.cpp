#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class AddValue{
private:
	int theValue;
public:
	AddValue(int v) : theValue(v){
	}

	void operator() (int& elem) const{
		elem += theValue;
	}
};

int main(){

	list<int> coll;

	for(int i=1; i<=9; ++i){
		coll.push_back(i);
	}

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl;

	for_each(coll.begin(), coll.end(), AddValue(10));

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl;

	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));

	for(const auto& elem: coll){
		cout << elem << " ";
	}
	cout << endl;
}