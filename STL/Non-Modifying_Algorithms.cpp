
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	/* STL Algorithm
		Non-modifying Algorithms
		count, min an max, compare, linear search, attribute
	*/

//C++ 11 Lambda Function: Short function without name

vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 28, 7};
vector<int> vec2 = {9, 60, 70, 8, 45, 87};

//1. Counting
// Count the occurence of the specific element
// Count if some condition is met

int n = count(vec.begin(), vec.end(), 69); // 2
int m = count_if(vec.begin(), vec.end(), [](int x){return x < 10;}); // 3, Lambda function is used

// 2. Min and Max
auto itr1 = max_element(vec.begin()+2, vec.end()); // 90, default comparison (simpliefied form)
// max_element will return first max value (first match)

// We can customize the comparison rules by ourselves as lambda function (generalized form)

auto itr2 = max_element(vec.begin(), vec.end(), [](int x, int y){return (x%10) < (y%10);}); // 9, only compare last digit 
auto itr3 = min_element(vec.begin(), vec.end()); // 7

// minmax_element returns pair of iterators which points first of min and last of max
auto pair_of_itr = minmax_element(vec.begin(), vec.end());

// 3. Linear Seach
// Used when data is not sorted, use binary search for the sorted array!
// returns the first match

auto itr4 = find(vec.begin(), vec.end(), 55);

auto itr5 = find_if(vec.begin(), vec.end(), [](int x){ return x > 80; });

auto itr6 = find_if_not(vec.begin(), vec.end(), [](int x){ return x > 80; });

auto itr7 = search_n(vec.begin(), vec.end(), 2, 69); // Find '69' for consecutively 2 times, can find multiple occurences

// Search subrange

vector<int> sub = {45, 87, 90};

auto itr8 = search(vec.begin(), vec.end(), sub.begin(), sub.end()); //find the pattern sub = {45, 87, 90} in vector "vec"
																	// find first subrange
auto itr9 = find_end(vec.begin(), vec.end(), sub.begin(), sub.end()); // Search last subrange 

// Search any_of
vector<int> items = {87, 69};

auto itr10 = find_first_of(vec.begin(), vec.end(), items.begin(), items.end());
		// find any one of the item element in the vector "vec" (simplified form)
auto itr11 = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(), [](int x, int y){ return x == y * 4; });
		// Search any one of item that satisfies the condition "x = y * 4" (generalized form)

// Search Adjacent
auto itr12 = adjacent_find(vec.begin(), vec.end()); // Find two adjacent items that are same {69, 69}

auto itr13 = adjacent_find(vec.begin(), vec.end(), [](int x, int y){ return x == y * 4; });
		// Find two adjacent items that satisfy x = y * 4, {}

// Comparing Ranges
if (equal(vec.begin(), vec.end(), vec2.begin())){	// check if vec and vec2 are same
	cout << "vec and vec2 are same." << endl;
}

if (is_permutation(vec.begin(), vec.end(), vec2.begin())){ // check if vec and vec2 have same elements
	cout << "vec and vec2 have same items, but in different order" << endl;
}

auto pair_of_itr2 = mismatch(vec.begin(), vec.end(), vec2.begin());
// find first difference
// Points to place of the difference
// pair_of_itr2.first is an iterator of vec
// pair_of_itr2.second is an iterator of vec2

//Lexicographical Comparison: one-by-one comparison with "less than"
lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
	// ex. {1, 2, 3, 5} < {1, 2, 4, 5}, element-wise compare.

//Check Attribute
auto check1 = is_sorted(vec.begin(), vec.end());	// check if the vector is sorted

auto itr14 = is_sorted_until(vec.begin(), vec.end());
	// itr points first place where elements no longer sorted

auto check2 = is_partitioned(vec.begin(), vec.end(), [](int x){ return x > 80;});
	//check if vector "vec" is partitioned based on the condition of x > 80

auto check3 = is_heap(vec.begin(), vec.end()); // check if vec is a heap
auto itr15 = is_heap_until(vec.begin(), vec.end()); //find first place where it is no longer a heap


// All, any, none

auto check4 = all_of(vec.begin(), vec.end(), [](int x){ return x > 80;});
// check if all of vec is bigger than 80

auto check5 = any_of(vec.begin(), vec.end(), [](int x){ return x > 80;});
// check if any of vec element is bigger than 80

auto check6 = none_of(vec.begin(), vec.end(), [](int x){ return x > 80;});
// check if none of vec element is bigger than 80


cout << *itr1 << endl;
cout << *itr2 << endl;
cout << *itr3 << endl;
cout << *itr4 << endl;
cout << *itr5 << endl;
cout << *itr6 << endl;
cout << *itr7 << endl;
cout << *itr8 << endl;
cout << *itr9 << endl;
cout << *itr10 << endl;
cout << *itr11 << endl;
cout << *itr12 << endl;
cout << *itr13 << endl;
cout << *itr14 << endl;
cout << *itr15 << endl;

cout << check1 << endl;
cout << check2 << endl;
cout << check3 << endl;
cout << check4 << endl;
cout << check5 << endl;
cout << check6 << endl;

	return 0;
}