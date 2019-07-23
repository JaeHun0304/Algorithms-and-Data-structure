
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

class X { // X is a class but behaves like function
	public:
	void operator() (string str){
		cout << "Calling functor X with parameter " << str << endl;
	}
};

/*
	Advantages of functor
		1. Smart function: beyond operator (), it can rember state (as class member data)
		2. It can have its own type
*/

// Parameterized Function

class Y{
	public:
	Y(int i) {}	// constructor takes int parameter
	void operator() (string str){
		cout << "Calling functor Y with parameter " << str << endl;
	}
};

class AddValue{
	int val;
public:
	AddValue(int j) : val(j) {}	// initialize val wth "j"
	void operator() (int i){
		cout << i + val << endl;
	}
};

class NeedCopy{
public:
	int operator() (int x){
		if ((x>20) || (x<5))
			return x;
		else
			return 0;
	}
};

void add2(int i);
template<int val> void addVal (int i);
void addVal2 (int i, int val);
double  Pow(double x, double y);

int main(){

	// Function Objects (functors)

	X ex1;
	ex1("Hi");	// Calling functor X with parameter Hi

	Y(8) ("Hi");	// Function parameterized with 8
	
	vector<int> vec = {2, 3, 4, 5};
	for_each(vec.begin(), vec.end(), add2); // {4, 5, 6, 7}
	for_each(vec.begin(), vec.end(), addVal<2>);	//parametrized Val with template {4, 5, 6, 7}

	int x = 2;
	// for_each(vec.begin(), vec.end(), addVal<x>) // Error!, since template resolve at compile time
	for_each(vec.begin(), vec.end(), AddValue(x)); // {4, 5, 6, 7}
	for_each(vec.begin(), vec.end(), bind(addVal2, placeholders::_1, 2)); // use bind function to set second parameter
	// Built-in Functors

	/*
		less_greater greater_equal less_equal not_equal_to
		logical_and logical_not logical_or
		multiplies minus plus divide modulus negate
	*/

	int y = multiplies<int>() (3, 4); // y = 3 * 4
	if (not_equal_to<int>() (y, 10)) // if (x != 10)
		cout << y << endl;

	// Parameter Binding

	set<int> myset = {2, 3, 4, 5};
	vector<int> vec2;

	int z = multiplies<int>() (3, 4);

	transform(myset.begin(), myset.end(), 
			   back_inserter(vec2),
			   bind(multiplies<int>(), placeholders::_1, 10)); //functor
		// Bind function: placeholders::_1 means first parameter of multiplies will be substituted from element of myset
		// and second parameter is 10 => vec2: {20, 30, 40, 50}
	for(auto itr: vec2)
		cout << itr << " ";
	cout << endl;


	set<int> myset2 = {3, 1, 25, 7, 12};
	deque<int> d;
	auto f = function<double (double, double)>(Pow); // Template class function convert Pow into functor "f" (C++11)
	transform(myset2.begin(), myset2.end(),	 // source
			  back_inserter(d),				 // destination
			  bind(f, placeholders::_1, 2)); // functor
			// d = {1, 9, 49, 144, 625}

	for(auto itr: d)
		cout << itr << " ";
	cout << endl;

	set<int> myset3 = {3, 1, 25, 7, 12};
	// when(if) (x > 20) || (x < 5), copy from myset to d2
	deque<int> d2;

	transform(myset3.begin(), myset3.end(),		//source
			  back_inserter(d2),				//destination
			  [](int x){ if((x>20) || (x<5)) return x; else return 0; });		// bind again x < 5
			// This bind can be expressed as lamda function like
			// [](int x){return (x>20)||(x<5);}
			// d2 = {1, 3, 25}

	for(auto itr: d2)
		cout << itr << " ";
	cout << endl;

	// STL set actually can take second parameter as functor that can used for sorting standard
	set<int, less<int>> myset4 = {3, 1, 25, 7, 12}; // ascending order sorting, {1, 3, 7, 12, 25}
	set<int, greater<int>> myset5 = {3, 1, 25, 7, 12};	// descending order sorting, {25. 12. 7, 3, 1}
	// Second parameter of set must be a functor!

	for(auto itr: myset4)
		cout << itr << " ";
	cout << endl;

	for(auto itr: myset5)
		cout << itr << " ";
	cout << endl;

	/* Predicate is
		1. function returns a boolean
		2. Does not modify data
	*/
	set<int> myset6 = {1, 2, 3, 4, 5};
	deque<int> d3;

	transform(myset6.begin(), myset6.end(), //source
			  back_inserter(d3),  //destination
			  NeedCopy());	//predicate will decide whether put element in the "d2"
	// Mainly used for comparison and condition check

	for(auto itr: d3)
		cout << itr << " ";
	cout << endl;

	return 0;	
}

void add2(int i){	// code is not extendible!
	cout << i + 2 << endl;
}

template<int val>	//More extendible by making it as a template, resolve at compile time.
void addVal (int i){
	cout << val + i << endl;
}

/* Best pratice is using functor with private value and member function */

void addVal2 (int i, int val){
	cout << i + val << endl;
}

// Let's convert this regular function to a functor
double  Pow(double x, double y){
	return pow(x, y);
}