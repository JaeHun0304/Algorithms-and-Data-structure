#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){

	vector<string> coll1;

	cout << "Type string you want to sort:";
	// Read all words from standard input until EOF error
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(coll1));

	sort(coll1.begin(), coll1.end());

	cout << coll1.front();
	//Print elements w/o duplicates
	unique_copy(coll1.cbegin(), coll1.cend(), ostream_iterator<string>(cout, "\n"));

	return 0;
}