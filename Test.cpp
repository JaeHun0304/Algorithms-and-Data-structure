
#include <iostream>
#include <array>




int main(void){

	std::array<int,3> array = {1, 2, 3};

	switch(array.size())
{
	case 4:
		std::cout << "Four" << "\n";
	case 3:
		std::cout << "Four" << "\n";

	case 2:
		std::cout << "Four" << "\n";

	case 1:
		std::cout << "Four" << "\n";
}

	return 0;
}