#include <iostream>
#include <vector>

void PrintVec(std::vector<int>& vec){

	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}