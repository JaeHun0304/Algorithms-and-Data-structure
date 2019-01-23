// Simple recursive way to implement factorial computation program

#include <iostream>

int factorial(int n);

int main(void){

	std::cout << factorial(5);
	return 0;

}

int factorial(int n){

	if(n==0){
		return 1;
	}

	return n * factorial(n-1);
}