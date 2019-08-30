#include <list>
#include <iostream>
using namespace std;

int main(){

	list<char> coll;

	for(char c='a'; c <= 'z'; ++c){
		coll.push_back(c);
	}

	for(auto it: coll){
		cout << it << " ";
	}
	cout << endl;
}

