#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	vector<int> coll = {3, 7, 2, 5, 4, 3, 2};

	auto pos = find_if(coll.begin(), coll.end(), [] (int i){ return i == 10 || i == 7;});

	if(pos == coll.end()) cout << "Not found 10 or 7" << endl;

	if(*pos == 10){
		auto pos10 = pos;
		auto pos7 = find(++pos, coll.end(), 7);
		if(pos7 == coll.end()){
			cout << "Element 7 is not found!" << endl;
		}
		else{
		cout << "Elemnt 10 and 7 are found!" << endl;
		}
	}

	if(*pos == 7){
		auto pos7 = pos;
		auto pos10 = find(++pos, coll.end(), 10);
		
		if(pos10 == coll.end()){
			cout << "Element 10 is not found! but 7 is found!" << endl;
			cout << "Element 7 is in index " << pos7 - coll.begin() << endl;
		}
		else{
		cout << "Element 10 and 7 are found!" << endl;
		}
	}
}