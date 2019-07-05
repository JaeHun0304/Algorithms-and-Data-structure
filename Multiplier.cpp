

#include <iostream>

int main(){

	int n;
	int multiply[9];

	std::cout << "1부터 9사이의 정수를 입력하세요! :";

	while(1){
		std::cin >> n;
		if(n < 0 || n > 9){
			std::cout <<"\n" << "1~9 사이의 정수를 입력하세요! :";
		}
		else
			break;
	}

	std::cout << "\n";

	for(int i = 0; i <9; i++){
		multiply[i] = n * (i+1);
		std::cout << n << " * " << (i+1) << " " << multiply[i] << "\n";
	}

	return 0;
}