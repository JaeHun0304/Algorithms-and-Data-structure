#include <algorithm>
#include <iostream>
#include <vector>
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

	vector<int> coll;

	for(int i=1; i<=9; ++i)
		coll.push_back(i);

	AddValue add10(10);	//functor type that adds value 10
	AddValue add20(20); //functor type that adds value 20

	for_each(coll.begin(), coll.end(), add10);

	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;

	for_each(coll.begin(), coll.end(), add20);

	for(const auto& elem: coll)
		cout << elem << " ";
	cout << endl;
}