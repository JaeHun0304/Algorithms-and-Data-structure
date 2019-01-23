// recursive way to find palindrome in given strings


#include <iostream>
#include <string>


std::string pailndrome(std::string arr);

int main(void){

	std::string str1 = "xyzxyzyxzyx";
	std::string str2 = "abcdefg";

	std::cout << pailndrome(str1) << " ";
	std::cout << pailndrome(str2);
	return 0;
}


std::string pailndrome(std::string arr){

	if(arr.empty() == true || arr.size() == 1)
		return "true";

	else if(arr.front() == arr.back()){
		arr.erase(0,1);
		arr.pop_back();
		return pailndrome(arr);
	}

	else
		return "false";
}