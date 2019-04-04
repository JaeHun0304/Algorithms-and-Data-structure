// implement binary search on the sorted fixed-array list.
// The binary search also can be used on dynamic array by using std::vector instead of the std::array

#include <algorithm>
#include <array>
#include <iostream>

// Function BinarySearch declaration
int BinarySearch(std::array<int, 10> Array, int target); //asdfsdaf


int main(){

	std::array<int, 10> s1 = {10, 7, 3, 2, 5, 9, 11, 15, 25, 4};
	std::sort(s1.begin(), s1.end());
	
	for(auto a: s1){
		std::cout << a << " ";
	}

	std::cout << "\n" << "15 is located at index:" << BinarySearch(s1, 15);

	return 0;

}

// Function BinarySearch Definition
int BinarySearch(std::array<int, 10> Array, int target){

	int min = 0;
	int max = 9;
	int pos = (int)((0+9)/2);

	while(target != Array[pos]){

		if(min > max){
			pos = -1;
			break;
		}

		if(Array[pos] < target){
			min = pos + 1;
			pos = (int)((min+max)/2);}
		else if(Array[pos] > target){
			max = pos - 1;
			pos = (int)((min+max)/2);}
	}

	return pos;
}