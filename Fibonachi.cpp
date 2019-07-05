
#include <iostream>
#include <limits>

int fibonachi(int n);

int main(){

	std::cout << fibonachi(1000000000) << "\n";
	std::cout << std::numeric_limits<int>::max();
	return 0;
}

int fibonachi(int n){
	if(n<0){
		std::cout << "Invalid Input!" << "\n";
	}

	if(n==0){
		return 0;
	}

	if(n==1){
		return 1;
	}

	int a1 = 0;
	int a2 = 1;
	int answer;

	for(int i = 2; i <= n; i++){
		answer = a1 + a2;
		a1 = a2;
		a2 = answer;
	}

	if(answer > std::numeric_limits<int>::max()){
		std::cout << "parameter is too large! Overflow! return -1" << "\n";
		return -1;
	}
	else{
	return answer;
	}
}