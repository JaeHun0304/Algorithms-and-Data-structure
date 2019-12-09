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

std::bitset<32> complementBits(int num){
	
	std::bitset<32> bin_num = std::bitset<32>(num);
	std::bitset<32> bin_num2;
	for(int i =0; i < bin_num.size() ; i++){
		if(bin_num[i] == 0)
			bin_num2[i] = 1;
		else
			bin_num2[i] = 0;
	}
	
	return bin_num2;
}
