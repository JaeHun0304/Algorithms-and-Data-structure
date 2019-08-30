#include <forward_list>
#include <iostream>
using namespace std;

int main(){

	forward_list<long> coll = {2, 3, 5, 7, 11, 13, 17};

	coll.resize(9);
	coll.resize(10, 99);

	for(auto elem: coll){
		cout << elem << " ";
	}
	cout << endl;
}