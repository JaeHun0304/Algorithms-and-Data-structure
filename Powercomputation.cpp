// recursive way to impelement power computation

#include <iostream>

int powercompute(int x, int n);

int main(void){

	std::cout << powercompute(10, 5);
	return 0;

}

int powercompute(int x, int n){

	if (n == 0){
		return 1;
	}

	else if (n % 2 == 0){
		return powercompute(x, n/2) * powercompute(x, n/2);
	}

	else if(n % 2 != 0){
		return powercompute(x, n-1) * x;
	}

	else if(n < 0){
		return powercompute(x, -n);
	}

}