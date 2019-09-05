#include <list>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

// Predicate that finds prime number (Unary predicate)
bool isPrime(int number){
	number = abs(number);

	if(number == 0 || number == 1) return false;

	//find divisor that divides without a remainder
	int divisor;
	for(divisor = number/2; number%divisor != 0; --divisor){
		;
	}

	// if no divisor greater than 1 found, it is a prime number
	return divisor == 1;
}

int main(){

	list<int> coll;

	for(int i=24; i<=30; ++i){
		coll.push_back(i);
	}

	// Search for the prime number
	auto pos = find_if(coll.cbegin(), coll.cend(), isPrime);

	if(pos != coll.end()){
		cout << *pos << " is first prime number found!" << endl;
	}
	else{
		cout << "no prime number found" << endl;
	}
}