#include <deque>
#include <iostream>

using namespace std;

int main(){

	deque<float> coll;

	for(int i = 1; i <= 6; ++i){
		coll.push_front(i*1.1);
	}

	for(int i = 0; i < coll.size(); ++i){
		cout << coll[i] << " ";
	}
	cout << endl;
}