
#include <iostream>
#include <array>

int main(){

	char c; 
	std::array<char, 100> c_array;

	std::cout << "Size of c is " << sizeof(c) << " and Size of c_array is " << sizeof(c_array) << "\n";
	std::cout << "Length of c_array is " << c_array.size() << "\n";
	std::cout << "Hence, length and size of the array are same" << '\n';
	return 0;

}