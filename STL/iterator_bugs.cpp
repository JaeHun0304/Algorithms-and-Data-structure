#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> coll1;
	vector<int> coll2;

	//RUNTIME ERROR
	//-beginning is behind the end of the range
	vector<int>::iterator pos = coll1.begin();
	reverse(++pos, coll1.end());

	for(int i=1; i<=9; ++i)
		coll1.push_back(i);

	//RUNTIME_ERROR
	// overwriting nonexisting elements
	copy(coll1.cbegin(), coll1.cend(), coll2.begin());

	//RUNTIME ERROR
	//collections mistaken cbegin() and cend() refer to different collections
	copy(coll1.cbegin(), coll2.cend(), coll1.end());
}