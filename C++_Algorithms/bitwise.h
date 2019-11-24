
#include <bitset>
#include <string>
#include <vector>


int countSetBits(int num){
	if(num == 0)
		return 0;
	int counter = 0;

	while(num != 0){
		if(num & 1 == 1)
			counter++;
		num = num >> 1;
	}

	return counter;
}

std::string complementBits(int num){
	if(num == 0)
		return "please enter number not zero";

	std::string num_str = std::bitset<32>(num).to_string();
	std::string num_str2;
	for(int i =0; i < num_str.size(); i++){
		if(num_str[i] == 0)
			num_str2.push_back(1);
		else
			num_str2.push_back(0);
	}

	return num_str2;
}